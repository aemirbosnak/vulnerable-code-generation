//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    }
    switch(c) {
        case '.':
        case '_':
        case '~':
        case '+':
        case '=':
        case '%':
        case '?':
        case '#':
        case '&':
        case '/':
        case ':':
        case ';':
        case ',':
        case '@':
        case '!':
        case '$':
        case '*':
        case '(':
        case ')':
        case '"':
            return 1;
        default:
            return 0;
    }
}

int is_valid_url(char* url) {
    int i = 0;
    while (url[i]!= '\0' && i < MAX_URL_LENGTH) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

void sanitize_url(char* url) {
    int i = 0;
    while (url[i]!= '\0' && i < MAX_URL_LENGTH) {
        if (!is_valid_url_char(url[i])) {
            url[i] = '%';
            i++;
        } else {
            i++;
        }
    }
    url[MAX_URL_LENGTH - 1] = '\0';
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}