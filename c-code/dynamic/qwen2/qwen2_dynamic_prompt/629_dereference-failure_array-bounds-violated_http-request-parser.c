#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void parse_request(char *request) {
    char method[MAX_LINE_LENGTH];
    char uri[MAX_LINE_LENGTH];
    char version[MAX_LINE_LENGTH];

    sscanf(request, "%s %s %s", method, uri, version);

    printf("Method: %s\n", method);
    printf("URI: %s\n", uri);
    printf("Version: %s\n", version);
}

int main() {
    char request[MAX_LINE_LENGTH] = "GET /path/to/resource HTTP/1.1\r\nHost: example.com\r\n";

    // Intentionally overflow the buffer to demonstrate a dereference failure
    strncat(request, "A", sizeof(request));

    parse_request(request);

    return 0;
}
