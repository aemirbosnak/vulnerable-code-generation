#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void parse_request(char *request) {
    char buffer[BUFFER_SIZE];
    int port;

    // Simulate parsing an HTTP request to extract the port number
    if (sscanf(request, "GET / HTTP/1.1\r\nHost: %*[^:]:%d", &port) == 1) {
        printf("Port: %d\n", port);
    } else {
        printf("Invalid request format.\n");
    }
}

int main() {
    char request[200];

    printf("Enter an HTTP request:\n");
    fgets(request, sizeof(request), stdin);

    parse_request(request);

    return 0;
}
