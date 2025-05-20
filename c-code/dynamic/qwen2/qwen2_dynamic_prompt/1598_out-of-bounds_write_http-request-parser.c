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

    // Vulnerability: Out-of-bounds write due to insufficient buffer size
    strcpy(method, "GET");
    strcpy(path, "/vulnerable");
    strcpy(version, "HTTP/1.1");

    printf("Method: %s\n", method);
    printf("Path: %s\n", path);
    printf("Version: %s\n", version);
}

int main() {
    char request[BUFFER_SIZE] = "POST /exploit HTTP/1.1\r\nHost: vulnerable.com\r\n";

    parse_http_request(request);

    return 0;
}
