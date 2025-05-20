//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 4096

int is_valid_char(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' || c == ';' || c == '=' || c == '?' || c == '@' || c == '[' || c == '\\' || c == ']' || c == '^' || c == '`' || c == '{' || c == '|' || c == '}' || c == '~') {
        return 1;
    }
    return 0;
}

char* sanitize_url(char* url) {
    int len = strlen(url);
    if (len > MAX_URL_LEN) {
        return NULL;
    }
    char* sanitized_url = malloc(len + 1);
    if (!sanitized_url) {
        return NULL;
    }
    int i = 0;
    while (i < len) {
        if (is_valid_char(url[i])) {
            sanitized_url[i] = url[i];
            i++;
        } else {
            i++;
        }
    }
    sanitized_url[i] = '\0';
    return sanitized_url;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }
    char* url = argv[1];
    char* sanitized_url = sanitize_url(url);
    if (!sanitized_url) {
        printf("Error: Invalid URL\n");
        return 1;
    }
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}