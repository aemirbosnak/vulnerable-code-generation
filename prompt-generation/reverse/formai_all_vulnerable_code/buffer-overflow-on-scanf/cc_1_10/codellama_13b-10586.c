//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: dynamic
/*
 * Text to Morse code conversion program
 * Uses dynamic memory allocation to handle variable-length input
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define MAX_MORSE_CODE_LENGTH 100

// Morse code characters
const char *MORSE_CODE[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--.."
};

// Function to convert text to Morse code
void text_to_morse(char *text, char **morse_code) {
    int length = strlen(text);
    *morse_code = (char *)malloc(length * MAX_MORSE_CODE_LENGTH * sizeof(char));
    int morse_length = 0;
    for (int i = 0; i < length; i++) {
        int index = text[i] - 'A';
        if (index >= 0 && index < 26) {
            strcat(*morse_code, MORSE_CODE[index]);
            morse_length += strlen(MORSE_CODE[index]);
            if (i < length - 1) {
                strcat(*morse_code, " ");
                morse_length++;
            }
        }
    }
    *morse_code = (char *)realloc(*morse_code, morse_length + 1);
    (*morse_code)[morse_length] = '\0';
}

// Main function
int main() {
    char text[MAX_INPUT_SIZE];
    char *morse_code;
    printf("Enter text to convert to Morse code: ");
    scanf("%s", text);
    text_to_morse(text, &morse_code);
    printf("Morse code: %s\n", morse_code);
    free(morse_code);
    return 0;
}