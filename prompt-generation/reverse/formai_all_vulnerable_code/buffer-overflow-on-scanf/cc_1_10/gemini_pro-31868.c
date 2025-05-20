//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: relaxed
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is valid in a URL
bool is_valid_url_char(char c) {
    // Valid URL characters are letters, numbers, underscores, hyphens, and periods
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_' || c == '-' || c == '.';
}

// Function to sanitize a URL
char *sanitize_url(char *url) {
    // Allocate memory for the sanitized URL
    char *sanitized_url = malloc(MAX_URL_LENGTH);

    // Initialize the index of the sanitized URL
    int sanitized_index = 0;

    // Iterate over the characters in the URL
    for (int i = 0; i < strlen(url); i++) {
        // Check if the current character is valid in a URL
        if (is_valid_url_char(url[i])) {
            // If the character is valid, add it to the sanitized URL
            sanitized_url[sanitized_index++] = url[i];
        }
    }

    // Null-terminate the sanitized URL
    sanitized_url[sanitized_index] = '\0';

    // Return the sanitized URL
    return sanitized_url;
}

// Main function
int main() {
    // Get the URL from the user
    char url[MAX_URL_LENGTH];
    printf("Enter the URL to be sanitized: ");
    scanf("%s", url);

    // Sanitize the URL
    char *sanitized_url = sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the memory allocated for the sanitized URL
    free(sanitized_url);

    return 0;
}