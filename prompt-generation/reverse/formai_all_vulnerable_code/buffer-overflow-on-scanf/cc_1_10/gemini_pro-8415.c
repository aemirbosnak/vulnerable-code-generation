//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Ada Lovelace
// This code snippet is an example of a URL sanitizer in Ada Lovelace style.
// It takes a URL as input and returns a sanitized version of the URL.
// The sanitizer removes any unsafe characters from the URL.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize a URL.
// @param url The URL to sanitize.
// @return The sanitized URL.
char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    if (sanitized_url == NULL) {
        return NULL; // malloc failed
    }

    // Initialize the sanitized URL.
    strcpy(sanitized_url, "");

    // Loop through each character in the URL.
    for (int i = 0; i < strlen(url); i++) {
        char c = url[i];

        // Check if the character is safe.
        if (isalnum(c) || c == '.' || c == '/' || c == '?' || c == '&' || c == '=') {
            // The character is safe. Add it to the sanitized URL.
            strncat(sanitized_url, &c, 1);
        } else {
            // The character is not safe. Escape it.
            char escaped_c[4];
            sprintf(escaped_c, "%%%02X", c);
            strncat(sanitized_url, escaped_c, 3);
        }
    }

    // Return the sanitized URL.
    return sanitized_url;
}

// Main function.
int main() {
    // Get the URL from the user.
    char url[MAX_URL_LENGTH];
    printf("Enter the URL to sanitize: ");
    scanf("%s", url);

    // Sanitize the URL.
    char *sanitized_url = sanitize_url(url);

    // Print the sanitized URL.
    printf("The sanitized URL is: %s\n", sanitized_url);

    // Free the memory allocated for the sanitized URL.
    free(sanitized_url);

    return 0;
}