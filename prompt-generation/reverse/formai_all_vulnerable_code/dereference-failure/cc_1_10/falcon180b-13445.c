//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',') {
        return 1;
    }
    return 0;
}

int is_valid_url(char *url) {
    int len = strlen(url);
    if (len <= 0 || len >= MAX_URL_LEN) {
        return 0;
    }
    char *p = url;
    while (*p) {
        if (!is_valid_url_char(*p)) {
            return 0;
        }
        p++;
    }
    return 1;
}

char *sanitize_url(char *url) {
    int len = strlen(url);
    char *sanitized_url = malloc(len + 1);
    if (!sanitized_url) {
        return NULL;
    }
    char *p = sanitized_url;
    while (*url) {
        if (is_valid_url_char(*url)) {
            *p = *url;
        } else {
            *p = '%';
            p++;
        }
        url++;
        p++;
    }
    *p = '\0';
    return sanitized_url;
}

int main() {
    char *url = "http://example.com/path?query=string#fragment";
    char *sanitized_url = sanitize_url(url);
    if (sanitized_url) {
        printf("sanitized url: %s\n", sanitized_url);
        free(sanitized_url);
    }
    return 0;
}