#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_REQUEST_SIZE 1024

void parse_request(char *request) {
    char method[16];
    char path[256];
    char version[16];

    sscanf(request, "%s %s %s", method, path, version);

    // Vulnerability: Out-of-bounds write due to insufficient buffer size
    strcpy(path, "http://example.com/");

    printf("Method: %s\n", method);
    printf("Path: %s\n", path);
    printf("Version: %s\n", version);
}

int main() {
    char request[MAX_REQUEST_SIZE];

    printf("Enter HTTP request:\n");
    fgets(request, sizeof(request), stdin);

    parse_request(request);

    return 0;
}
