//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Array of Morse code characters
const char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    int index = c - 'A';
    if (index >= 0 && index < 26) {
        return (char *)morse_code[index];
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5 + 1); // Assuming each character will be converted to a maximum of 5 Morse code characters
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        char *code = char_to_morse(str[i]);
        if (code != NULL) {
            strcpy(morse_code + j, code);
            j += strlen(code);
            morse_code[j++] = ' ';
        }
    }
    morse_code[j] = '\0';
    return morse_code;
}

// Main function
int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code);

    // Free the allocated memory
    free(morse_code);

    return 0;
}