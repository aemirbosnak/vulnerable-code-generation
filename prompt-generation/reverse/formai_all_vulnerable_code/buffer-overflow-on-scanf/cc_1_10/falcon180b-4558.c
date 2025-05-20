//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    switch (c) {
        case 'a'...'z':
        case 'A'...'Z':
        case '0'...'9':
        case '-':
        case '.':
        case '_':
        case '~':
        case ':':
        case '/':
        case '?':
        case '#':
        case '[':
        case ']':
        case '@':
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
        case '=':
            return 1;
        default:
            return 0;
    }
}

int is_valid_url(char *url) {
    int i = 0;
    while (url[i]) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

char *sanitize_url(char *url) {
    int i = 0, j = 0;
    char *sanitized_url = (char *)malloc(MAX_URL_LENGTH * sizeof(char));
    while (url[i]) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[j] = url[i];
            j++;
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
    char *sanitized_url = sanitize_url(url);
    if (is_valid_url(sanitized_url)) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Invalid URL!\n");
    }
    free(sanitized_url);
    return 0;
}