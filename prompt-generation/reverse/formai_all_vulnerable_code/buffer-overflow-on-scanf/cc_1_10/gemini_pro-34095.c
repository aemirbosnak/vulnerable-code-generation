//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code mapping table (relaxed version for excitement)
char* morseTable[] = {
    "-. ---",   // A
    "-... ---", // B
    "-.-.",     // C
    "-..",      // D
    ".",        // E
    "..-.",     // F
    "--.",      // G
    "....",     // H
    "..",       // I
    ".---",     // J
    "-.-",      // K
    ".-..",     // L
    "--",       // M
    "-.",       // N
    "---",      // O
    ".--.",     // P
    "--.-",     // Q
    ".-.",      // R
    "...",      // S
    "-",        // T
    "..-",      // U
    "...-",     // V
    ".--",      // W
    "-..-",     // X
    "-.--",     // Y
    "--..",     // Z

    "-----",    // 0
    ".----",   // 1
    "..---",   // 2
    "...--",   // 3
    "....-",   // 4
    ".....",   // 5
    "-....",   // 6
    "--...",   // 7
    "---..",   // 8
    "----.",   // 9
};

// Converts a character to its Morse code representation
char* charToMorse(char c) {
    if (c >= 'a' && c <= 'z') {
        // Convert lowercase letters to uppercase
        c -= 32;
    }
    return morseTable[c - 'A'];
}

int main() {
    printf("Welcome to the Electro-Morse Codeatorium!\n\n");

    // Get the input text
    char input[1000];
    printf("Enter your electrifying text: ");
    scanf("%[^\n]s", input);

    // Iterate over the input text and convert each character
    int inputLength = strlen(input);
    printf("\nYour electrifying text in Morse code: ");
    for (int i = 0; i < inputLength; i++) {
        printf("%s ", charToMorse(input[i]));
    }

    printf("\n\nMay your Morse code adventures continue to crackle with excitement!\n");

    return 0;
}