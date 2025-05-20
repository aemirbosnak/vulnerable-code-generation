//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

// Characters that are not allowed in a URL
char *disallowed_characters = "<>\"#%{}|\\^~[]`";

// Function to sanitize a URL
char *sanitize_url(char *url) {
    // Allocate memory for the sanitized URL
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    if (sanitized_url == NULL) {
        return NULL;
    }

    // Copy the URL into the sanitized URL
    strcpy(sanitized_url, url);

    // Replace all disallowed characters with underscores
    for (int i = 0; i < strlen(disallowed_characters); i++) {
        char c = disallowed_characters[i];
        for (int j = 0; j < strlen(sanitized_url); j++) {
            if (sanitized_url[j] == c) {
                sanitized_url[j] = '_';
            }
        }
    }

    // Return the sanitized URL
    return sanitized_url;
}

// Main function
int main() {
    // Get the URL from the user
    char url[MAX_URL_LENGTH];
    printf("Enter the URL: ");
    scanf("%s", url);

    // Sanitize the URL
    char *sanitized_url = sanitize_url(url);

    // If the URL was sanitized successfully, print it
    if (sanitized_url != NULL) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Error: Could not sanitize the URL.\n");
    }

    // Free the memory allocated for the sanitized URL
    free(sanitized_url);

    return 0;
}