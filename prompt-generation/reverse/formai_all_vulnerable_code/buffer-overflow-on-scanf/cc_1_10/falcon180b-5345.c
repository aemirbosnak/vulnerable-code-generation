//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048

bool is_valid_url_char(char c) {
    if (isalpha(c) || isdigit(c) || c == '-') {
        return true;
    } else if (c == '.') {
        return true;
    } else if (c == '_') {
        return true;
    } else if (c == '~') {
        return true;
    } else if (c == '/') {
        return true;
    } else if (c == '?') {
        return true;
    } else if (c == '&') {
        return true;
    } else if (c == '=') {
        return true;
    } else if (c == '+') {
        return true;
    } else if (c == '%') {
        return true;
    } else {
        return false;
    }
}

bool is_valid_url(const char *url) {
    int length = strlen(url);
    if (length > MAX_URL_LENGTH) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        char c = url[i];
        if (!is_valid_url_char(c)) {
            return false;
        }
    }
    return true;
}

void sanitize_url(char *url) {
    int length = strlen(url);
    for (int i = 0; i < length; i++) {
        char c = url[i];
        if (!is_valid_url_char(c)) {
            url[i] = '%';
            i += 2;
            sprintf(&url[i], "%02X", c);
        }
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    if (is_valid_url(url)) {
        printf("URL is valid.\n");
        sanitize_url(url);
        printf("Sanitized URL: %s\n", url);
    } else {
        printf("URL is not valid.\n");
    }
    return 0;
}