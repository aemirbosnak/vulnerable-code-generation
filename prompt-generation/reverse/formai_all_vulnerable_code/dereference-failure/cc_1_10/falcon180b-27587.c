//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '/' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%' || c == '$') {
        return 1;
    }
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
    char* sanitized_url = malloc(MAX_URL_LEN);
    int i = 0;
    while (url[i]) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[i] = url[i];
        } else {
            sanitized_url[i] = '%';
            i++;
            int hex_val = url[i] >> 4;
            if (hex_val < 10) {
                sanitized_url[i] = hex_val + '0';
            } else {
                sanitized_url[i] = hex_val + 'A' - 10;
            }
            i++;
            hex_val = url[i] & 0x0F;
            if (hex_val < 10) {
                sanitized_url[i] = hex_val + '0';
            } else {
                sanitized_url[i] = hex_val + 'A' - 10;
            }
        }
        i++;
    }
    sanitized_url[i] = '\0';
    return sanitized_url;
}

int main() {
    char* url = "http://www.example.com/path?query=string&param=value#fragment";
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}