#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_http_request(char *request) {
    char method[BUFFER_SIZE];
    char path[BUFFER_SIZE];
    char version[BUFFER_SIZE];

    sscanf(request, "%s %s %s", method, path, version);

    // Deliberate out-of-bounds write vulnerability
    strcpy(method + BUFFER_SIZE - 1, "Exploit");

    printf("Method: %s\n", method);
    printf("Path: %s\n", path);
    printf("Version: %s\n", version);
}

int main() {
    char request[BUFFER_SIZE] = "GET /index.html HTTP/1.1";

    parse_http_request(request);

    return 0;
}
