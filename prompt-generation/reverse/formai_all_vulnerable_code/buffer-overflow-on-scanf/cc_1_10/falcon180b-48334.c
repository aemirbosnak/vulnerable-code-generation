//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' || c == ';' || c == '=' || c == ':' || c == '@' || c == '%' || c == '?' || c == '#' || c == '/' || c == '\\' || c == '|' || c == '^' || c == '`' || c == '{' || c == '}' || c == '[' || c == ']' || c == '~') {
        return 1;
    }
    return 0;
}

int is_valid_url(char *url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
    }
    return 1;
}

char *sanitize_url(char *url) {
    int i, j;
    char *new_url = malloc(MAX_URL_LENGTH * sizeof(char));
    i = j = 0;
    while (url[i]) {
        if (is_valid_url_char(url[i])) {
            new_url[j] = url[i];
            i++;
            j++;
        }
    }
    new_url[j] = '\0';
    return new_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    if (is_valid_url(url)) {
        printf("Valid URL: %s\n", url);
    } else {
        char *sanitized_url = sanitize_url(url);
        printf("Sanitized URL: %s\n", sanitized_url);
        free(sanitized_url);
    }
    return 0;
}