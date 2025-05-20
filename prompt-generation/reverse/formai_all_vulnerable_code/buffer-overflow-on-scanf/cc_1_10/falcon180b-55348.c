//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is valid in a URL
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',') {
        return 1;
    }
    return 0;
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    int i = 0;
    int j = 0;

    // Copy valid characters to sanitized_url
    while (url[i]) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[j++] = url[i++];
        } else {
            i++;
        }
    }
    sanitized_url[j] = '\0';

    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    char* sanitized_url;

    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    // Sanitize the URL
    sanitized_url = sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}