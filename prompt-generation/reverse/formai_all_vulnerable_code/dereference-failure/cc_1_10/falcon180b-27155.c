//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_URL_LENGTH 2048

char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH);
    memset(sanitized_url, 0, MAX_URL_LENGTH);
    strncpy(sanitized_url, url, MAX_URL_LENGTH - 1);

    char* protocol = strtok(sanitized_url, "://");
    char* domain = strtok(NULL, "/");
    char* path = strtok(NULL, "?");
    char* query = strtok(NULL, "#");

    char* sanitized_protocol = malloc(strlen(protocol) + 1);
    strncpy(sanitized_protocol, protocol, strlen(protocol));
    sanitized_protocol[strlen(protocol)] = '\0';

    char* sanitized_domain = malloc(strlen(domain) + 1);
    strncpy(sanitized_domain, domain, strlen(domain));
    sanitized_domain[strlen(domain)] = '\0';

    char* sanitized_path = malloc(strlen(path) + 1);
    strncpy(sanitized_path, path, strlen(path));
    sanitized_path[strlen(path)] = '\0';

    char* sanitized_query = malloc(strlen(query) + 1);
    strncpy(sanitized_query, query, strlen(query));
    sanitized_query[strlen(query)] = '\0';

    char* sanitized_url_string = malloc(MAX_URL_LENGTH);
    sprintf(sanitized_url_string, "%s://%s%s?%s", sanitized_protocol, sanitized_domain, sanitized_path, sanitized_query);

    free(protocol);
    free(domain);
    free(path);
    free(query);

    return sanitized_url_string;
}

int main() {
    char* url = "https://www.example.com/path/to/file?query=string#fragment";
    char* sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}