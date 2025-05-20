#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_REQUEST_SIZE 1024

void parse_request(char *request) {
    char method[16];
    char url[256];
    char version[16];

    sscanf(request, "%s %s %s", method, url, version);

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("Version: %s\n", version);
}

int main() {
    char request[MAX_REQUEST_SIZE];

    // Simulate receiving an HTTP request
    strcpy(request, "GET /path/to/resource HTTP/1.1\r\nHost: example.com\r\n");

    parse_request(request);

    return 0;
}
