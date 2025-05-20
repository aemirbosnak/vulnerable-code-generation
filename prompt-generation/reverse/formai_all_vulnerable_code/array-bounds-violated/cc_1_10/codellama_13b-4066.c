//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: thoughtful
/*
 * C Text to Morse code conversion program
 *
 * This program takes a string of text as input and outputs the corresponding
 * Morse code representation.
 *
 * Example:
 *
 * Input: "Hello World!"
 * Output: ".... . .-.. .-.. --- / .-- --- .-. .-.. -.."
 */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Define the Morse code table
const char *morse_code_table[] = {
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

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    return morse_code_table[c - 'A'];
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    char *morse = malloc(MAX_LENGTH * sizeof(char));
    int i = 0;

    while (*str) {
        // Convert the current character to Morse code
        char *code = char_to_morse(*str);

        // Add the Morse code to the output string
        strcat(morse, code);

        // Add a space between each character
        strcat(morse, " ");

        // Advance to the next character
        str++;
    }

    return morse;
}

int main() {
    // Input the string to be converted
    char str[MAX_LENGTH];
    printf("Enter a string to convert to Morse code: ");
    fgets(str, MAX_LENGTH, stdin);

    // Convert the string to Morse code
    char *morse = string_to_morse(str);

    // Print the Morse code
    printf("Morse code: %s\n", morse);

    return 0;
}