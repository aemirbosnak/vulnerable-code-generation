//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

/* Function to check if a character is a valid URL character */
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

/* Function to sanitize a URL */
char* sanitize_url(char* url) {
    int i, j;
    char* sanitized_url = malloc(MAX_URL_LENGTH);
    memset(sanitized_url, 0, MAX_URL_LENGTH);
    i = j = 0;
    while (url[i]) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[j++] = url[i];
        }
        i++;
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

/* Function to print the sanitized URL */
void print_sanitized_url(char* url) {
    printf("Sanitized URL: %s\n", url);
}

int main() {
    char* url = "https://www.example.com/path/to/page?query=string#fragment";
    char* sanitized_url = sanitize_url(url);
    print_sanitized_url(sanitized_url);
    free(sanitized_url);
    return 0;
}