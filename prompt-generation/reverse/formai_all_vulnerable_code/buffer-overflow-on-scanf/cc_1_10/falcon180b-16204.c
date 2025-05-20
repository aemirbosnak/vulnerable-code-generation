//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 26
#define MAX_WORD_LENGTH 100
#define MORSE_CODE_DELIMITER " "
#define MORSE_CODE_INVALID "Invalid input!"

typedef struct {
    char code[MAX_CODE_LENGTH];
    int length;
} MorseCode;

MorseCode morseCodeTable[26] = {
    {"A", 1}, {"B", 2}, {"C", 3}, {"D", 4}, {"E", 5}, {"F", 6}, {"G", 7},
    {"H", 8}, {"I", 9}, {"J", 10}, {"K", 11}, {"L", 12}, {"M", 13}, {"N", 14},
    {"O", 15}, {"P", 16}, {"Q", 17}, {"R", 18}, {"S", 19}, {"T", 20}, {"U", 21},
    {"V", 22}, {"W", 23}, {"X", 24}, {"Y", 25}, {"Z", 26}
};

int getMorseCodeLength(char *word) {
    int length = 0;
    while (*word) {
        if (isalpha(*word)) {
            length += strlen(morseCodeTable[tolower(*word) - 'a'].code);
            word++;
        } else {
            word++;
        }
    }
    return length;
}

void convertToMorseCode(char *word, MorseCode *morseCode) {
    int length = 0;
    while (*word) {
        if (isalpha(*word)) {
            strncat(morseCode->code, morseCodeTable[tolower(*word) - 'a'].code, strlen(morseCodeTable[tolower(*word) - 'a'].code));
            length += morseCodeTable[tolower(*word) - 'a'].length;
            word++;
        } else {
            word++;
        }
    }
    morseCode->length = length;
}

int main() {
    char input[MAX_WORD_LENGTH];
    printf("Enter a word to convert to Morse code: ");
    scanf("%s", input);
    MorseCode morseCode;
    convertToMorseCode(input, &morseCode);
    printf("Morse code: %s\n", morseCode.code);
    printf("Length: %d\n", morseCode.length);
    return 0;
}