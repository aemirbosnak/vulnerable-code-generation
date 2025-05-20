//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize a URL
char *sanitize_url(char *url) {
    // Allocate memory for the sanitized URL
    char *sanitized_url = malloc(strlen(url) + 1);
    if (sanitized_url == NULL) {
        return NULL;
    }

    // Copy the URL to the sanitized URL
    strcpy(sanitized_url, url);

    // Replace all spaces with %20
    char *ptr = sanitized_url;
    while (*ptr != '\0') {
        if (*ptr == ' ') {
            *ptr = '%';
            ptr++;
            *ptr = '2';
            ptr++;
            *ptr = '0';
        }
        ptr++;
    }

    // Return the sanitized URL
    return sanitized_url;
}

// Main function
int main() {
    // Get the URL from the user
    char url[1024];
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize the URL
    char *sanitized_url = sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the memory allocated for the sanitized URL
    free(sanitized_url);

    return 0;
}