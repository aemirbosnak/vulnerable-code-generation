//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048

typedef struct {
    char *url;
    char *scheme;
    char *host;
    char *path;
    char *query;
    char *fragment;
} URLParts;

URLParts *sanitize_url(const char *url) {
    URLParts *parts = malloc(sizeof(URLParts));
    if (parts == NULL) {
        printf("Error: Failed to allocate memory for URLParts.\n");
        exit(1);
    }

    char *scheme_end = strstr(url, "://");
    if (scheme_end == NULL) {
        printf("Error: Invalid URL format.\n");
        free(parts);
        exit(1);
    }

    parts->url = strndup(url, MAX_URL_LENGTH);
    parts->scheme = strndup(url, scheme_end - url);
    parts->host = strndup(scheme_end + 3, strcspn(scheme_end + 3, "/?#"));
    parts->path = strndup(strchr(scheme_end + 3, '/'), strlen(scheme_end + 3) - strcspn(scheme_end + 3, "/?#"));
    parts->query = strndup(strchr(parts->path, '?'), strlen(parts->path) - strcspn(parts->path, "?#"));
    parts->fragment = strndup(strchr(parts->path, '#'), strlen(parts->path) - strcspn(parts->path, "?#"));

    return parts;
}

void print_url_parts(const URLParts *parts) {
    printf("URL: %s\n", parts->url);
    printf("Scheme: %s\n", parts->scheme);
    printf("Host: %s\n", parts->host);
    printf("Path: %s\n", parts->path);
    printf("Query: %s\n", parts->query);
    printf("Fragment: %s\n", parts->fragment);
}

void free_url_parts(URLParts *parts) {
    free(parts->url);
    free(parts->scheme);
    free(parts->host);
    free(parts->path);
    free(parts->query);
    free(parts->fragment);
    free(parts);
}

int main() {
    char input[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(input, MAX_URL_LENGTH, stdin);

    URLParts *parts = sanitize_url(input);
    if (parts == NULL) {
        return 1;
    }

    print_url_parts(parts);

    free_url_parts(parts);
    return 0;
}