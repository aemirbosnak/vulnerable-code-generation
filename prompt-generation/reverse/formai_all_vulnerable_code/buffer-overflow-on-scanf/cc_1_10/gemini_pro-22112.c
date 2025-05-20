//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

char *sanitize_url(char *url) {
    // Allocate memory for the sanitized URL.
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    if (sanitized_url == NULL) {
        return NULL;
    }

    // Copy the URL to the sanitized URL.
    strcpy(sanitized_url, url);

    // Convert the URL to lowercase.
    for (int i = 0; i < strlen(sanitized_url); i++) {
        sanitized_url[i] = tolower(sanitized_url[i]);
    }

    // Remove any spaces from the URL.
    int j = 0;
    for (int i = 0; i < strlen(sanitized_url); i++) {
        if (sanitized_url[i] != ' ') {
            sanitized_url[j++] = sanitized_url[i];
        }
    }
    sanitized_url[j] = '\0';

    // Remove any trailing slashes from the URL.
    while (strlen(sanitized_url) > 0 && sanitized_url[strlen(sanitized_url) - 1] == '/') {
        sanitized_url[strlen(sanitized_url) - 1] = '\0';
    }

    // Add a trailing slash to the URL if it doesn't already have one.
    if (strlen(sanitized_url) > 0 && sanitized_url[strlen(sanitized_url) - 1] != '/') {
        strcat(sanitized_url, "/");
    }

    // Return the sanitized URL.
    return sanitized_url;
}

int main() {
    // Get the URL from the user.
    char url[MAX_URL_LENGTH];
    printf("Enter the URL: ");
    scanf("%s", url);

    // Sanitize the URL.
    char *sanitized_url = sanitize_url(url);

    // Print the sanitized URL.
    printf("The sanitized URL is: %s\n", sanitized_url);

    // Free the memory allocated for the sanitized URL.
    free(sanitized_url);

    return 0;
}