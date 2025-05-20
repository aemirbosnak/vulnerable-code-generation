//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (c >= 'a' && c <= 'z' ||
        c >= 'A' && c <= 'Z' ||
        c >= '0' && c <= '9' ||
        c == '-' ||
        c == '.' ||
        c == '_' ||
        c == '~' ||
        c == '!' ||
        c == '$' ||
        c == '&' ||
        c == '\'' ||
        c == '(' ||
        c == ')' ||
        c == '*' ||
        c == '+' ||
        c == ',' ||
        c == ';' ||
        c == '=' ||
        c == ':' ||
        c == '@' ||
        c == '[' ||
        c == ']' ||
        c == '?' ||
        c == '/' ||
        c == '\\' ||
        c == '|' ||
        c == '^' ||
        c == '{' ||
        c == '}' ||
        c == '~' ||
        c == '%') {
        return 1;
    }
    return 0;
}

int is_valid_url(char *url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LENGTH];
    strcpy(url, argv[1]);

    if (is_valid_url(url)) {
        printf("Valid URL.\n");
    } else {
        printf("Invalid URL.\n");
    }

    return 0;
}