#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void parse_request(char *request) {
    char method[BUFFER_SIZE];
    char path[BUFFER_SIZE];
    char version[BUFFER_SIZE];

    sscanf(request, "%s %s %s", method, path, version);
}

int main() {
    char request[200];
    printf("Enter HTTP request: ");
    fgets(request, sizeof(request), stdin);

    parse_request(request);

    return 0;
}
