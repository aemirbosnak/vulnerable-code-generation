//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

int is_valid_char(char c) {
    return (isalpha(c) || isdigit(c) || c == '.' || c == '-' || c == '_' || c == '+' || c == '~' || c == '*' || c == '/' || c == '?'|| c == '&' || c == '=' || c == '%' || c == '$');
}

int is_valid_url(char* url) {
    int len = strlen(url);
    if (len <= 0 || len >= MAX_URL_LEN) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!is_valid_char(url[i])) {
            return 0;
        }
    }
    return 1;
}

void sanitize_url(char* url) {
    int len = strlen(url);
    char* dst = malloc(MAX_URL_LEN);
    int dst_len = 0;
    for (int i = 0; i < len; i++) {
        if (is_valid_char(url[i])) {
            dst[dst_len++] = url[i];
        } else {
            dst[dst_len++] = '%';
            dst[dst_len++] = '2';
            dst[dst_len++] = '0';
        }
    }
    dst[dst_len] = '\0';
    strcpy(url, dst);
    free(dst);
}

int main() {
    char url[MAX_URL_LEN];
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