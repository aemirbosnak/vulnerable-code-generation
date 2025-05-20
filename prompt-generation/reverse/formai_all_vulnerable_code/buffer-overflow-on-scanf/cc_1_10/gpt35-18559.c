//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 200 // Maximum input length allowed
#define MAX_INVALID_CHARS 10 // Maximum number of invalid characters to be replaced

char invalid_chars[MAX_INVALID_CHARS]; // Array to store invalid characters
char replacement_char; // Character to replace invalid characters with

// Function to check if a character is invalid
int isInvalidChar(char ch) {
    for(int i=0; i<MAX_INVALID_CHARS; i++) {
        if(ch == invalid_chars[i]) {
            return 1;
        }
    }

    return 0;
}

// Function to sanitize the user input string
void sanitizeInput(char *input) {
    int len = strlen(input);

    for(int i=0; i<len; i++) {
        if(isInvalidChar(input[i])) {
            input[i] = replacement_char;
        }
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];

    // Initialize invalid characters array with some default values
    invalid_chars[0] = '<';
    invalid_chars[1] = '>';
    invalid_chars[2] = '(';

    printf("Enter the string to be sanitized: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    printf("Enter the character to replace invalid characters with: ");
    scanf("%c", &replacement_char);

    sanitizeInput(input);

    printf("Sanitized String: %s", input);

    return 0;
}