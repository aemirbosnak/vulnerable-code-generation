//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the ASCII characters to use
const char *ASCII_CHARS = "@#S%?*+;:,. "; // From densest to least dense

// Function to convert a character to an ASCII representation
char charToAscii(char c) {
    if (isspace(c)) {
        return ASCII_CHARS[sizeof(ASCII_CHARS) - 1]; // Space representation
    }
    // Scale the ASCII value to the range of 0-10
    int scaled = (int)(c) % (sizeof(ASCII_CHARS) - 1);
    return ASCII_CHARS[scaled]; // Return corresponding ASCII character 
}

// Function to convert text to ASCII art
void textToAsciiArt(const char *input) {
    printf("\nYour ASCII Art Representation:\n\n");
    while (*input) {
        char asciiChar = charToAscii(*input);
        printf("%c", asciiChar);
        input++;
    }
    printf("\n\n");
}

// Function for user input and triggering conversion
void userInputAndConvert() {
    char input[256]; // Buffer for user input
    printf("Welcome to the ASCII Art Generator!\n");
    printf("Enter the text you want to convert to ASCII art (max 255 characters):\n");
    
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = 0; // Remove the trailing newline
        textToAsciiArt(input);
    } else {
        printf("Error reading input. Please try again.\n");
    }
}

int main() {
    // Continue prompting user for conversion
    char continueInput;
    do {
        userInputAndConvert();
        printf("Would you like to convert another text? (y/n): ");
        scanf(" %c", &continueInput);
        while (getchar() != '\n'); // clear input buffer
    } while (continueInput == 'y' || continueInput == 'Y');

    printf("Thank you for using the ASCII Art Generator! Goodbye!\n");
    return 0;
}