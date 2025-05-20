//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= '0' && c <= '9')
        return 1;
    if (c == '-')
        return 1;
    if (c == '_')
        return 1;
    if (c == '.')
        return 1;
    if (c == '~')
        return 1;
    return 0;
}

int is_valid_url(char* url) {
    int i = 0;
    while (url[i]) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

char* sanitize_url(char* url) {
    int i = 0;
    char* sanitized_url = (char*)malloc(MAX_URL_LENGTH * sizeof(char));
    while (url[i]) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[i] = url[i];
            i++;
        }
    }
    sanitized_url[i] = '\0';
    return sanitized_url;
}

int main() {
    char input_url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", input_url);
    char* sanitized_url = sanitize_url(input_url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}