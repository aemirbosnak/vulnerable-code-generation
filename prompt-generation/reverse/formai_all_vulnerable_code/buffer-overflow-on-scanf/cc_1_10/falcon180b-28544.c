//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 5

struct MorseCode {
    char code[MAX_CODE_LENGTH];
    int length;
};

struct MorseCode morseCodeTable[] = {
    {"A", 1},
    {"B", 2},
    {"C", 3},
    {"D", 4},
    {"E", 5},
    {"F", 6},
    {"G", 7},
    {"H", 8},
    {"I", 2},
    {"J", 3},
    {"K", 5},
    {"L", 4},
    {"M", 2},
    {"N", 6},
    {"O", 3},
    {"P", 5},
    {"Q", 8},
    {"R", 3},
    {"S", 3},
    {"T", 1},
    {"U", 4},
    {"V", 6},
    {"W", 9},
    {"X", 5},
    {"Y", 6},
    {"Z", 7},
    {"0", 5},
    {"1", 2},
    {"2", 3},
    {"3", 4},
    {"4", 5},
    {"5", 6},
    {"6", 7},
    {"7", 8},
    {"8", 9},
    {"9", 10}
};

int isValidInput(char *input) {
    int i = 0;
    while (input[i]!= '\0') {
        if (!isalpha(input[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

void convertToMorseCode(char *input, char *output) {
    int i = 0;
    while (input[i]!= '\0') {
        if (isalpha(input[i])) {
            int index = 0;
            for (index = 0; index < sizeof(morseCodeTable) / sizeof(morseCodeTable[0]); index++) {
                if (toupper(input[i]) == toupper(morseCodeTable[index].code[0])) {
                    strcat(output, morseCodeTable[index].code);
                    break;
                }
            }
            if (index == sizeof(morseCodeTable) / sizeof(morseCodeTable[0])) {
                strcat(output, " ");
            }
        }
        i++;
    }
}

int main() {
    char input[100], output[1000];
    printf("Enter text to convert to Morse code: ");
    scanf("%s", input);
    if (!isValidInput(input)) {
        printf("Invalid input. Please enter only alphabets.\n");
        return 1;
    }
    convertToMorseCode(input, output);
    printf("Morse code: %s\n", output);
    return 0;
}