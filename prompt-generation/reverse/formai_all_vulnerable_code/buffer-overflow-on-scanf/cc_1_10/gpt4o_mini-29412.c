//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

// Function to sanitize the input string
void sanitize_input(char *input) {
    char *src = input, *dest = input;

    while (*src) {
        if (isalnum((unsigned char)*src) || isspace((unsigned char)*src)) {
            *dest++ = *src; // Keep alphanumeric characters and spaces
        }
        src++;
    }
    *dest = '\0'; // Null-terminate the sanitized string
}

// Function to read user input
void read_input() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter a string (max %d characters): ", MAX_INPUT_LENGTH - 1);
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove the newline character from the input, if present
        input[strcspn(input, "\n")] = '\0';

        // Call the sanitizer
        sanitize_input(input);

        printf("Sanitized input: '%s'\n", input);
    } else {
        fprintf(stderr, "Error reading input\n");
    }
}

// Function to validate if input is empty
int is_empty(const char *input) {
    return (input == NULL || *input == '\0');
}

// Function to convert a string to lowercase
void to_lowercase(char *input) {
    for (char *p = input; *p; p++) {
        *p = tolower((unsigned char)*p);
    }
}

// Function to count the length of a string
size_t string_length(const char *input) {
    const char *p = input;
    while (*p) p++;
    return p - input;
}

// Main function
int main() {
    char continue_program;

    do {
        read_input();
        
        // Example usage of additional string utility functions
        char additional_input[MAX_INPUT_LENGTH];
        printf("Enter another string to check for empty and convert to lowercase: ");
        if (fgets(additional_input, sizeof(additional_input), stdin) != NULL) {
            additional_input[strcspn(additional_input, "\n")] = '\0'; // Remove newline
            if (is_empty(additional_input)) {
                printf("The input is empty.\n");
            } else {
                char lowercased[MAX_INPUT_LENGTH];
                strncpy(lowercased, additional_input, MAX_INPUT_LENGTH);
                to_lowercase(lowercased);
                printf("Lowercased input: '%s'\n", lowercased);
                printf("Length of the original input: %zu characters\n", string_length(additional_input));
            }
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &continue_program);
        while (getchar() != '\n'); // Clear stdin buffer
    } while (continue_program == 'y' || continue_program == 'Y');

    printf("Goodbye!\n");
    return 0;
}