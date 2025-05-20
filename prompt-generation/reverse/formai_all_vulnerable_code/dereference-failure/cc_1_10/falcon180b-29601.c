//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define MAX_DOMAIN_LENGTH 255

int is_valid_url(char *url) {
    char *protocol = strtok(url, "://");
    if (protocol == NULL) {
        return 0;
    }
    if (strcasecmp(protocol, "http")!= 0 && strcasecmp(protocol, "https")!= 0) {
        return 0;
    }
    char *domain = strtok(NULL, "/");
    if (domain == NULL) {
        return 0;
    }
    int domain_length = strlen(domain);
    if (domain_length > MAX_DOMAIN_LENGTH) {
        return 0;
    }
    for (int i = 0; i < domain_length; i++) {
        if (!isalnum(domain[i]) && domain[i]!= '-') {
            return 0;
        }
    }
    return 1;
}

char *sanitize_url(char *url) {
    char *protocol = strtok(url, "://");
    char *domain = strtok(NULL, "/");
    char *path = strtok(NULL, "");
    char *query = strtok(NULL, "");
    char *fragment = strtok(NULL, "");

    char *sanitized_url = malloc(MAX_URL_LENGTH);
    sprintf(sanitized_url, "%s://%s", protocol, domain);

    if (path!= NULL) {
        strcat(sanitized_url, "/");
        strcat(sanitized_url, path);
    }

    if (query!= NULL) {
        strcat(sanitized_url, "?");
        strcat(sanitized_url, query);
    }

    if (fragment!= NULL) {
        strcat(sanitized_url, "#");
        strcat(sanitized_url, fragment);
    }

    return sanitized_url;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char *sanitized_url = sanitize_url(url);

    if (is_valid_url(sanitized_url)) {
        printf("Valid URL: %s\n", sanitized_url);
    } else {
        printf("Invalid URL: %s\n", url);
    }

    free(sanitized_url);
    return 0;
}