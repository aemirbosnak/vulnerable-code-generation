//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LEN 256

// Function to sanitize input by removing unwanted characters
void sanitize_input(char *input) {
    int i, j = 0;
    char sanitized[MAX_INPUT_LEN];

    for (i = 0; input[i] != '\0' && i < MAX_INPUT_LEN; i++) {
        // Allow only alphanumeric characters and basic punctuation
        if (isalnum(input[i]) || input[i] == ' ' || input[i] == '.' || 
            input[i] == ',' || input[i] == '!' || input[i] == '?') {
            sanitized[j++] = input[i];
        }
    }
    sanitized[j] = '\0'; // null-terminate the sanitized string

    // Copy the sanitized string back to the input
    strcpy(input, sanitized);
}

// Function to read user input and sanitize it
void read_and_sanitize_input() {
    char input[MAX_INPUT_LEN];

    printf("Please enter a sentence (max %d characters): ", MAX_INPUT_LEN - 1);
    
    // Using fgets to safely read input
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character, if found
        input[strcspn(input, "\n")] = '\0'; 

        printf("Original input: \"%s\"\n", input);
        sanitize_input(input);
        printf("Sanitized input: \"%s\"\n", input);
    } else {
        fprintf(stderr, "Error reading input.\n");
    }
}

// Function to escape special characters for output
void escape_special_chars(const char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        switch (input[i]) {
            case ' ':
                printf("\\ ");
                break;
            case '!':
                printf("\\!");
                break;
            case '?':
                printf("\\?");
                break;
            case '.':
                printf("\\.");
                break;
            case ',':
                printf("\\,");
                break;
            default:
                putchar(input[i]);
        }
    }
}

int main() {
    printf("Welcome to the C User Input Sanitizer Program!\n");
    
    // Loop to allow multiple inputs
    while (1) {
        read_and_sanitize_input();

        char more_input;
        printf("Would you like to enter another sentence? (y/n): ");
        scanf(" %c", &more_input);
        getchar(); // to consume the newline character left by scanf
        if (more_input != 'y' && more_input != 'Y') {
            break;
        }
    }

    // Example of escaping special characters in output
    // Getting a sample to demonstrate escaping
    char sample[] = "You entered a well-formed sentence! Really? Yes, indeed.";
    printf("\nDemonstrating escaping special characters:\nOriginal: \"%s\"\nEscaped: ", sample);
    escape_special_chars(sample);
    printf("\n");

    printf("Thank you for using the C User Input Sanitizer Program!\n");
    
    return 0;
}