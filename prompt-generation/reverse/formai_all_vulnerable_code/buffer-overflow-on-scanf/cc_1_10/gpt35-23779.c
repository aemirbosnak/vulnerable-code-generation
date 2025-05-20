//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 1000

bool is_valid_scheme(char *str) {
    char valid_schemes[][8] = {"http://", "https://", "ftp://", "ssh://"};
    int i, num_schemes = sizeof(valid_schemes) / sizeof(valid_schemes[0]);
    for (i = 0; i < num_schemes; i++) {
        if (strncmp(str, valid_schemes[i], strlen(valid_schemes[i])) == 0) {
            return true;
        }
    }
    return false;
}

bool is_valid_hostname(char *str) {
    /* Valid hostname should only contain letters, digits, separator ".", and hyphen "-" */
    int len = strlen(str), i;
    if (len > 255) {
        return false;
    }
    for (i = 0; i < len; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || (str[i] == '-') || (str[i] == '.'))) {
            return false;
        }
    }
    return true;
}

bool is_valid_port(char *str) {
    int len = strlen(str), i;
    for (i = 0; i < len; i++) {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            return false;
        }
    }
    int port = atoi(str);
    if (port < 1 || port > 65535) {
        return false;
    }
    return true;
}

char *sanitize_url(char *url) {
    /*
    URL Syntax:
    [<scheme>:][//]<hostname>[:<port>][/<path>][?<query>]

    Examples:
    http://www.example.com:8080/index.html?page=1
    https://example.org/image.png

    Scheme and hostname are required. Port, path and query are optional.
    */
    char scheme[MAX_URL_LENGTH], hostname[MAX_URL_LENGTH], port[MAX_URL_LENGTH], path[MAX_URL_LENGTH], query[MAX_URL_LENGTH];
    memset(scheme, 0, MAX_URL_LENGTH);
    memset(hostname, 0, MAX_URL_LENGTH);
    memset(port, 0, MAX_URL_LENGTH);
    memset(path, 0, MAX_URL_LENGTH);
    memset(query, 0, MAX_URL_LENGTH);
    int i = 0, j = 0, state = 0;
    while (url[i] != '\0') {
        switch (state) {
            case 0:
                /* Parsing scheme */
                if (url[i] == ':' && url[i+1] == '/' && url[i+2] == '/') {
                    /* valid scheme found, move to next state */
                    state = 1;
                    i += 3;
                }
                else {
                    /* Invalid scheme, return NULL */
                    return NULL;
                }
                break;
            case 1:
                /* Parsing hostname */
                if (url[i] == ':') {
                    /* Port detected, move to next state */
                    state = 2;
                    j = 0;
                }
                else if (url[i] == '/') {
                    /* End of hostname, move to next state */
                    state = 3;
                    j = 0;
                }
                else if (url[i] == '?') {
                    /* End of hostname, skip port and path */
                    state = 4;
                    j = 0;
                }
                else {
                    hostname[j] = url[i];
                    j++;
                }
                break;
            case 2:
                /* Parsing port */
                if (url[i] == '/') {
                    /* End of port, move to next state */
                    state = 3;
                    j = 0;
                }
                else if (url[i] == '?') {
                    /* End of port, skip path */
                    state = 4;
                    j = 0;
                }
                else {
                    port[j] = url[i];
                    j++;
                }
                break;
            case 3:
                /* Parsing path */
                if (url[i] == '?') {
                    /* End of path, move to next state */
                    state = 4;
                    j = 0;
                }
                else {
                    path[j] = url[i];
                    j++;
                }
                break;
            case 4:
                /* Parsing query */
                query[j] = url[i];
                j++;
                break;
        }
        i++;
    }

    /* Validate scheme and hostname */
    if (!is_valid_scheme(scheme) || !is_valid_hostname(hostname)) {
        return NULL;
    }

    /* Validate port */
    if (strlen(port) > 0 && !is_valid_port(port)) {
        return NULL;
    }

    /* Concatenate sanitized URL */
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    memset(sanitized_url, 0, MAX_URL_LENGTH);
    strcat(sanitized_url, scheme);
    strcat(sanitized_url, hostname);
    if (strlen(port) > 0) {
        strcat(sanitized_url, ":");
        strcat(sanitized_url, port);
    }
    strcat(sanitized_url, "/");
    strcat(sanitized_url, path);
    if (strlen(query) > 0) {
        strcat(sanitized_url, "?");
        strcat(sanitized_url, query);
    }

    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    char *sanitized_url = sanitize_url(url);
    if (sanitized_url != NULL) {
        printf("Sanitized URL: %s\n", sanitized_url);
        free(sanitized_url);
    }
    else {
        printf("Invalid URL\n");
    }

    return 0;
}