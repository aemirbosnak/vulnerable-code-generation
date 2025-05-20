//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: beginner-friendly
/*
 * Text to Morse code conversion example program
 *
 * This program converts a text input into Morse code and prints it to the console.
 *
 * Usage:
 *  - Enter the text you want to convert to Morse code as the first argument
 *  - The program will convert the text and print the Morse code to the console
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code alphabet
const char* MORSE_CODE[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--.."
};

// Define the Morse code for the space character
const char* MORSE_CODE_SPACE = " ";

// Define the Morse code for the newline character
const char* MORSE_CODE_NEWLINE = "\n";

int main(int argc, char* argv[]) {
    // Check if the user has provided the text to convert
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text to convert>\n", argv[0]);
        return 1;
    }

    // Get the text to convert from the command line argument
    char* text = argv[1];

    // Initialize the converted text
    char* converted_text = malloc(strlen(text) * 3 + 1);
    if (converted_text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize the current index of the converted text
    int index = 0;

    // Convert the text to Morse code
    for (int i = 0; text[i] != '\0'; i++) {
        // Get the current character of the text
        char c = text[i];

        // Check if the character is a letter or a number
        if (c >= 'A' && c <= 'Z') {
            // Get the index of the character in the Morse code alphabet
            int morse_index = c - 'A';

            // Copy the Morse code for the character to the converted text
            strcpy(&converted_text[index], MORSE_CODE[morse_index]);
            index += strlen(MORSE_CODE[morse_index]);
        } else if (c >= 'a' && c <= 'z') {
            // Get the index of the character in the Morse code alphabet
            int morse_index = c - 'a';

            // Copy the Morse code for the character to the converted text
            strcpy(&converted_text[index], MORSE_CODE[morse_index]);
            index += strlen(MORSE_CODE[morse_index]);
        } else if (c >= '0' && c <= '9') {
            // Get the index of the character in the Morse code alphabet
            int morse_index = c - '0';

            // Copy the Morse code for the character to the converted text
            strcpy(&converted_text[index], MORSE_CODE[morse_index]);
            index += strlen(MORSE_CODE[morse_index]);
        } else if (c == ' ') {
            // Copy the Morse code for the space character to the converted text
            strcpy(&converted_text[index], MORSE_CODE_SPACE);
            index += strlen(MORSE_CODE_SPACE);
        } else if (c == '\n') {
            // Copy the Morse code for the newline character to the converted text
            strcpy(&converted_text[index], MORSE_CODE_NEWLINE);
            index += strlen(MORSE_CODE_NEWLINE);
        }
    }

    // Print the converted text to the console
    printf("%s\n", converted_text);

    // Free the memory allocated for the converted text
    free(converted_text);

    return 0;
}