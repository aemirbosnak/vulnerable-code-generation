//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    } else if (c == '.') {
        return 1;
    } else if (c == '_') {
        return 1;
    } else if (c == '~') {
        return 1;
    } else if (c == '%') {
        if (isxdigit(strchr(c, '%'))) {
            return 1;
        }
    }
    return 0;
}

int is_valid_url(char* url) {
    int i = 0;
    while (url[i]) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

char* sanitize_url(char* url) {
    int i = 0;
    char* sanitized_url = calloc(MAX_URL_LENGTH, sizeof(char));
    while (url[i]) {
        if (is_valid_url_character(url[i])) {
            sanitized_url[i] = url[i];
        }
        i++;
    }
    return sanitized_url;
}

int main() {
    char* url = "https://www.example.com/path/to/file";
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}