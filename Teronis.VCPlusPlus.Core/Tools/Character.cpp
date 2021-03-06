#include "Character.h"
#include <iostream>
#include "Integer.h"

using namespace std;

namespace Teronis {
	namespace VCPlusPlus {
		namespace Tools {
			int CharacterTools::toNumber(char c) {
				return (int)c - (char)'0';
			}

			int CharacterTools::searchCharacter(char* ptr, int length, char c, int startIndex, int endIndex) {
				IntegerTools::initializeEndIndex(length, startIndex, &endIndex);

				for (int i = startIndex; i < length; i++)
					if (*(ptr + i) == c)
						return i;

				return -1;
			}

			int CharacterTools::transformCharsToNumber(char* ptr, int length, int startIndex, int backIndex) {
				IntegerTools::initializeEndIndex(length, startIndex, &backIndex);

				bool isNegative = false;
				int j = 0, mSize = sizeof(ptr), indexRange;

				if (*(ptr + startIndex) == '-') {
					startIndex++;
					isNegative = true;
				}

				// Now startIndex don't change anymore.
				indexRange = backIndex - startIndex + 1;

				// Now we need the 0-based back index.
				for (backIndex; backIndex >= startIndex; backIndex--) {
					int index = indexRange - (backIndex - startIndex + 1);
					int n = toNumber(*(ptr + backIndex));
					int multiplier = (int)pow(10, index);
					n *= multiplier;
					j += n;
				}

				if (isNegative)
					j *= -1;

				return j;
			}
		};
	}
}