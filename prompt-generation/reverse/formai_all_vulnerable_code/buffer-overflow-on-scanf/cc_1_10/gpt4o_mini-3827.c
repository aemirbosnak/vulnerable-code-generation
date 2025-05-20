//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is safe in a URL
int is_safe_char(char c) {
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == ':' || c == '/' || c == '?' || c == '&' || c == '=');
}

// Function to sanitize the URL
void sanitize_url(const char *input, char *output) {
    int i, j = 0;
    for (i = 0; input[i] != '\0' && j < MAX_URL_LENGTH - 1; i++) {
        if (is_safe_char(input[i])) {
            output[j++] = input[i];
        } else {
            // Replace unsafe characters with underscore
            output[j++] = '_';
        }
    }
    output[j] = '\0'; // Null-terminate the sanitized URL
}

int main() {
    char input_url[MAX_URL_LENGTH];
    char sanitized_url[MAX_URL_LENGTH];

    // Ask for user input
    printf("Enter a URL to sanitize: ");
    fgets(input_url, sizeof(input_url), stdin);

    // Remove trailing newline character from fgets
    size_t len = strlen(input_url);
    if (len > 0 && input_url[len - 1] == '\n') {
        input_url[len - 1] = '\0';
    }

    // Sanitize the URL
    sanitize_url(input_url, sanitized_url);

    // Output the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Prompt the user for another URL
    char more;
    printf("Would you like to sanitize another URL? (y/n): ");
    scanf(" %c", &more);

    while (more == 'y' || more == 'Y') {
        printf("Enter a URL to sanitize: ");
        getchar(); // Clear the newline character from the input buffer
        fgets(input_url, sizeof(input_url), stdin);
        
        len = strlen(input_url);
        if (len > 0 && input_url[len - 1] == '\n') {
            input_url[len - 1] = '\0';
        }

        sanitize_url(input_url, sanitized_url);
        printf("Sanitized URL: %s\n", sanitized_url);

        printf("Would you like to sanitize another URL? (y/n): ");
        scanf(" %c", &more);
    }

    printf("Thank you for using the URL sanitizer!\n");
    return 0;
}