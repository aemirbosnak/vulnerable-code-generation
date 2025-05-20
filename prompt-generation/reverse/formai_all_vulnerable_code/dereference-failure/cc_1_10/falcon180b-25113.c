//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

struct url_t {
    char *scheme;
    char *username;
    char *password;
    char *host;
    char *port;
    char *path;
    char *query;
    char *fragment;
};

void url_sanitize(char *url, struct url_t *parsed_url) {
    char *scheme_start = strstr(url, "://");
    if (!scheme_start) {
        scheme_start = url;
    } else {
        scheme_start += 3;
    }

    parsed_url->scheme = strndup(scheme_start, strcspn(scheme_start, "/?#"));

    char *path_start = strstr(url, "/");
    if (!path_start) {
        path_start = url + strlen(url);
    } else {
        path_start += 1;
    }

    char *query_start = strstr(url, "?");
    if (!query_start) {
        query_start = path_start;
    } else {
        query_start += 1;
    }

    char *fragment_start = strstr(url, "#");
    if (!fragment_start) {
        fragment_start = path_start;
    } else {
        fragment_start += 1;
    }

    parsed_url->host = strndup(scheme_start, path_start - scheme_start);
    parsed_url->path = strndup(path_start, query_start - path_start);
    parsed_url->query = strndup(query_start, fragment_start - query_start);
    parsed_url->fragment = strndup(fragment_start, strlen(fragment_start));

    char *username_password_start = strstr(parsed_url->host, "@");
    if (username_password_start) {
        *username_password_start = '\0';
        parsed_url->username = strdup(parsed_url->host);
        parsed_url->password = strdup(username_password_start + 1);
    } else {
        parsed_url->username = NULL;
        parsed_url->password = NULL;
    }

    char *port_start = strstr(parsed_url->host, ":");
    if (port_start) {
        *port_start = '\0';
        parsed_url->port = strdup(port_start + 1);
    } else {
        parsed_url->port = NULL;
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    struct url_t parsed_url;
    url_sanitize(url, &parsed_url);

    printf("Scheme: %s\n", parsed_url.scheme);
    printf("Username: %s\n", parsed_url.username);
    printf("Password: %s\n", parsed_url.password);
    printf("Host: %s\n", parsed_url.host);
    printf("Port: %s\n", parsed_url.port);
    printf("Path: %s\n", parsed_url.path);
    printf("Query: %s\n", parsed_url.query);
    printf("Fragment: %s\n", parsed_url.fragment);

    return 0;
}