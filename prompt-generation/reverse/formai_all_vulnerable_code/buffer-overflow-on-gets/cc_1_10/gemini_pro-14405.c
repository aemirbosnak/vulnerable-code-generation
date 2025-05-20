//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: immersive
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Morse code table
const char *morseCodeTable[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--..", // Z
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----.", // 9
    "-----", // 0
};

// Convert a character to Morse code
char *charToMorse(char character) {
    character = toupper(character);
    if (character >= 'A' && character <= 'Z') {
        return (char *)morseCodeTable[character - 'A'];
    } else if (character >= '0' && character <= '9') {
        return (char *)morseCodeTable[character - '0' + 26];
    } else {
        return "";
    }
}

// Convert a string to Morse code
char *stringToMorse(char *string) {
    int len = strlen(string);
    char *morseCode = malloc(len * 5 + 1); // Allocate enough space for the Morse code, assuming each character takes up to 5 characters
    int index = 0;
    for (int i = 0; i < len; i++) {
        char *morse = charToMorse(string[i]);
        strcat(morseCode, morse);
        strcat(morseCode, " ");
        index += strlen(morse) + 1;
    }
    morseCode[index - 1] = '\0'; // Remove the trailing space
    return morseCode;
}

// Print Morse code
void printMorseCode(char *morseCode) {
    printf("Morse code: %s\n", morseCode);
}

int main() {
    // Get the input string
    char string[101];
    printf("Enter a string to convert to Morse code: ");
    gets(string);

    // Convert the string to Morse code
    char *morseCode = stringToMorse(string);

    // Print the Morse code
    printMorseCode(morseCode);

    // Free the allocated memory
    free(morseCode);

    return 0;
}