//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_char(char c) {
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
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
        c == '?' ||
        c == '@' ||
        c == '[' ||
        c == ']' ||
        c == '^' ||
        c == '`' ||
        c == '{' ||
        c == '}' ||
        c == '|' ||
        c == '~') {
        return 1;
    } else {
        return 0;
    }
}

int sanitize_url(char* url) {
    int i = 0;
    int j = 0;
    while (url[i]) {
        if (is_valid_char(url[i])) {
            url[j++] = url[i];
        }
        i++;
    }
    url[j] = '\0';
    return 1;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    if (sanitize_url(url)) {
        printf("Sanitized URL: %s\n", url);
    } else {
        printf("Invalid characters in URL.\n");
    }
    return 0;
}