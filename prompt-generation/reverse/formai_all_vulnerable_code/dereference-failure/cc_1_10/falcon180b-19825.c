//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '/' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%' || c == '$') {
        return 1;
    } else {
        return 0;
    }
}

int sanitize_url(char *url) {
    int i = 0;
    int j = 0;
    int len = strlen(url);
    char sanitized_url[MAX_URL_LENGTH];

    while (i < len) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[j++] = url[i];
        } else {
            sanitized_url[j++] = '%';
            j += sprintf(&sanitized_url[j], "%02X", (unsigned char)url[i]);
        }
        i++;
    }

    sanitized_url[j] = '\0';
    strcpy(url, sanitized_url);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LENGTH];
    strcpy(url, argv[1]);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}