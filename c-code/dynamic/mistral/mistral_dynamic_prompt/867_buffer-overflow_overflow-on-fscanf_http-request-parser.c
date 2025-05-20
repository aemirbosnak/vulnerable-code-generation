#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void http_request_parser(char *buf) {
    char method[8], url[256], version[9];
    char request[1024];
    char *token;

    // OVERFLOW POTENTIAL: No bounds check on fscanf for 'version' array
    fscanf(buf, "%s %s %s\n%s", method, url, version, request);

    // More parsing logic...
    // (I've intentionally omitted it for brevity)

    printf("Method: %s\nURL: %s\nVersion: %s\nRequest: %s\n", method, url, version, request);
}

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage: %s <HTTP request>\n", argv[0]);
        return 1;
    }

    strcpy(buffer, argv[1]);
    http_request_parser(buffer);

    return 0;
}
