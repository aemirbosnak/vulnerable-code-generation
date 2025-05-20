//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '/' || c == '?'|| c == '&' || c == '=' || c == '+' || c == '%' || c == '$') {
        return 1;
    }
    return 0;
}

int is_valid_url(char *url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

char *sanitize_url(char *url) {
    int i = 0;
    char *sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    while (url[i]!= '\0') {
        if (is_valid_url_char(url[i])) {
            sanitized_url[i] = url[i];
        } else {
            sanitized_url[i] = '%';
            i++;
            int j = 0;
            while (isxdigit(url[i])) {
                j = j * 16 + (url[i] - '0');
                i++;
            }
            if (j > 0) {
                j -= 1;
                sanitized_url[i] = (char)j;
            } else {
                sanitized_url[i] = '%';
            }
        }
        i++;
    }
    sanitized_url[i] = '\0';
    return sanitized_url;
}

int main() {
    char *input_url = "https://www.example.com/path/to/file?query=string&param=value#fragment";
    char *sanitized_url = sanitize_url(input_url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}