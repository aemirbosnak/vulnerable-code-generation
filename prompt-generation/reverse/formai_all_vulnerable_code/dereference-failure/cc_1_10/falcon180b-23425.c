//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (isalnum(c)) {
        return 1;
    } else if (c == '-' || c == '.' || c == '_' || c == '~' || c == '/' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char *url) {
    int length = strlen(url);
    if (length == 0) {
        return 0;
    }
    if (url[0]!= 'h' || url[1]!= 't' || url[2]!= 't' || url[3]!= 'p' || url[4]!= ':') {
        return 0;
    }
    int i = 5;
    while (i < length) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

char *sanitize_url(char *url) {
    int length = strlen(url);
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    int i = 0;
    while (i < length) {
        if (is_valid_url_character(url[i])) {
            sanitized_url[i] = url[i];
        } else {
            sanitized_url[i] = '%';
            i++;
            if (is_valid_url_character(url[i])) {
                sprintf(&sanitized_url[i], "%02X", url[i]);
            } else {
                sprintf(&sanitized_url[i], "%%");
            }
        }
        i++;
    }
    sanitized_url[length] = '\0';
    return sanitized_url;
}

int main() {
    char *url = "https://example.com/path/to/resource?query=string&param1=value1&param2=value2";
    char *sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}