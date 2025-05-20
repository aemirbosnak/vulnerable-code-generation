//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: cheerful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_URL_LEN 2048

int is_valid_url_char(char c) {
    if (isalnum(c)) {
        return 1;
    }
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

int is_valid_url(char *url) {
    int len = strlen(url);
    if (len == 0 || len > MAX_URL_LEN) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
    }
    return 1;
}

void sanitize_url(char *url) {
    int len = strlen(url);
    char sanitized_url[MAX_URL_LEN];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    strcpy(url, sanitized_url);
}

int main() {
    char url[MAX_URL_LEN];
    printf("Enter a URL: ");
    scanf("%s", url);

    if (is_valid_url(url)) {
        printf("Valid URL: %s\n", url);
        sanitize_url(url);
        printf("Sanitized URL: %s\n", url);
    } else {
        printf("Invalid URL\n");
    }

    return 0;
}