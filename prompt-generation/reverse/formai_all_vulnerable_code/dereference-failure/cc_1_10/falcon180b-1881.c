//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048

bool is_valid_url_character(char c) {
    if (isalnum(c) || c == '-') {
        return true;
    }

    switch (c) {
        case '?':
        case '&':
        case '=':
        case '/':
        case '.':
        case '_':
        case '~':
        case '+':
        case '%':
            return true;
        default:
            return false;
    }
}

bool is_valid_url(char* url) {
    int i = 0;

    while (url[i]!= '\0') {
        if (!is_valid_url_character(url[i])) {
            return false;
        }
        i++;
    }

    return true;
}

char* sanitize_url(char* url) {
    int i = 0;
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));

    while (url[i]!= '\0') {
        if (is_valid_url_character(url[i])) {
            sanitized_url[i] = url[i];
        } else {
            sanitized_url[i] = '%';
            i++;
            sprintf(&sanitized_url[i], "%02x", url[i]);
        }
        i++;
    }

    sanitized_url[i] = '\0';

    return sanitized_url;
}

int main() {
    char* url = "https://www.example.com/path?query=string#fragment";
    char* sanitized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}