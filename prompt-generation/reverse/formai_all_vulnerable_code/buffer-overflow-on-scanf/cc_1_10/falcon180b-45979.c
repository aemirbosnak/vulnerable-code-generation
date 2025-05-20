//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.~:/?#[]@!$&'()*+,;="

int is_valid_character(char c) {
    return strchr(ALLOWED_CHARACTERS, c)!= NULL;
}

int is_valid_url(char* url) {
    int length = strlen(url);
    if (length > MAX_URL_LENGTH) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (!is_valid_character(url[i])) {
            return 0;
        }
    }

    return 1;
}

void sanitize_url(char* url) {
    int length = strlen(url);
    char* sanitized_url = malloc(length + 1);

    int j = 0;
    for (int i = 0; i < length; i++) {
        if (is_valid_character(url[i])) {
            sanitized_url[j++] = url[i];
        }
    }

    sanitized_url[j] = '\0';
    strcpy(url, sanitized_url);
    free(sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter URL: ");
    scanf("%s", url);

    if (is_valid_url(url)) {
        printf("Valid URL\n");
    } else {
        sanitize_url(url);
        printf("Sanitized URL: %s\n", url);
    }

    return 0;
}