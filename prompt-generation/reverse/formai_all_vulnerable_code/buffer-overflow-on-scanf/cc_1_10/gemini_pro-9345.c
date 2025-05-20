//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "---.", "----",
    "-----"
};

// ASCII to Morse code conversion function
char *text_to_morse(char *text) {
    // Allocate memory for the Morse code string
    char *morse = malloc(strlen(text) * 5);
    if (morse == NULL) {
        return NULL;
    }

    // Convert each character in the text string to Morse code
    int i, j;
    for (i = 0, j = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            // Convert uppercase letters to lowercase
            text[i] = tolower(text[i]);
        }

        // Get the Morse code for the character
        char *morse_char = morse_table[text[i] - 'a'];

        // Append the Morse code to the Morse code string
        strcat(morse, morse_char);

        // Add a space between each character
        if (text[i + 1] != '\0') {
            strcat(morse, " ");
        }
    }

    // Return the Morse code string
    return morse;
}

// Main function
int main() {
    // Get the input text from the user
    char text[100];
    printf("Enter the text to convert to Morse code: ");
    scanf("%s", text);

    // Convert the text to Morse code
    char *morse = text_to_morse(text);

    // Print the Morse code
    printf("Morse code: %s\n", morse);

    // Free the memory allocated for the Morse code string
    free(morse);

    return 0;
}