//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.~:/?#[]@!$&'()*+,;="

int is_allowed_char(char c) {
    int i;
    for (i = 0; i < strlen(ALLOWED_CHARS); i++) {
        if (c == ALLOWED_CHARS[i]) {
            return 1;
        }
    }
    return 0;
}

int is_valid_url(char *url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (!is_allowed_char(url[i])) {
            return 0;
        }
    }
    return 1;
}

void sanitize_url(char *url) {
    int i, j;
    char buffer[MAX_URL_LENGTH];
    for (i = 0, j = 0; i < strlen(url); i++) {
        if (is_allowed_char(url[i])) {
            buffer[j++] = url[i];
        }
    }
    buffer[j] = '\0';
    strcpy(url, buffer);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitize_url(url);
    if (is_valid_url(url)) {
        printf("Sanitized URL: %s\n", url);
    } else {
        printf("Invalid URL\n");
    }
    return 0;
}