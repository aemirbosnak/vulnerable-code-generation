//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_LEN 256
#define ALLOWED_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~"
#define IS_VALID_CHAR(c) (strchr(ALLOWED_CHARS, (unsigned char)(c)) != NULL)
bool is_valid_url(char *url) {
    size_t len = strlen(url);
    if (len > MAX_LEN || len < 3) return false;
    if (url[0] != 'http' && url[0] != 'https') return false;
    size_t port_start = 0;
    size_t port_end = 0;
    if (strchr(url, ':') != NULL) {
        port_start = strchr(url, ':') - url;
        if (port_start > 2 && url[port_start - 1] != '/') return false;
        port_end = strchr(url, '/') != NULL ? strchr(url, '/') - url : len;
        if (port_end > port_start + 2 || port_end - port_start < 2) return false;
        if (atoi(url + port_start + 1) < 1 || atoi(url + port_start + 1) > 65535) return false;
    }
    for (size_t i = 0; i < len; ++i) {
        if (!IS_VALID_CHAR(url[i])) {
            if (url[i] == '.' && (i > 0 && i < len - 1 && IS_VALID_CHAR(url[i-1]) && IS_VALID_CHAR(url[i+1]))) continue;
            if (url[i] == '/') continue;
            if (url[i] == '?') {
                for (size_t j = i+1; j < len; ++j) {
                    if (IS_VALID_CHAR(url[j])) continue;
                    if (url[j] == '\0') break;
                    return false;
                }
                break;
            }
            return false;
        }
    }
    return true;
}
void sanitize_url(char *url) {
    size_t len = strlen(url);
    for (size_t i = 0; i < len; ++i) {
        if (!IS_VALID_CHAR(url[i])) {
            if (url[i] == '.' && (i > 0 && i < len - 1 && IS_VALID_CHAR(url[i-1]) && IS_VALID_CHAR(url[i+1]))) continue;
            url[i] = '_';
        }
    }
}
int main() {
    char url[MAX_LEN];
    printf("Enter a URL: ");
    scanf("%s", url);
    if (is_valid_url(url)) {
        printf("Valid URL.\n");
        sanitize_url(url);
        printf("Sanitized URL: %s\n", url);
    } else {
        printf("Invalid URL.\n");
    }
    return 0;
}