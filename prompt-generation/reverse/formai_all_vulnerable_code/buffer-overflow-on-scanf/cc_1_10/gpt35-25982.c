//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a URL
#define MAX_URL_LENGTH 256

// Custom function to sanitize the URL
void sanitize_url(char* url) {
    // Define a list of unsafe characters
    char unsafe[] = "<>@!#$%^&*()+`~[]{}|\\;:\"',./?=";

    // Calculate length of URL
    int len = strlen(url);

    // Declare a temporary buffer
    char buffer[MAX_URL_LENGTH];

    // Set the buffer index to 0
    int buffer_index = 0;

    // Loop through each character of the URL
    for (int i = 0; i < len; i++) {
        // Get the current character
        char c = url[i];

        // Check if the current character is an unsafe character
        if (strchr(unsafe, c) == NULL) {
            // If not, add it to the buffer
            buffer[buffer_index++] = c;
        }
    }

    // Terminate the buffer with a null character
    buffer[buffer_index] = '\0';

    // Copy the contents of the buffer back to the original URL
    strcpy(url, buffer);
}

int main() {
    // Declare a URL variable
    char url[MAX_URL_LENGTH];

    // Prompt the user to enter a URL
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    // Sanitize the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}