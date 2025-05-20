//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is valid in a URL
int is_valid_char(char c) {
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' ||
            c == '!' || c == '*' || c == '\'' || c == '(' || c == ')' ||
            c == ';' || c == ':' || c == '@' || c == '&' || c == '=' ||
            c == '+' || c == '$' || c == ',' || c == '/' || c == '?' ||
            c == '#' || c == '[' || c == ']' || c == '%');
}

// Function to sanitize the URL
void sanitize_url(const char *input_url, char *sanitized_url) {
    int j = 0;
    for (int i = 0; input_url[i] != '\0'; i++) {
        char c = input_url[i];
        if (is_valid_char(c)) {
            sanitized_url[j++] = c;
        } else {
            // If character is invalid, encode it as a percent-encoded character
            j += sprintf(sanitized_url + j, "%%%02X", (unsigned char)c);
        }
    }
    sanitized_url[j] = '\0'; // Ensure the string is null-terminated
}

// Function to print menu
void display_menu() {
    printf("URL Sanitizer\n");
    printf("--------------\n");
    printf("1. Sanitize a URL\n");
    printf("2. Exit\n");
    printf("Select an option: ");
}

// Main function
int main() {
    char input_url[MAX_URL_LENGTH];
    char sanitized_url[MAX_URL_LENGTH];
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Remove newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter a URL to sanitize: ");
                fgets(input_url, sizeof(input_url), stdin);
                input_url[strcspn(input_url, "\n")] = 0; // Remove trailing newline

                sanitize_url(input_url, sanitized_url);

                printf("Sanitized URL: %s\n", sanitized_url);
                break;
            case 2:
                printf("Exiting the URL Sanitizer. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

        printf("\n"); // Extra line for better readability
    }
    return 0;
}