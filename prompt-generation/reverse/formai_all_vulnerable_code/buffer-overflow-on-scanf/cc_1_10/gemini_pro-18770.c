//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", "..--..", "-....-", "-...-", "-.-.-.", "--..--", "-.--.-", ".-.-.-", "..--.-", "...-..-", "....-.", "....."
};

// Length of the Morse code table
const int morse_table_length = sizeof(morse_table) / sizeof(char *);

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    // Convert the character to uppercase
    c = toupper(c);

    // Get the index of the character in the Morse code table
    int index = c - 'A';

    // Return the corresponding Morse code
    return morse_table[index];
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    // Allocate memory for the Morse code string
    char *morse = malloc(strlen(str) * 5 + 1);

    // Convert each character in the string to Morse code
    int i;
    for (i = 0; i < strlen(str); i++) {
        strcat(morse, char_to_morse(str[i]));
    }

    // Return the Morse code string
    return morse;
}

// Function to print the Morse code representation of a string
void print_morse(char *str) {
    // Print the Morse code string
    printf("%s\n", str);
}

// Main function
int main() {
    // Get the input string from the user
    char str[101];
    printf("Enter a string: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse = string_to_morse(str);

    // Print the Morse code representation of the string
    print_morse(morse);

    // Free the allocated memory
    free(morse);

    return 0;
}