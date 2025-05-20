//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

// Function to check if a character is valid for a URL
int is_valid_url_char(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '-' || c == '_' || c == '.' || c == '~') {
        return 1;
    } else {
        return 0;
    }
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LEN * sizeof(char));
    int sanitized_url_len = 0;

    while (*url) {
        if (is_valid_url_char(*url)) {
            sanitized_url[sanitized_url_len++] = tolower(*url);
        } else {
            sanitized_url[sanitized_url_len++] = '%';
            sanitized_url[sanitized_url_len++] = sprintf("%02X", (int) *url);
        }
        url++;
    }

    sanitized_url[sanitized_url_len] = '\0';
    return sanitized_url;
}

int main() {
    char input_url[MAX_URL_LEN];
    char* sanitized_url;

    printf("Enter a URL to sanitize: ");
    scanf("%s", input_url);

    sanitized_url = sanitize_url(input_url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}