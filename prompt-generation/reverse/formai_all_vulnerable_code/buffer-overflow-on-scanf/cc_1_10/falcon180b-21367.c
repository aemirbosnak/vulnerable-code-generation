//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: real-life
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 2048

int is_valid_char(char c) {
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
        (c == '=')) {
        return 1;
    }
    return 0;
}

char* sanitize_url(char* url) {
    int len = strlen(url);
    char* sanitized_url = malloc(MAX_LEN * sizeof(char));
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (is_valid_char(url[i])) {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';

    return sanitized_url;
}

int main() {
    char url[MAX_LEN];
    printf("Enter a URL: ");
    scanf("%s", url);

    char* sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}