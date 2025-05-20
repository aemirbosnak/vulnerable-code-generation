#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void parse_request(char *request) {
    char method[10];
    char path[256];
    int port;

    // Vulnerable fscanf call
    if (sscanf(request, "%9s %255s %*s", method, path) != 2) {
        fprintf(stderr, "Invalid request format\n");
        return;
    }

    printf("Method: %s\n", method);
    printf("Path: %s\n", path);

    // Simulate parsing port from request
    if (sscanf(path, ":%d", &port) == 1) {
        printf("Port: %d\n", port);
    } else {
        printf("No port specified\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <HTTP_REQUEST>\n", argv[0]);
        return 1;
    }

    parse_request(argv[1]);

    return 0;
}
