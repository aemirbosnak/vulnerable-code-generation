//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 2048

// Function to check if a character is allowed in a sanitized URL
int is_safe_char(char ch) {
    // Define the set of safe characters.
    return (isalnum(ch) || ch == '-' || ch == '_' || ch == '.' || ch == '~');
}

// Function to sanitize the URL by encoding unsafe characters.
void sanitize_url(const char *input, char *output) {
    char *pos = output; // Pointer for the output string
    while (*input) {
        if (is_safe_char(*input)) {
            *pos++ = *input; // Copy safe character directly
        } else {
            // Encode unsafe characters as %xx where xx is the ASCII value in hex
            pos += sprintf(pos, "%%%02X", (unsigned char)*input); 
        }
        input++;
    }
    *pos = '\0'; // Null-terminate the output string
}

// Function to print a menu for user interaction
void print_menu() {
    printf("Welcome to the URL Sanitizer!\n");
    printf("1. Sanitize a URL\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

// Function to handle user input and process URL
void process_choice() {
    char input_url[MAX_LEN];
    char sanitized_url[MAX_LEN];
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a URL to sanitize: ");
                scanf(" %2047[^\n]", input_url); // Read the input URL
                
                // Sanitize the URL
                sanitize_url(input_url, sanitized_url);
                
                // Display the results
                printf("Original URL: %s\n", input_url);
                printf("Sanitized URL: %s\n", sanitized_url);
                break;

            case 2:
                printf("Exiting the URL Sanitizer. Goodbye!\n");
                return;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

int main() {
    process_choice(); // Start the URL sanitizer process
    return 0;
}