//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 1024
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;="

int is_allowed_character(char c) {
    return (strchr(ALLOWED_CHARACTERS, c)!= NULL);
}

int is_valid_url(char* url) {
    int i = 0;
    int length = strlen(url);
    while (i < length) {
        if (!is_allowed_character(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

void sanitize_url(char* url) {
    int i = 0;
    int j = 0;
    int length = strlen(url);
    while (i < length) {
        if (is_allowed_character(url[i])) {
            url[j++] = url[i];
        }
        i++;
    }
    url[j] = '\0';
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