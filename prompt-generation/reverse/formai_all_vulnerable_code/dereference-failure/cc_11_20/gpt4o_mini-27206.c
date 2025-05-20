//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize URLs
char* sanitize_url(const char* url) {
    size_t length = strlen(url);
    char* sanitized_url = malloc(length + 1);
    if (!sanitized_url) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    size_t j = 0;
    for (size_t i = 0; i < length; i++) {
        char c = url[i];
        // Allow alphanumeric characters, special characters used in URLs,
        // and some specific punctuation.
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || 
            c == '!' || c == '*' || c == '\'' || c == '(' || c == ')' || 
            c == ';' || c == ':' || c == '@' || c == '&' || c == '=' || 
            c == '+' || c == '$' || c == ',' || c == '/' || c == '?' || 
            c == '#' || c == '[' || c == ']' || c == '@') {
            sanitized_url[j++] = c;
        }
    }
    sanitized_url[j] = '\0'; // Null-terminate the sanitized string

    return sanitized_url;
}

int main() {
    char* url = malloc(MAX_URL_LENGTH);
    if (!url) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    printf("Enter a URL to sanitize: ");
    if (fgets(url, MAX_URL_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading input!\n");
        free(url);
        return EXIT_FAILURE;
    }

    // Removing potential newline character at the end
    url[strcspn(url, "\n")] = '\0';

    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);

    // Cleanup
    free(url);
    free(sanitized_url);
    return EXIT_SUCCESS;
}