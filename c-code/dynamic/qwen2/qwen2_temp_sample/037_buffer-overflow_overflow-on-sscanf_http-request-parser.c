#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_http_request(char *request) {
    char method[BUFFER_SIZE];
    char uri[BUFFER_SIZE];
    char version[BUFFER_SIZE];

    if (sscanf(request, "%s %s %s", method, uri, version) != 3) {
        return;
    }

    printf("Method: %s\n", method);
    printf("URI: %s\n", uri);
    printf("Version: %s\n", version);
}

int main() {
    char request[BUFFER_SIZE] = "GET /path/to/resource HTTP/1.1\r\nHost: example.com\r\n";

    // Intentionally crafting an overflow by appending more data to the request
    strncat(request, "A", sizeof(request) - strlen(request) - 1);

    parse_http_request(request);

    return 0;
}
