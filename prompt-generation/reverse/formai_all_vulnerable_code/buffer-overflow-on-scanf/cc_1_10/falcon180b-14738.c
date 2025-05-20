//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '/' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%') {
        return 1;
    }
    return 0;
}

int is_valid_url(char* url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
    }
    return 1;
}

void sanitize_url(char* url) {
    int i, j;
    char sanitized_url[MAX_URL_LENGTH];
    sanitized_url[0] = '\0';
    for (i = 0; i < strlen(url); i++) {
        if (is_valid_url_character(url[i])) {
            strncat(sanitized_url, &url[i], 1);
        }
    }
    for (i = 0, j = strlen(sanitized_url) - 1; i < j; i++, j--) {
        char temp = sanitized_url[i];
        sanitized_url[i] = sanitized_url[j];
        sanitized_url[j] = temp;
    }
    strcpy(url, sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    if (is_valid_url(url)) {
        printf("The URL is valid.\n");
    } else {
        printf("The URL is not valid.\n");
        sanitize_url(url);
        printf("Sanitized URL: %s\n", url);
    }
    return 0;
}