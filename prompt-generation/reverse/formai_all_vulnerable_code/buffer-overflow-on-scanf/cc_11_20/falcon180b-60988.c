//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_character(char c) {
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
        (c == '-') ||
        (c == '.') ||
        (c == '_') ||
        (c == '~') ||
        (c == '!') ||
        (c == '$') ||
        (c == '&') ||
        (c == '\'') ||
        (c == '(') ||
        (c == ')') ||
        (c == '*') ||
        (c == '+') ||
        (c == ',') ||
        (c == ';') ||
        (c == ':') ||
        (c == '=') ||
        (c == '?') ||
        (c == '@') ||
        (c == '[') ||
        (c == ']') ||
        (c == '^') ||
        (c == '`') ||
        (c == '{') ||
        (c == '|') ||
        (c == '}') ||
        (c == '~')) {
        return 1;
    } else {
        return 0;
    }
}

char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    int i = 0;
    int j = 0;
    while (url[i]) {
        if (is_valid_character(url[i])) {
            sanitized_url[j++] = url[i];
        }
        i++;
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}