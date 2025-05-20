#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 4096

void parse_http_request(char* request) {
    char method[8], url[256], version[16];
    int http_version;

    if (sscanf(request, "%s %s %s ", method, url, version) != 3) {
        printf("Invalid HTTP request format\n");
        return;
    }

    http_version = atoi(version);
    if (http_version < 1 || http_version > 99) {
        printf("Invalid HTTP version\n");
        return;
    }

    // Buffer overflow vulnerability in the following line, the buffer for 'headers' has a size of 8 characters,
    // but 'Content-Length' header value is not checked or validated, allowing for possible buffer overflow

    char headers[8];
    if (sscanf(request, "%*s %*s %s ", headers) != 1) {
        printf("Missing headers\n");
        return;
    }
}

int main() {
    char buffer[MAX_LINE];

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        parse_http_request(buffer);
    }

    return 0;
}
