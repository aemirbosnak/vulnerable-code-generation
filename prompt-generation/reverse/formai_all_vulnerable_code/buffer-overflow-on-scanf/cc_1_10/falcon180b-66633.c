//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;="
#define NUM_ALLOWED_CHARACTERS (sizeof(ALLOWED_CHARACTERS) - 1)

int is_allowed_character(char c) {
    for (int i = 0; i < NUM_ALLOWED_CHARACTERS; i++) {
        if (ALLOWED_CHARACTERS[i] == c) {
            return 1;
        }
    }
    return 0;
}

int is_valid_url(char* url) {
    int length = strlen(url);

    if (length <= 0 || length >= MAX_URL_LENGTH) {
        return 0;
    }

    char* p = url;
    while (*p!= '\0') {
        if (!is_allowed_character(*p)) {
            return 0;
        }
        p++;
    }

    return 1;
}

void sanitize_url(char* url) {
    int length = strlen(url);
    char sanitized_url[MAX_URL_LENGTH];
    int sanitized_length = 0;

    char* p = url;
    while (*p!= '\0') {
        if (is_allowed_character(*p)) {
            sanitized_url[sanitized_length++] = *p;
        }
        p++;
    }
    sanitized_url[sanitized_length] = '\0';

    strcpy(url, sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    scanf("%s", url);

    if (is_valid_url(url)) {
        printf("URL is valid.\n");
    } else {
        printf("URL is not valid.\n");
        sanitize_url(url);
        printf("Sanitized URL: %s\n", url);
    }

    return 0;
}