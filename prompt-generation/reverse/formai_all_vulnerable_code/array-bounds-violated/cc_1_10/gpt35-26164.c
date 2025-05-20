//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surprised
#include <stdio.h>
#include <string.h>

void alienTranslator(char* message) {
    // Alien language rules
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    char suffix[] = {'m', 'x', 'y', 'z', 'M', 'X', 'Y', 'Z'};
    char consonants[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z',
                         'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'
                        };

    int msgLength = strlen(message);
    char translatedMessage[msgLength*2];
    int pointer = 0;

    // Translate each letter
    for(int i = 0; i < msgLength; i++) {
        char letter = message[i];

        // Handle vowels
        for(int k = 0; k < sizeof(vowels); k++) {
            if(letter == vowels[k]) {
                translatedMessage[pointer++] = letter;
                translatedMessage[pointer++] = 'm';
                break;
            }
        }

        // Handle suffix
        for(int k = 0; k < sizeof(suffix); k++) {
            if(i == (msgLength - 1) && letter == suffix[k]) {
                translatedMessage[pointer++] = 'u';
                translatedMessage[pointer++] = letter;
                break;
            }
        }

        // Handle consonants
        for(int k = 0; k < sizeof(consonants); k++) {
            if(letter == consonants[k]) {
                translatedMessage[pointer++] = letter;
                translatedMessage[pointer++] = 'o';
                translatedMessage[pointer++] = letter;
                break;
            }
        }
    }

    translatedMessage[pointer] = '\0';

    printf("Translated message:\n%s\n", translatedMessage);
}

int main() {
    char message[] = "Hello World!";
    printf("Original message:\n%s\n", message);

    alienTranslator(message);

    return 0;
}