//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a character is allowed in a URL
bool is_allowed_char(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.' || c == '~';
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    // Allocate memory for the sanitized URL
    char* sanitized_url = malloc(strlen(url) + 1);
    if (sanitized_url == NULL) {
        return NULL;
    }

    // Copy the first character of the URL to the sanitized URL
    sanitized_url[0] = url[0];

    // Loop through the remaining characters in the URL
    for (int i = 1; i < strlen(url); i++) {
        // If the character is allowed, copy it to the sanitized URL
        if (is_allowed_char(url[i])) {
            sanitized_url[i] = url[i];
        }
        // Otherwise, replace the character with an underscore
        else {
            sanitized_url[i] = '_';
        }
    }

    // Terminate the sanitized URL with a null character
    sanitized_url[strlen(url)] = '\0';

    // Return the sanitized URL
    return sanitized_url;
}

// Main function
int main() {
    // Get the URL from the user
    char* url = malloc(1024);
    if (url == NULL) {
        return 1;
    }
    printf("Enter the URL you want to sanitize: ");
    scanf("%s", url);

    // Sanitize the URL
    char* sanitized_url = sanitize_url(url);
    if (sanitized_url == NULL) {
        return 1;
    }

    // Print the sanitized URL
    printf("The sanitized URL is: %s\n", sanitized_url);

    // Free the memory allocated for the URL and the sanitized URL
    free(url);
    free(sanitized_url);

    return 0;
}