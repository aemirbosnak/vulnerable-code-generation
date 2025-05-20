//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LEN 2048

typedef struct {
    char *scheme;
    char *user;
    char *password;
    char *host;
    char *port;
    char *path;
} url_t;

void url_free(url_t *url) {
    free(url->scheme);
    free(url->user);
    free(url->password);
    free(url->host);
    free(url->port);
    free(url->path);
    free(url);
}

url_t *url_parse(const char *url_str) {
    char *scheme_end = strchr(url_str, ':');
    if (scheme_end == NULL) {
        return NULL;
    }
    scheme_end++;
    char *host_end = strchr(scheme_end, '/');
    if (host_end == NULL) {
        return NULL;
    }
    *host_end = '\0';
    char *port_str = strchr(scheme_end, ':');
    if (port_str!= NULL) {
        *port_str = '\0';
        port_str++;
    } else {
        port_str = "80";
    }
    url_t *url = malloc(sizeof(url_t));
    url->scheme = strndup(url_str, scheme_end - url_str);
    url->host = strndup(scheme_end, host_end - scheme_end);
    url->port = strdup(port_str);
    url->path = strdup(host_end + 1);
    return url;
}

void url_print(const url_t *url) {
    printf("scheme: %s\n", url->scheme);
    printf("host: %s\n", url->host);
    printf("port: %s\n", url->port);
    printf("path: %s\n", url->path);
}

int main() {
    char input_url[MAX_URL_LEN];
    printf("Enter a URL: ");
    fgets(input_url, MAX_URL_LEN, stdin);
    input_url[strcspn(input_url, "\n")] = '\0';
    url_t *url = url_parse(input_url);
    if (url == NULL) {
        printf("Invalid URL\n");
        return 1;
    }
    url_print(url);
    url_free(url);
    return 0;
}