//Falcon2-11B DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize URLs
void sanitize_url(char *url) {
    char *result = strdup(url);

    char *protocol_part = strchr(result, ':');
    if (protocol_part!= NULL) {
        *protocol_part = '\0';
    }

    char *host_part = strchr(result, '/');
    if (host_part!= NULL) {
        *host_part = '\0';
    }

    char *port_part = strchr(result, ':');
    if (port_part!= NULL) {
        *port_part = '\0';
    }

    char *path_part = strchr(result, '/');
    if (path_part!= NULL) {
        *path_part = '\0';
    }

    char *query_part = strchr(result, '?');
    if (query_part!= NULL) {
        *query_part = '\0';
    }

    char *fragment_part = strchr(result, '#');
    if (fragment_part!= NULL) {
        *fragment_part = '\0';
    }

    printf("Sanitized URL: %s\n", result);
}

int main() {
    char url[256];

    printf("Enter a URL: ");
    scanf("%s", url);

    sanitize_url(url);

    return 0;
}