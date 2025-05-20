//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: light-weight
/*
 * Unique C Text to Morse code conversion example program
 *
 * This program converts a given text into Morse code using a light-weight approach.
 * It uses a hash map to store the Morse code for each letter and then converts the
 * text into Morse code by iterating over each letter and looking up the corresponding
 * Morse code in the hash map.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hash map to store the Morse code for each letter
#define LETTERS 26
char *morse_codes[LETTERS] = {
    ".-",   // A
    "-...", // B
    "-.-.",  // C
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
    "--.."  // Z
};

// Function to convert text to Morse code
char *text_to_morse(char *text) {
    char *morse = malloc(strlen(text) * 4 + 1); // Allocate memory for the Morse code
    char *ptr = morse;

    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A'; // Convert to lowercase
            strcpy(ptr, morse_codes[c]);
            ptr += strlen(morse_codes[c]);
        }
    }

    *ptr = '\0'; // Null terminate the string
    return morse;
}

int main() {
    char text[] = "HELLO WORLD";
    char *morse = text_to_morse(text);
    printf("%s\n", morse);
    free(morse);
    return 0;
}