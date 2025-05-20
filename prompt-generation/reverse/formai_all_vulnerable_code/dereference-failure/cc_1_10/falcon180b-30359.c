//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    }
    switch (c) {
        case '.':
        case '_':
        case '~':
        case '!':
        case '$':
        case '&':
        case '\'':
        case '(':
        case ')':
        case '*':
        case '+':
        case ',':
        case ';':
        case ':':
        case '=':
        case '?':
        case '@':
            return 1;
        default:
            return 0;
    }
}

int is_valid_url(char *url) {
    int len = strlen(url);
    if (len > MAX_URL_LEN) {
        return 0;
    }
    char *p = url;
    while (*p) {
        if (!is_valid_url_char(*p)) {
            return 0;
        }
        p++;
    }
    return 1;
}

char *sanitize_url(char *url) {
    int len = strlen(url);
    char *p = url;
    char *sanitized_url = malloc(MAX_URL_LEN * sizeof(char));
    int sanitized_len = 0;
    while (*p) {
        if (is_valid_url_char(*p)) {
            sanitized_url[sanitized_len++] = *p;
        }
        p++;
    }
    sanitized_url[sanitized_len] = '\0';
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LEN];
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LEN, stdin);
    char *sanitized_url = sanitize_url(url);
    if (is_valid_url(sanitized_url)) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Invalid URL\n");
    }
    free(sanitized_url);
    return 0;
}