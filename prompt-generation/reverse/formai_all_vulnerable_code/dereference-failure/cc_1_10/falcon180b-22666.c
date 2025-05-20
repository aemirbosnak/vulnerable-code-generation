//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LEN 2048
#define ALLOWED_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.~:/?#[]@!$&'()*+,;="

typedef struct {
    char *url;
    size_t len;
} URL;

URL *url_new(const char *str) {
    URL *url = malloc(sizeof(URL));
    url->url = strdup(str);
    url->len = strlen(str);
    return url;
}

void url_free(URL *url) {
    free(url->url);
    free(url);
}

bool is_allowed_char(char c) {
    return strchr(ALLOWED_CHARS, c)!= NULL;
}

bool is_valid_url(const char *url) {
    if (strlen(url) > MAX_URL_LEN) {
        return false;
    }
    for (int i = 0; i < strlen(url); i++) {
        if (!is_allowed_char(url[i])) {
            return false;
        }
    }
    return true;
}

char *url_sanitize(const char *url) {
    char *sanitized_url = malloc(MAX_URL_LEN);
    int j = 0;
    for (int i = 0; i < strlen(url); i++) {
        if (is_allowed_char(url[i])) {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    URL *url = url_new("https://example.com/path/to/page?query=string#hash");
    char *sanitized_url = url_sanitize(url->url);
    printf("Original URL: %s\n", url->url);
    printf("Sanitized URL: %s\n", sanitized_url);
    url_free(url);
    free(sanitized_url);
    return 0;
}