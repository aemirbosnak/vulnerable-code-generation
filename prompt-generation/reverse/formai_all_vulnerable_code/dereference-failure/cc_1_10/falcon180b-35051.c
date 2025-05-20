//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

// Returns 1 if the character is a valid URL character, 0 otherwise
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    } else if (c == '.') {
        return 1;
    } else if (c == '_') {
        return 1;
    } else if (c == '~') {
        return 1;
    } else {
        return 0;
    }
}

// Returns 1 if the URL is valid, 0 otherwise
int is_valid_url(char *url) {
    int i = 0;
    while (i < strlen(url)) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Sanitizes the URL by removing invalid characters and replacing them with '%' followed by the hexadecimal representation of the character
void sanitize_url(char *url) {
    int i = 0;
    while (i < strlen(url)) {
        if (!is_valid_url_char(url[i])) {
            sprintf(&url[i], "%%%02X", url[i]);
            i += 3;
        }
        i++;
    }
}

// Returns the length of the sanitized URL
int sanitized_url_len(char *url) {
    int i = 0;
    int len = 0;
    while (i < strlen(url)) {
        if (url[i] == '%') {
            i += 3;
        } else {
            i++;
        }
        len++;
    }
    return len;
}

// Returns 1 if the URL is valid and sanitized, 0 otherwise
int is_valid_sanitized_url(char *url) {
    int len = sanitized_url_len(url);
    if (len > MAX_URL_LEN) {
        return 0;
    }
    return is_valid_url(url);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }
    char *url = argv[1];
    sanitize_url(url);
    if (is_valid_sanitized_url(url)) {
        printf("Valid and sanitized URL: %s\n", url);
    } else {
        printf("Invalid URL: %s\n", url);
    }
    return 0;
}