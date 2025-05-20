//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 256

// Function to check if character is alphanumeric
bool isAlphanumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Function to check if character is a special character
bool isSpecialChar(char c) {
    return !isAlphanumeric(c) && !(c == '-' || c == '_' || c == '.');
}

// Function to check if URL is valid
bool isURLValid(char* url) {
    int len = strlen(url);

    // Check if URL starts with "http://", "https://", "ftp://" or "ftps://"
    if (len < 7 || (strstr(url, "http://") != url && strstr(url, "https://") != url && strstr(url, "ftp://") != url && strstr(url, "ftps://") != url))
        return false;

    // Check if the URL is longer than MAX_LEN characters
    if (len > MAX_LEN)
        return false;

    // Check if there are any invalid characters in the URL
    for (int i = 0; i < len; i++) {
        if (isSpecialChar(url[i]))
            return false;
    }

    return true;
}

// Function to sanitize URL by removing any unauthorized characters
void sanitizeURL(char* url) {
    char sanitizedURL[MAX_LEN + 1] = {0};
    int sanitizedIndex = 0;

    for (int i = 0; url[i] != '\0'; i++) {
        char c = url[i];

        // Only add alphanumeric characters, '-' (hyphen), '_' (underscore), and '.' (dot) to the sanitized URL
        if (isAlphanumeric(c) || c == '-' || c == '_' || c == '.') {
            sanitizedURL[sanitizedIndex++] = c;
        }
    }

    strcpy(url, sanitizedURL);
}

int main() {
    char url[MAX_LEN + 1] = {0};

    // Get URL input from the user
    printf("Enter a URL: ");
    scanf("%s", url);

    // Check if URL is valid
    if (!isURLValid(url)) {
        printf("Invalid URL\n");
        return 1;
    }

    // Sanitize URL
    sanitizeURL(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}