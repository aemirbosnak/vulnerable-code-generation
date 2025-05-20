//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_host(char *host) {
    int i;
    for (i = 0; i < strlen(host); i++) {
        if (!isalnum(host[i]) && host[i]!= '-') {
            return 0;
        }
    }
    return 1;
}

int is_valid_url(char *url) {
    char *protocol = strtok(url, "://");
    char *host = strtok(NULL, "/");
    if (protocol == NULL || host == NULL) {
        return 0;
    }
    if (strcmp(protocol, "http")!= 0 && strcmp(protocol, "https")!= 0) {
        return 0;
    }
    if (!is_valid_host(host)) {
        return 0;
    }
    return 1;
}

char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    char *protocol = strtok(url, "://");
    char *host = strtok(NULL, "/");
    int host_length = strlen(host);
    int i;
    for (i = 0; i < host_length; i++) {
        if (host[i] == '.') {
            sanitized_url[i] = '.';
        } else if (isalnum(host[i])) {
            sanitized_url[i] = tolower(host[i]);
        } else {
            sanitized_url[i] = '-';
        }
    }
    sanitized_url[host_length] = '\0';
    strcat(sanitized_url, host);
    strcat(sanitized_url, "/");
    return sanitized_url;
}

int main() {
    char input[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", input);
    char *sanitized_url = sanitize_url(input);
    if (is_valid_url(sanitized_url)) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Invalid URL\n");
    }
    free(sanitized_url);
    return 0;
}