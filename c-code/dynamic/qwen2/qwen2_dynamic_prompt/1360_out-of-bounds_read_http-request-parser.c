#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_REQUEST_SIZE 1024

void parse_http_request(char *request) {
    char method[16];
    char path[256];
    char version[16];

    sscanf(request, "%s %s %s", method, path, version);

    if (strcmp(method, "GET") != 0 && strcmp(method, "POST") != 0) {
        return;
    }

    // Out-of-bounds read vulnerability
    printf("Method: %s\nPath: %s\nVersion: %s\n", method, path, version);
}

int main() {
    char request[MAX_REQUEST_SIZE];

    printf("Enter an HTTP request:\n");
    fgets(request, sizeof(request), stdin);

    parse_http_request(request);

    return 0;
}
