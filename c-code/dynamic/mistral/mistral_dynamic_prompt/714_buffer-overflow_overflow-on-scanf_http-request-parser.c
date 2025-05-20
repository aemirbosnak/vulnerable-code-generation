#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void parse_request(char *buffer) {
    char method[8], uri[256], version[16];
    char *params;

    sscanf(buffer, "%s %s %s", method, uri, version);

    // Excessive length of URI to trigger buffer overflow
    params = strchr(uri, ' ') + BUFFER_SIZE - 1;
    strcpy(params, "extra_data");
}

int main(int argc, char **argv) {
    char request[1024];

    printf("HTTP Request Parser\n");
    printf("Enter HTTP request:\n");
    fgets(request, sizeof(request), stdin);

    parse_request(request);

    return 0;
}
