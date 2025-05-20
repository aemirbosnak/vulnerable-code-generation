//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is valid in a URL
int is_valid_url_char(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '-' || c == '_' || c == '.' || c == '~') {
        return 1;
    } else {
        return 0;
    }
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH);
    int i = 0;
    int j = 0;

    // Loop through each character in the URL
    while (url[i]) {
        // Check if the character is valid
        if (is_valid_url_char(url[i])) {
            // Copy the character to the sanitized URL
            sanitized_url[j] = url[i];
            j++;
        }
        i++;
    }

    // Add a null terminator to the end of the sanitized URL
    sanitized_url[j] = '\0';

    return sanitized_url;
}

// Main function
int main() {
    char* input_url;

    // Prompt the user to enter a URL
    printf("Enter a URL to sanitize: ");
    scanf("%s", input_url);

    // Sanitize the URL
    char* sanitized_url = sanitize_url(input_url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the memory used for the sanitized URL
    free(sanitized_url);

    return 0;
}