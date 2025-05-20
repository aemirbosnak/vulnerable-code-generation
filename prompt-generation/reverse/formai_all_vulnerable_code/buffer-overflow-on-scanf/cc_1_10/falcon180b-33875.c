//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    }
    switch (c) {
        case '!':
        case '#':
        case '$':
        case '%':
        case '&':
        case '*':
        case '+':
        case '/':
        case '=':
        case '?':
        case '@':
        case '^':
        case '~':
            return 1;
        default:
            return 0;
    }
}

int is_valid_url(char* url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
    }
    return 1;
}

char* sanitize_url(char* url) {
    int i, j;
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    i = j = 0;
    while (url[i]) {
        if (is_valid_url_character(url[i])) {
            sanitized_url[j++] = tolower(url[i]);
        }
        i++;
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char* url;
    printf("Enter a URL: ");
    scanf("%s", url);
    if (is_valid_url(url)) {
        printf("Valid URL.\n");
    } else {
        char* sanitized_url = sanitize_url(url);
        printf("Sanitized URL: %s\n", sanitized_url);
        free(sanitized_url);
    }
    return 0;
}