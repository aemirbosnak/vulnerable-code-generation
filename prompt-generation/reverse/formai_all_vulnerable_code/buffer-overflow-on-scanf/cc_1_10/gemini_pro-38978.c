//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
static const char *MORSE_CODE[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----", "|",
};

// Text to Morse code conversion function
char *text_to_morse(const char *text) {
    size_t text_len = strlen(text);
    size_t morse_len = 0;

    // Calculate the length of the Morse code representation
    for (size_t i = 0; i < text_len; i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            morse_len += strlen(MORSE_CODE[c - 'a']);
        } else if (c >= 'A' && c <= 'Z') {
            morse_len += strlen(MORSE_CODE[c - 'A']);
        } else if (c == ' ') {
            morse_len += 1;
        }
    }

    // Allocate memory for the Morse code representation
    char *morse = malloc(morse_len + 1);
    if (morse == NULL) {
        return NULL;
    }

    // Convert the text to Morse code
    size_t morse_index = 0;
    for (size_t i = 0; i < text_len; i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            strcpy(morse + morse_index, MORSE_CODE[c - 'a']);
            morse_index += strlen(MORSE_CODE[c - 'a']);
        } else if (c >= 'A' && c <= 'Z') {
            strcpy(morse + morse_index, MORSE_CODE[c - 'A']);
            morse_index += strlen(MORSE_CODE[c - 'A']);
        } else if (c == ' ') {
            morse[morse_index++] = ' ';
        }
    }

    // Terminate the Morse code string
    morse[morse_index] = '\0';

    return morse;
}

// Main function
int main() {
    // Get the text input from the user
    char text[100];
    printf("Enter a text to convert to Morse code: ");
    scanf("%s", text);

    // Convert the text to Morse code
    char *morse = text_to_morse(text);
    if (morse == NULL) {
        printf("Error: Out of memory.\n");
        return 1;
    }

    // Print the Morse code representation
    printf("Morse code: %s\n", morse);

    // Free the allocated memory
    free(morse);

    return 0;
}