//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: genious
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// A genius function to sanitize a URL
char *sanitize_url(const char *url) {
    // Allocate a buffer for the sanitized URL
    char *sanitized_url = (char *) malloc(strlen(url) + 1);
    if (sanitized_url == NULL) {
        return NULL;
    }

    // Copy the URL into the buffer
    strcpy(sanitized_url, url);

    // Replace all invalid characters with underscores
    for (char *c = sanitized_url; *c != '\0'; c++) {
        if (!isalnum(*c) && *c != '.' && *c != '_' && *c != '-') {
            *c = '_';
        }
    }

    // Return the sanitized URL
    return sanitized_url;
}

// A main function to test the sanitize_url function
int main() {
    // Get the URL from the user
    char *url = (char *) malloc(1024);
    if (url == NULL) {
        return 1;
    }
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize the URL
    char *sanitized_url = sanitize_url(url);
    if (sanitized_url == NULL) {
        return 1;
    }

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the memory allocated for the URL and the sanitized URL
    free(url);
    free(sanitized_url);

    return 0;
}