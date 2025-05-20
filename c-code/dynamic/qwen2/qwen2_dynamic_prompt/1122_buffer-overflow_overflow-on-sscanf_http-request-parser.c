#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REQUEST_SIZE 1024

void parse_request(char *request) {
    char method[16];
    char path[256];
    int port;

    if (sscanf(request, "%s %s %*s", method, path) != 2) {
        fprintf(stderr, "Invalid request format\n");
        return;
    }

    if (strcmp(method, "GET") == 0) {
        printf("Method: GET\n");
    } else if (strcmp(method, "POST") == 0) {
        printf("Method: POST\n");
    } else {
        fprintf(stderr, "Unsupported method\n");
        return;
    }

    if (sscanf(path, "/port=%d", &port) == 1) {
        printf("Port: %d\n", port);
    } else {
        printf("No port specified\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <HTTP request>\n", argv[0]);
        return 1;
    }

    char request[MAX_REQUEST_SIZE];
    strncpy(request, argv[1], sizeof(request) - 1);
    request[sizeof(request) - 1] = '\0';

    parse_request(request);

    return 0;
}
