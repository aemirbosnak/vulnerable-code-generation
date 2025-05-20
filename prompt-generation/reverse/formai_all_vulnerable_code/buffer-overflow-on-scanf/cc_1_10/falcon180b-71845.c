//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '-' || c == '_' || c == '.' || c == '~') {
        return 1;
    } else if (c >= '!' && c <= '*') {
        return 1;
    } else if (c >= '+' && c <= '/') {
        return 1;
    } else if (c >= '?' && c <= '&') {
        return 1;
    } else if (c >= ':' && c <= '=') {
        return 1;
    } else {
        return 0;
    }
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

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    if (is_valid_url(url)) {
        printf("The URL is valid.\n");
    } else {
        printf("The URL is not valid.\n");
    }

    return 0;
}