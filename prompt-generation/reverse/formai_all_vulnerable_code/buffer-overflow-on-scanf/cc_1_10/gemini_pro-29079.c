//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

typedef struct {
    char character;
    char *morse_code;
} MorseCode;

MorseCode morse_codes[] = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {' ', " "}
};

int main() {
    char text[MAX_LENGTH];
    printf("Enter a text to convert to Morse code: ");
    scanf("%s", text);

    char morse_code[MAX_LENGTH];
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        for (j = 0; j < sizeof(morse_codes) / sizeof(morse_codes[0]); j++) {
            if (text[i] == morse_codes[j].character) {
                strcat(morse_code, morse_codes[j].morse_code);
                strcat(morse_code, " ");
                break;
            }
        }
    }

    printf("Morse code: %s\n", morse_code);

    return 0;
}