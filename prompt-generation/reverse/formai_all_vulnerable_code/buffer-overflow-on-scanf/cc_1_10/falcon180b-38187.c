//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_CODE_LENGTH 6

struct MorseCode {
    char letter;
    char code[MAX_CODE_LENGTH];
};

int main() {
    struct MorseCode morseCode[] = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
        {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."},
        {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'0', "-----"}
    };

    int numOfWords;

    printf("Enter the number of words to convert to Morse code: ");
    scanf("%d", &numOfWords);

    char words[numOfWords][MAX_WORD_LENGTH];

    for (int i = 0; i < numOfWords; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i]);
    }

    printf("\nMorse code translation:\n");

    for (int i = 0; i < numOfWords; i++) {
        int wordLength = strlen(words[i]);

        for (int j = 0; j < wordLength; j++) {
            char letter = toupper(words[i][j]);

            for (int k = 0; k < MAX_CODE_LENGTH; k++) {
                struct MorseCode *morseCodeLetter = &morseCode[k];

                if (morseCodeLetter->letter == letter) {
                    printf("%s ", morseCodeLetter->code);
                    break;
                }
            }
        }

        printf("\n");
    }

    return 0;
}