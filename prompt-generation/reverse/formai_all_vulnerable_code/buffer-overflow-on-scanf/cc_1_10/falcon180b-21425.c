//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: expert-level
// URL Sanitizer in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '-' || c == '_' || c == '.' || c == '~' || c == '!') {
        return 1;
    } else if (c == '%') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char *url) {
    int length = strlen(url);
    if (length == 0 || length > MAX_URL_LENGTH) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
    }
    return 1;
}

void sanitize_url(char *url) {
    int length = strlen(url);
    if (length == 0 || length > MAX_URL_LENGTH) {
        return;
    }
    for (int i = 0; i < length; i++) {
        if (!is_valid_url_char(url[i])) {
            url[i] = '_';
        }
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    if (!is_valid_url(url)) {
        printf("Invalid URL.\n");
    } else {
        sanitize_url(url);
        printf("Sanitized URL: %s\n", url);
    }
    return 0;
}

// End of URL Sanitizer in C