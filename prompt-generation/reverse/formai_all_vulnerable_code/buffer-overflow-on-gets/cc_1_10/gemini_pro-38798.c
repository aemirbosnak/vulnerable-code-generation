//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", " "
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    // Check if the character is a letter
    if (isalpha(c)) {
        // Convert the character to uppercase
        c = toupper(c);
    }

    // Get the index of the character in the Morse code table
    int index = c - 'A';

    // Return the Morse code for the character
    return (char *)morse_code[index];
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    // Allocate memory for the Morse code string
    char *morse_code = (char *)malloc(strlen(str) * 5);

    // Convert each character in the string to Morse code
    for (int i = 0; i < strlen(str); i++) {
        strcat(morse_code, char_to_morse(str[i]));
    }

    // Return the Morse code string
    return morse_code;
}

// Print Morse code
void print_morse(char *morse_code) {
    // Print each character in the Morse code string
    for (int i = 0; i < strlen(morse_code); i++) {
        printf("%c", morse_code[i]);
    }

    // Print a newline
    printf("\n");
}

// Main function
int main() {
    // Get the input string from the user
    char *str = (char *)malloc(100);
    printf("Enter a string: ");
    gets(str);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);

    // Print the Morse code
    printf("Morse code: ");
    print_morse(morse_code);

    // Free the memory allocated for the Morse code string
    free(morse_code);

    // Return 0
    return 0;
}