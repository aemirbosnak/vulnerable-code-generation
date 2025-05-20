//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_URL_LENGTH 2048

int is_valid_char(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char* url) {
    int i = 0;
    int is_valid = 1;
    while (url[i]!= '\0' && is_valid) {
        if (!is_valid_char(url[i])) {
            is_valid = 0;
        }
        i++;
    }
    return is_valid;
}

char* sanitize_url(char* url) {
    int i = 0;
    int j = 0;
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    if (sanitized_url == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    while (url[i]!= '\0') {
        if (is_valid_char(url[i])) {
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
        printf("Error: Invalid URL\n");
    }
    free(sanitized_url);
    return 0;
}