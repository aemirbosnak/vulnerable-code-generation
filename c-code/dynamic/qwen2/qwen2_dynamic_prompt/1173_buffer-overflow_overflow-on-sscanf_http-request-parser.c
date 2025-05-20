#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_REQUEST_SIZE 1024

void parse_request(char *request) {
    char method[16], path[256], version[16];
    if (sscanf(request, "%s %s %s", method, path, version) != 3) {
        return;
    }
    printf("Method: %s\nPath: %s\nVersion: %s\n", method, path, version);
}

int main() {
    char request[MAX_REQUEST_SIZE];
    while (fgets(request, sizeof(request), stdin)) {
        parse_request(request);
    }
    return 0;
}
