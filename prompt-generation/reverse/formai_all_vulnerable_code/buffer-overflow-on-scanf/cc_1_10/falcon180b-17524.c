//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (c == '/' || c == '.' || c == '-' || c == '_' || c == '~' ||
        (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}

int is_valid_url(char *url) {
    int len = strlen(url);
    if (len == 0 || len > MAX_URL_LENGTH) {
        return 0;
    }
    char *ptr = url;
    while (*ptr) {
        if (!is_valid_url_character(*ptr)) {
            return 0;
        }
        ptr++;
    }
    return 1;
}

char *sanitize_url(char *url) {
    int len = strlen(url);
    char *sanitized_url = malloc(len + 1);
    if (sanitized_url == NULL) {
        return NULL;
    }
    char *ptr = sanitized_url;
    while (*url) {
        if (is_valid_url_character(*url)) {
            *ptr++ = *url++;
        } else {
            *ptr++ = '%';
            *ptr++ = (char) ((int) *url / 16 + (int) '0');
            *ptr++ = (char) ((int) *url % 16 + (int) '0');
            url++;
        }
    }
    *ptr = '\0';
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    char *sanitized_url = sanitize_url(url);
    if (sanitized_url == NULL) {
        printf("Error: Memory allocation failed.\n");
    } else if (is_valid_url(sanitized_url)) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Error: Invalid URL.\n");
    }
    free(sanitized_url);
    return 0;
}