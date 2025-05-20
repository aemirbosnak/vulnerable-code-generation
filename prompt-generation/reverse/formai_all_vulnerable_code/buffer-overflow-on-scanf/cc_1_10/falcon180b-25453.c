//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.~:/?#[]@!$&'()*+,;=%"

int is_allowed_char(char c) {
    char *allowed = ALLOWED_CHARS;
    while (*allowed) {
        if (c == *allowed) {
            return 1;
        }
        allowed++;
    }
    return 0;
}

int is_valid_url(char *url) {
    int i, j;
    for (i = 0, j = 0; i < strlen(url); i++) {
        if (!is_allowed_char(url[i])) {
            return 0;
        }
        if (i == 0 && url[i]!= 'http' && url[i]!= 'https') {
            return 0;
        }
        if (i > 0 && i < strlen(url) - 1 && (url[i] == '.' || url[i] == '/')) {
            if (i > 0 && url[i - 1] == '/') {
                return 0;
            }
            if (i < strlen(url) - 1 && url[i + 1] == '/') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    if (is_valid_url(url)) {
        printf("URL is valid.\n");
    } else {
        printf("URL is invalid.\n");
    }

    return 0;
}