#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_REQUEST_SIZE 1024

void parse_request(char *request) {
    char method[16], path[256];
    int content_length = 0;

    // Simulate parsing HTTP request
    sscanf(request, "%s %s", method, path);
    if (strcmp(method, "POST") == 0) {
        sscanf(request, "%*s %*s Content-Length: %d", &content_length);
        if (content_length > MAX_REQUEST_SIZE) {
            printf("Content length too large\n");
            return;
        }
        // Vulnerability: Integer overflow
        int buffer_size = content_length + 10; // Overflow here
        char *buffer = malloc(buffer_size);
        if (buffer == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        strcpy(buffer, request + strlen(method) + strlen(path) + 18); // Potential buffer overflow
        free(buffer);
    } else {
        printf("Unsupported method\n");
    }
}

int main() {
    char request[MAX_REQUEST_SIZE] = "POST /upload HTTP/1.1\r\nContent-Length: 2147483647\r\n\r\n";
    parse_request(request);
    return 0;
}
