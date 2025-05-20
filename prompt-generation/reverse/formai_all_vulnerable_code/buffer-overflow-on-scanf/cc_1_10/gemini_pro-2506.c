//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define URL_MAX_LEN 1024

// Function to validate a URL
int is_valid_url(const char *url) {
    // Check if the URL is empty
    if (strlen(url) == 0) {
        return 0;
    }

    // Check if the URL starts with "http://" or "https://"
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        return 0;
    }

    // Check if the URL contains any invalid characters
    for (int i = 0; i < strlen(url); i++) {
        char c = url[i];
        if (!(isalnum(c) || c == '.' || c == '-' || c == '_' || c == '/' || c == ':' || c == '@')) {
            return 0;
        }
    }

    // Check if the URL is too long
    if (strlen(url) > URL_MAX_LEN) {
        return 0;
    }

    return 1;
}

// Function to sanitize a URL
char *sanitize_url(const char *url) {
    // Allocate memory for the sanitized URL
    char *sanitized_url = malloc(strlen(url) + 1);

    // Copy the URL into the sanitized URL
    strcpy(sanitized_url, url);

    // Replace any invalid characters with underscores
    for (int i = 0; i < strlen(sanitized_url); i++) {
        char c = sanitized_url[i];
        if (!(isalnum(c) || c == '.' || c == '-' || c == '_' || c == '/' || c == ':' || c == '@')) {
            sanitized_url[i] = '_';
        }
    }

    // Truncate the URL if it is too long
    if (strlen(sanitized_url) > URL_MAX_LEN) {
        sanitized_url[URL_MAX_LEN] = '\0';
    }

    return sanitized_url;
}

int main() {
    // Get the URL from the user
    char url[URL_MAX_LEN];
    printf("Enter the URL: ");
    scanf("%s", url);

    // Validate the URL
    if (!is_valid_url(url)) {
        printf("Invalid URL!\n");
        return 1;
    }

    // Sanitize the URL
    char *sanitized_url = sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the memory allocated for the sanitized URL
    free(sanitized_url);

    return 0;
}