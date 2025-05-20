//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9') ||
           (c == '-') || (c == '.') || (c == '_') || (c == '~');
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

void sanitize_url(char *url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (url[i] == '%') {
            char hex[3];
            memset(hex, 0, 3);
            strncat(hex, &url[i+1], 2);
            int hex_val = strtol(hex, NULL, 16);
            char sanitized_char = hex_val % 256;
            url[i] = sanitized_char;
        }
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    sanitize_url(url);
    if (is_valid_url(url)) {
        printf("Sanitized URL: %s\n", url);
    } else {
        printf("Invalid URL\n");
    }
    return 0;
}