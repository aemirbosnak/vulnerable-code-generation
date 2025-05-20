//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c)) return 1;
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

int is_valid_url(const char *url) {
    int i = 0;
    while (url[i]!= '\0' && i < MAX_URL_LENGTH) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

void sanitize_url(char *url) {
    int i = 0;
    while (url[i]!= '\0' && i < MAX_URL_LENGTH) {
        if (!is_valid_url_char(url[i])) {
            url[i] = '_';
        }
        i++;
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    if (!is_valid_url(url)) {
        sanitize_url(url);
        printf("Sanitized URL: %s\n", url);
    } else {
        printf("URL is valid.\n");
    }

    return 0;
}