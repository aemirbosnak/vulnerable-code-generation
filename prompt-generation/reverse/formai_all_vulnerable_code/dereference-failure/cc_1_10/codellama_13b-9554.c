//Code Llama-13B DATASET v1.0 Category: URL Sanitizer ; Style: unmistakable
// URL Sanitizer Program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_URL_LENGTH 2083

// Function to sanitize a URL
void sanitize_url(char *url) {
    // Remove leading and trailing spaces
    while (isspace(*url)) {
        ++url;
    }
    char *end = url + strlen(url) - 1;
    while (isspace(*end)) {
        --end;
    }
    *(end + 1) = '\0';

    // Check for invalid characters
    for (char *c = url; *c != '\0'; ++c) {
        if (!isalnum(*c) && *c != '-' && *c != '_' && *c != '.') {
            *c = '_';
        }
    }

    // Check for consecutive invalid characters
    for (char *c = url; *c != '\0'; ++c) {
        if (*c == '_') {
            char *next = c + 1;
            while (*next == '_') {
                ++next;
            }
            if (*next != '\0') {
                memmove(c, next, strlen(next) + 1);
            }
        }
    }
}

int main(void) {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}