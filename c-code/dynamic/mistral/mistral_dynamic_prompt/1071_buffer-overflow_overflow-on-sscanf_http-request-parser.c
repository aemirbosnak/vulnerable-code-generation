#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 2048

void parse_http_request(char *buffer) {
    char method[8], url[256], version[16];
    int http_version_major, http_version_minor;
    char request[BUFFER_SIZE];

    sscanf(buffer, "%s %s %s HTTP/1.1\n%s", method, url, version, request);

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("Version: %s\n", version);
    printf("Request:\n%s", request);

    memset(request, '\0', BUFFER_SIZE);
    strcat(request, "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ); // overflow the request buffer
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];
    fgets(input, BUFFER_SIZE, stdin);
    parse_http_request(input);

    return 0;
}
