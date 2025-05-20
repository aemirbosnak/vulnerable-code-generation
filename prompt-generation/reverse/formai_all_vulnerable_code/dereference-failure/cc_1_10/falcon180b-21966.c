//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 2048

int is_valid_char(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '*' || c == '\'' || c == '(' || c == ')' || c == ';' || c == ':' || c == '@' || c == '&' || c == '=' || c == '+' || c == '$' || c == ',' || c == '/' || c == '?' || c == '%' || c == '#') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char* url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_char(url[i])) {
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
    char* input_url = "https://www.example.com/path/to/file?query=string#fragment";
    char* sanitized_url = sanitize_url(input_url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}