//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024
#define MAX_MORSE_LENGTH 4096

typedef struct {
    char letter;
    char *morse;
} MorseCode;

MorseCode morseCodes[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
    {'9', "----."}, {' ', " "}
};

char *textToMorse(char *text) {
    int i, j;
    char *morse = malloc(MAX_MORSE_LENGTH);
    memset(morse, 0, MAX_MORSE_LENGTH);

    for (i = 0; i < strlen(text); i++) {
        for (j = 0; j < sizeof(morseCodes) / sizeof(MorseCode); j++) {
            if (text[i] == morseCodes[j].letter) {
                strcat(morse, morseCodes[j].morse);
                strcat(morse, " ");
                break;
            }
        }
    }

    return morse;
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char *morse;

    printf("Enter the text to convert: ");
    scanf("%s", text);

    morse = textToMorse(text);

    printf("The Morse code is: %s\n", morse);

    free(morse);

    return 0;
}