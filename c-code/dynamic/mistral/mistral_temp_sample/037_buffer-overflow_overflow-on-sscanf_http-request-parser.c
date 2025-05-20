#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_request(char *buffer) {
    char method[8], url[256], version[16];
    int http_version;
    char request_body[BUFFER_SIZE];

    sscanf(buffer, "%s %s %s %n", method, url, version, &http_version);
    strncat(url, buffer + http_version, BUFFER_SIZE - strlen(url) - http_version);
    sscanf(buffer + http_version, "%s", request_body);

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("Version: %s\n", version);
    printf("Request Body: %s\n", request_body);
}

int main() {
    char request[BUFFER_SIZE * 10];
    printf("Enter a HTTP request:\n");
    fgets(request, BUFFER_SIZE * 10, stdin);

    parse_request(request);
    return 0;
}
