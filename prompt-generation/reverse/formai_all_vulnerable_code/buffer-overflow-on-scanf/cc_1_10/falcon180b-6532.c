//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.~:/?#[]@!$&'()*+,;="

int is_allowed_character(char c) {
    char *allowed = ALLOWED_CHARACTERS;
    while (*allowed) {
        if (c == *allowed) {
            return 1;
        }
        allowed++;
    }
    return 0;
}

void sanitize_url(char *url) {
    int i = 0;
    while (url[i]) {
        if (is_allowed_character(url[i])) {
            i++;
        } else {
            url[i] = '%';
            i++;
            sprintf(&url[i], "%02X", (unsigned char)url[i-1]);
            i += 2;
        }
    }
    url[i] = '\0';
}

void recursive_sanitize_url(char *url) {
    int i = 0;
    while (url[i]) {
        if (url[i] == '%') {
            i++;
            sprintf(&url[i], "%c", (unsigned char)strtol(&url[i], NULL, 16));
            i += 2;
        } else {
            i++;
        }
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    recursive_sanitize_url(url);
    printf("Recursively sanitized URL: %s\n", url);
    return 0;
}