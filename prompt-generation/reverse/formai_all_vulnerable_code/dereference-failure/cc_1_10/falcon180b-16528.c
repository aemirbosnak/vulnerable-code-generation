//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is valid for a URL
bool is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',') {
        return true;
    } else {
        return false;
    }
}

// Function to sanitize a URL
char* sanitize_url(const char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    int sanitized_url_length = 0;
    int i = 0;

    // Loop through the URL and copy valid characters to the sanitized URL
    while (url[i]!= '\0') {
        if (is_valid_url_char(url[i])) {
            sanitized_url[sanitized_url_length++] = url[i];
        }
        i++;
    }

    // Add a null terminator to the sanitized URL
    sanitized_url[sanitized_url_length] = '\0';

    return sanitized_url;
}

int main() {
    char* url = "https://www.example.com/path/to/page?query=string&foo=bar#fragment";

    // Sanitize the URL
    char* sanitized_url = sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the memory used by the sanitized URL
    free(sanitized_url);

    return 0;
}