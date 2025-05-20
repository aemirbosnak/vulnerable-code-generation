//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <err.h>
#include <alloca.h>
#include <ctype.h>
#include <stdint.h>

typedef struct url_s {
    char scheme[16];
    char *user;
    char *pass;
    char host[256];
    char path[1024];
    int port;
} url_t;

void sanitize_url(url_t *url) {
    int i, j;

    // Sanitize scheme
    for (i = 0; i < strlen(url->scheme) && isalnum(url->scheme[i]); i++);
    if (i == strlen(url->scheme)) {
        strncpy(url->scheme, "http", strlen("http") + 1);
    }

    // Sanitize user and pass
    for (i = 0; url->user; i++) {
        if (url->user[i] == ':') {
            url->user[i] = '\0';
            for (j = i + 1; url->pass && isalnum(url->pass[j]); j++);
            url->pass[j] = '\0';
            break;
        }
    }

    // Sanitize host and path
    for (i = 0; i < strlen(url->host) && isalnum(url->host[i]) || url->host[i] == '.' || url->host[i] == '-'; i++);
    if (i != strlen(url->host)) {
        warn("Invalid host: %s", url->host);
        memset(url, 0, sizeof(url_t));
        return;
    }

    for (i = 0; url->path[i]; i++) {
        if (url->path[i] == ':' || url->path[i] == ';' || url->path[i] == '\\' || url->path[i] == '/' || url->path[i] == '?' || url->path[i] == '=' || url->path[i] == '+') {
            url->path[i] = '\0';
            break;
        }
    }

    // Sanitize port
    if (url->port < 0 || url->port > 65535) {
        url->port = -1;
    }
}

int main(int argc, char **argv) {
    url_t url;
    char *input = alloca(1024);

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(input, argv[1]);
    sscanf(input, "%%%[^:]:%s%s%s:%d%s", url.scheme, &url.user, &url.pass, &url.port, url.path);

    sanitize_url(&url);

    printf("Scheme: %s\n", url.scheme);
    printf("User: %s\n", url.user ? url.user : "<none>");
    printf("Password: %s\n", url.pass ? url.pass : "<none>");
    printf("Host: %s\n", url.host);
    printf("Port: %d\n", url.port >= 0 ? url.port : "<none>");
    printf("Path: %s\n", url.path);

    return EXIT_SUCCESS;
}