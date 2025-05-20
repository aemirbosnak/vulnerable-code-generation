//Code Llama-13B DATASET v1.0 Category: URL Sanitizer ; Style: Linus Torvalds
/*
 * Linus Torvalds URL Sanitizer Example Program
 *
 * This program takes a URL as input and sanitizes it by removing any
 * malicious or suspicious elements.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1024

int is_valid_url(char *url);
char *sanitize_url(char *url);

int main(int argc, char **argv) {
    char *url;
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }
    url = argv[1];
    if (!is_valid_url(url)) {
        printf("Invalid URL: %s\n", url);
        return 1;
    }
    url = sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}

int is_valid_url(char *url) {
    if (strlen(url) > MAX_URL_LENGTH) {
        return 0;
    }
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        return 0;
    }
    return 1;
}

char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    int i;
    for (i = 0; i < MAX_URL_LENGTH; i++) {
        if (url[i] == '\0') {
            break;
        }
        if (isalnum(url[i]) || url[i] == '-' || url[i] == '_' || url[i] == '.') {
            sanitized_url[i] = url[i];
        } else {
            sanitized_url[i] = '_';
        }
    }
    sanitized_url[i] = '\0';
    return sanitized_url;
}