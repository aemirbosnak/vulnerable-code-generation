//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is a valid URL character
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '/' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%') {
        return 1;
    } else {
        return 0;
    }
}

// Function to sanitize a URL
void sanitize_url(char* url) {
    int i = 0;
    int j = 0;
    char sanitized_url[MAX_URL_LENGTH];

    // Copy the original URL to the sanitized URL
    strcpy(sanitized_url, url);

    // Loop through each character in the sanitized URL
    while (sanitized_url[i]) {
        // Check if the character is a valid URL character
        if (is_valid_url_char(sanitized_url[i])) {
            // Copy the character to the sanitized URL
            sanitized_url[j] = sanitized_url[i];
            j++;
        }
        i++;
    }

    // Add a null terminator to the sanitized URL
    sanitized_url[j] = '\0';

    // Copy the sanitized URL to the original URL
    strcpy(url, sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];

    // Get the URL from the user
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}