//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: multivariable
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

int is_valid_url(char* url) {
    int len = strlen(url);
    if (len > MAX_URL_LEN) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
    }
    return 1;
}

void sanitize_url(char* url) {
    int len = strlen(url);
    if (len > MAX_URL_LEN) {
        url[MAX_URL_LEN - 1] = '\0';
        len = MAX_URL_LEN;
    }
    for (int i = 0; i < len; i++) {
        if (!is_valid_url_char(url[i])) {
            url[i] = '_';
        }
    }
}

int main() {
    char url[MAX_URL_LEN];
    printf("Enter a URL: ");
    scanf("%s", url);
    if (!is_valid_url(url)) {
        printf("Invalid URL!\n");
        sanitize_url(url);
        printf("Sanitized URL: %s\n", url);
    } else {
        printf("Valid URL!\n");
    }
    return 0;
}