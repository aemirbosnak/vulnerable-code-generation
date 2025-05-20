//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines the maximum length of the input string
#define MAX_INPUT_LENGTH 100

// Defines the Morse code table
static const char *MORSE_CODE_TABLE[] = {
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
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----.", // 9
};

// Converts a character to Morse code
static char *convert_char_to_morse(char character) {
    // Converts the character to uppercase
    character = toupper(character);

    // Gets the Morse code for the character
    char *morse_code = MORSE_CODE_TABLE[character - 'A'];

    // Returns the Morse code
    return morse_code;
}

// Converts a string to Morse code
static char *convert_string_to_morse(char *string) {
    // Initializes the Morse code string
    char *morse_code = malloc(strlen(string) * 5 + 1);

    // Converts each character in the string to Morse code
    for (int i = 0; i < strlen(string); i++) {
        char *character_morse_code = convert_char_to_morse(string[i]);
        strcat(morse_code, character_morse_code);
        strcat(morse_code, " ");
    }

    // Removes the trailing space
    morse_code[strlen(morse_code) - 1] = '\0';

    // Returns the Morse code
    return morse_code;
}

// Main function
int main() {
    // Gets the input string from the user
    char input_string[MAX_INPUT_LENGTH];
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", input_string);

    // Converts the string to Morse code
    char *morse_code = convert_string_to_morse(input_string);

    // Prints the Morse code
    printf("Morse code: %s\n", morse_code);

    // Frees the allocated memory
    free(morse_code);

    return 0;
}