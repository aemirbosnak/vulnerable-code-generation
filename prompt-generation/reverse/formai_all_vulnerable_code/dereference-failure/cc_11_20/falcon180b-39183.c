//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_char(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '*' || c == '+' || c == '=' || c == '?' || c == '/' || c == ';' || c == ':' || c == '@' || c == '%' || c == '^' || c == '&') {
        return 1;
    }
    return 0;
}

int is_valid_url(char *url) {
    int len = strlen(url);
    if (len > MAX_URL_LENGTH) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!is_valid_char(url[i])) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }
    char *url = argv[1];
    int len = strlen(url);
    if (len > MAX_URL_LENGTH) {
        printf("Error: URL is too long\n");
        return 1;
    }
    for (int i = 0; i < len; i++) {
        if (!is_valid_char(url[i])) {
            printf("Error: Invalid character in URL\n");
            return 1;
        }
    }
    printf("Valid URL\n");
    return 0;
}