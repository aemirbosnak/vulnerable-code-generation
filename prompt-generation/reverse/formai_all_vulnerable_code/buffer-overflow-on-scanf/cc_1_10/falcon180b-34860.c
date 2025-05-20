//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '+' || c == '=' || c == '&' || c == '?' || c == '%' || c == ';' || c == '$' || c == ',') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char* url) {
    int i = 0;
    while (url[i]) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

char* sanitize_url(char* url) {
    int i = 0;
    int j = 0;
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));

    while (url[i]) {
        if (is_valid_url_character(url[i])) {
            sanitized_url[j] = url[i];
            j++;
        }
        i++;
    }
    sanitized_url[j] = '\0';

    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    scanf("%s", url);

    char* sanitized_url = sanitize_url(url);

    if (is_valid_url(sanitized_url)) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Invalid URL\n");
    }

    free(sanitized_url);

    return 0;
}