//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1024

// Function to sanitize a URL
char* sanitize_url(char* url) {
    // Allocate memory for the sanitized URL
    char* sanitized_url = malloc(MAX_URL_LENGTH);
    if (sanitized_url == NULL) {
        return NULL;
    }

    // Copy the URL to the sanitized URL
    strcpy(sanitized_url, url);

    // Convert the URL to lowercase
    for (int i = 0; i < strlen(sanitized_url); i++) {
        sanitized_url[i] = tolower(sanitized_url[i]);
    }

    // Remove any spaces from the URL
    char* new_sanitized_url = malloc(MAX_URL_LENGTH);
    if (new_sanitized_url == NULL) {
        free(sanitized_url);
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < strlen(sanitized_url); i++) {
        if (sanitized_url[i] != ' ') {
            new_sanitized_url[j] = sanitized_url[i];
            j++;
        }
    }

    // Terminate the new sanitized URL
    new_sanitized_url[j] = '\0';

    // Free the old sanitized URL
    free(sanitized_url);

    // Return the new sanitized URL
    return new_sanitized_url;
}

// Main function
int main() {
    // Get the URL from the user
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize the URL
    char* sanitized_url = sanitize_url(url);
    if (sanitized_url == NULL) {
        printf("Error: Could not sanitize URL.\n");
        return EXIT_FAILURE;
    }

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the sanitized URL
    free(sanitized_url);

    return EXIT_SUCCESS;
}