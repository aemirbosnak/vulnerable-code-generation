//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_URL_LENGTH 2048

int is_valid_char(char c) {
    if (isalnum(c) || (c == '-') || (c == '.') || (c == '_')) {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char *url) {
    int i = 0;
    while (url[i]) {
        if (!is_valid_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

char *sanitize_url(char *url) {
    int i = 0;
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    if (sanitized_url == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    while (url[i]) {
        if (is_valid_char(url[i])) {
            sanitized_url[i] = url[i];
        } else {
            sanitized_url[i] = '_';
        }
        i++;
    }
    sanitized_url[i] = '\0';
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize:\n");
    scanf("%s", url);
    char *sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}