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

    if (sscanf(request, "%9s %9s %9s", method, path, version) != 3) {
        printf("Invalid request format\n");
        return;
    }

    printf("Method: %s\n", method);
    printf("Path: %s\n", path);
    printf("Version: %s\n", version);
}

int main() {
    char request[200] = "GET /path/to/resource HTTP/1.1";

    // Intentionally crafting an overflow by setting a very large path
    memset(request + strlen(request), 'A', 100);

    parse_request(request);

    return 0;
}
