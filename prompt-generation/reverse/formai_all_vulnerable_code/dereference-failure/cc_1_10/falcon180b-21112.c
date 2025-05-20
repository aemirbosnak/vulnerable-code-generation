//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is valid for a URL
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '%' || c == '&' || c == '*' || c == '+' || c == '/' || c == '=' || c == '?' || c == '@' || c == '^' || c == '`' || c == '{' || c == '}' || c == '|' || c == '\\' || c == ']') {
        return 1;
    }
    return 0;
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    int sanitized_url_length = 0;

    // Copy the original URL to the sanitized URL
    for (int i = 0; i < strlen(url); i++) {
        char c = url[i];

        // Check if the character is valid for a URL
        if (is_valid_url_char(c)) {
            sanitized_url[sanitized_url_length] = c;
            sanitized_url_length++;
        }
    }

    // Add a null terminator to the sanitized URL
    sanitized_url[sanitized_url_length] = '\0';

    return sanitized_url;
}

// Function to print a sanitized URL
void print_sanitized_url(char* url) {
    printf("Sanitized URL: %s\n", url);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char* url = argv[1];
    char* sanitized_url = sanitize_url(url);
    print_sanitized_url(sanitized_url);

    free(sanitized_url);
    return 0;
}