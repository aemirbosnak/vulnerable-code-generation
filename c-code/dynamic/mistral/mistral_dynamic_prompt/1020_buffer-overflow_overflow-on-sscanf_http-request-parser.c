#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define HEADER_LEN 512

void parse_http_request(char *buffer) {
    char method[10], uri[HEADER_LEN], version[10];
    int major, minor;

    sscanf(buffer, "%s %s %s\n", method, uri, version);
    sscanf(uri, "http://%s", method);
    sscanf(buffer, "%*d.%*d ", &major);
    sscanf(version, "%*d.%d", &minor);

    printf("Method: %s\n", method);
    printf("URI: %s\n", uri);
    printf("HTTP version: %s\n", version);
    printf("Major version: %d\n", major);
    printf("Minor version: %d\n", minor);
}

int main(int argc, char *argv[]) {
    char *request = malloc(BUFFER_SIZE);

    if (request) {
        printf("Enter HTTP request:\n");
        fgets(request, BUFFER_SIZE, stdin);

        parse_http_request(request);
        free(request);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
