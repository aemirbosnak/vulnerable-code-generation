//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_scheme(const char *scheme) {
    // Check if the scheme is valid
    if (strcmp(scheme, "http") == 0 || strcmp(scheme, "https") == 0) {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_host(const char *host) {
    // Check if the host is valid
    if (strlen(host) > 0 && strcmp(host, "localhost")!= 0) {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_port(const char *port) {
    // Check if the port is valid
    if (isdigit(port[0]) && strlen(port) <= 5) {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_query(const char *query) {
    // Check if the query is valid
    if (strlen(query) <= MAX_URL_LENGTH - 1) {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_fragment(const char *fragment) {
    // Check if the fragment is valid
    if (strlen(fragment) <= MAX_URL_LENGTH - 1) {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(const char *url) {
    // Check if the URL is valid
    char *scheme = strtok(url, "://");
    char *host = strtok(NULL, "/");
    char *port = strtok(NULL, "/");
    char *path = strtok(NULL, "?");
    char *query = strtok(NULL, "#");
    char *fragment = strtok(NULL, "");

    if (is_valid_scheme(scheme) && is_valid_host(host) && is_valid_port(port) && is_valid_query(query) && is_valid_fragment(fragment)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    if (is_valid_url(url)) {
        printf("Valid URL\n");
    } else {
        printf("Invalid URL\n");
    }

    return 0;
}