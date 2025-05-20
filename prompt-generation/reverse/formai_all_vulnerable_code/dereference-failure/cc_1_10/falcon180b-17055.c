//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LEN 4096

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '/' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%') {
        return 1;
    }
    return 0;
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
    int i, j;
    char *clean_url = malloc(MAX_URL_LEN);
    clean_url[0] = '\0';
    for (i = 0; i < strlen(url); i++) {
        if (is_valid_url_char(url[i])) {
            strncat(clean_url, &url[i], 1);
        }
    }
    for (i = 0; i < strlen(clean_url); i++) {
        if (clean_url[i] == '%') {
            if (i + 2 < strlen(clean_url)) {
                char hex_str[3] = {0};
                strncat(hex_str, &clean_url[i + 1], 2);
                int hex_val = strtol(hex_str, NULL, 16);
                char ascii_val = hex_val;
                strncat(clean_url, &ascii_val, 1);
                i += 2;
            }
        }
    }
    strcpy(url, clean_url);
    free(clean_url);
}

int main() {
    char url[MAX_URL_LEN];
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}