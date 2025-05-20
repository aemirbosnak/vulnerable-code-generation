//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == ':' || c == '/' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%' || c == '$') {
        return 1;
    }
    return 0;
}

int is_valid_url(char *url) {
    int length = strlen(url);
    if (length > MAX_URL_LENGTH) {
        return 0;
    }
    int i;
    for (i = 0; i < length; i++) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
    }
    return 1;
}

void sanitize_url(char *url) {
    int length = strlen(url);
    char *sanitized_url = malloc(length + 1);
    int i = 0;
    int j = 0;
    while (url[i]) {
        if (is_valid_url_character(url[i])) {
            sanitized_url[j] = url[i];
            j++;
        }
        i++;
    }
    sanitized_url[j] = '\0';
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter URL: ");
    scanf("%s", url);
    if (is_valid_url(url)) {
        printf("Valid URL\n");
        sanitize_url(url);
    } else {
        printf("Invalid URL\n");
    }
    return 0;
}