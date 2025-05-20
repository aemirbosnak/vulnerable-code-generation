//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LEN 2048

bool is_valid_url_char(char c) {
    if (isalnum(c)) {
        return true;
    }
    switch (c) {
        case '-':
        case '_':
        case '.':
        case '~':
        case '/':
        case '?':
        case '&':
        case '=':
        case '+':
        case '%':
            return true;
        default:
            return false;
    }
}

int count_valid_url_chars(char *url) {
    int count = 0;
    for (int i = 0; i < strlen(url); i++) {
        if (is_valid_url_char(url[i])) {
            count++;
        }
    }
    return count;
}

bool is_valid_url(char *url) {
    int valid_url_char_count = count_valid_url_chars(url);
    if (valid_url_char_count == strlen(url)) {
        return true;
    }
    return false;
}

char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LEN * sizeof(char));
    int sanitized_url_len = 0;
    for (int i = 0; i < strlen(url); i++) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[sanitized_url_len++] = url[i];
        }
    }
    sanitized_url[sanitized_url_len] = '\0';
    return sanitized_url;
}

void main() {
    char input_url[MAX_URL_LEN];
    printf("Enter a URL to sanitize: ");
    scanf("%s", input_url);

    if (is_valid_url(input_url)) {
        printf("The input URL is already valid.\n");
    } else {
        char *sanitized_url = sanitize_url(input_url);
        printf("The sanitized URL is: %s\n", sanitized_url);
        free(sanitized_url);
    }
}