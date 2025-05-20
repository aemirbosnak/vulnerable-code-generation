//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

int is_valid_url_char(char c) {
    if (isalnum(c))
        return 1;
    switch (c) {
        case '-':
        case '_':
        case '.':
        case '~':
            return 1;
        default:
            return 0;
    }
}

char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LEN);
    char *ptr = sanitized_url;
    int in_scheme = 1;
    int in_host = 0;

    while (*url!= '\0') {
        if (in_scheme && (*url == ':' || *url == '/' || *url == '?' || *url == '#')) {
            *ptr++ = *url;
        } else if (in_scheme && is_valid_url_char(*url)) {
            *ptr++ = *url;
        } else if (*url == ':') {
            in_scheme = 0;
            in_host = 1;
        } else if (in_host && is_valid_url_char(*url)) {
            *ptr++ = *url;
        }

        url++;
    }

    *ptr = '\0';
    return sanitized_url;
}

int main() {
    char input_url[MAX_URL_LEN];
    printf("Enter a URL: ");
    fgets(input_url, MAX_URL_LEN, stdin);

    char *sanitized_url = sanitize_url(input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}