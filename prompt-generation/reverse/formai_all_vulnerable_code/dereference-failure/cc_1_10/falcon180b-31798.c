//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 2048
#define MAX_ALLOWED_SCHEMES 10
#define MAX_ALLOWED_DOMAINS 10
#define MAX_ALLOWED_DOMAIN_LENGTH 255
#define MAX_ALLOWED_PATH_LENGTH 2048

typedef struct {
    char *scheme;
    char *domain;
    char *path;
} URL;

void sanitize_url(URL *url) {
    char *ptr = url->scheme;
    while (*ptr!= '\0') {
        if (!isalnum(*ptr)) {
            *ptr = '_';
        }
        ptr++;
    }

    ptr = url->domain;
    while (*ptr!= '\0') {
        if (!isalnum(*ptr) && *ptr!= '.' && *ptr!= '-') {
            *ptr = '_';
        }
        ptr++;
    }

    ptr = url->path;
    while (*ptr!= '\0') {
        if (!isalnum(*ptr) && *ptr!= '/' && *ptr!= '.' && *ptr!= '-' && *ptr!= '_' && *ptr!= '?' && *ptr!= '&' && *ptr!= '=' && *ptr!= '+') {
            *ptr = '_';
        }
        ptr++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <scheme> <domain> <path>\n", argv[0]);
        return 1;
    }

    URL url = {
       .scheme = argv[1],
       .domain = argv[2],
       .path = argv[3]
    };

    sanitize_url(&url);

    printf("Sanitized URL:\n");
    printf("Scheme: %s\n", url.scheme);
    printf("Domain: %s\n", url.domain);
    printf("Path: %s\n", url.path);

    return 0;
}