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

    sscanf(request, "%s %s %s", method, uri, version);

    printf("Method: %s\n", method);
    printf("URI: %s\n", uri);
    printf("Version: %s\n", version);
}

int main() {
    char buffer[BUFFER_SIZE];
    fgets(buffer, sizeof(buffer), stdin);

    parse_http_request(buffer);

    return 0;
}
