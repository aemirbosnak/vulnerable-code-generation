//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <regex.h>

#define MAX_URL_LENGTH 2048

bool is_valid_url_character(char c);
bool is_valid_url(char *url);
char *sanitize_url(char *url);

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    if (!is_valid_url(url)) {
        printf("Invalid URL.\n");
        return 1;
    }

    char *sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);

    return 0;
}

bool is_valid_url_character(char c) {
    return isalpha(c) || isdigit(c) || c == '.' || c == '/' || c == ':' || c == '?' || c == '&' || c == '=' || c == '-' || c == '_' || c == '~';
}

bool is_valid_url(char *url) {
    if (strlen(url) == 0) {
        return false;
    }
    for (int i = 0; i < strlen(url); i++) {
        if (!is_valid_url_character(url[i])) {
            return false;
        }
    }
    return true;
}

char *sanitize_url(char *url) {
    char *sanitized_url = malloc(strlen(url) + 1);
    int j = 0;
    for (int i = 0; i < strlen(url); i++) {
        if (is_valid_url_character(url[i])) {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}