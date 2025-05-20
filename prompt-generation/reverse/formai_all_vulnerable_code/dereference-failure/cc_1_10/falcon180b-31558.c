//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 2048

typedef struct {
    char *url;
    char *sanitized_url;
} url_sanitizer_t;

int is_valid_url(const char *url) {
    if (strlen(url) > MAX_URL_LENGTH) {
        return 0;
    }
    char *valid_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;=%";
    char *p;
    for (p = (char *)url; *p; p++) {
        if (!strchr(valid_chars, *p)) {
            return 0;
        }
    }
    return 1;
}

void sanitize_url(url_sanitizer_t *sanitizer) {
    char *p;
    for (p = sanitizer->url; *p; p++) {
        if (!isalnum(*p) && *p!= '.' && *p!= '-') {
            *p = '_';
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [URL]\n", argv[0]);
        return 1;
    }
    char *url = argv[1];
    if (!is_valid_url(url)) {
        printf("Invalid URL\n");
        return 1;
    }
    url_sanitizer_t sanitizer;
    sanitizer.url = strdup(url);
    sanitizer.sanitized_url = malloc(MAX_URL_LENGTH);
    if (!sanitizer.url ||!sanitizer.sanitized_url) {
        printf("Memory error\n");
        return 1;
    }
    sanitize_url(&sanitizer);
    strncpy(sanitizer.sanitized_url, sanitizer.url, MAX_URL_LENGTH - 1);
    sanitizer.sanitized_url[MAX_URL_LENGTH - 1] = '\0';
    printf("Sanitized URL: %s\n", sanitizer.sanitized_url);
    free(sanitizer.url);
    free(sanitizer.sanitized_url);
    return 0;
}