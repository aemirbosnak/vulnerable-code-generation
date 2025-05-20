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
    sscanf(request, "%s %s HTTP/1.1", method, path);
    if (strcmp(method, "POST") == 0) {
        sscanf(request, "%*s %*s HTTP/1.1\r\nContent-Length: %d\r\n", &content_length);
        if (content_length > MAX_REQUEST_SIZE) {
            printf("Error: Content length exceeds maximum allowed size.\n");
            return;
        }
        // Integer overflow vulnerability here
        int buffer_size = content_length + 10; // Vulnerable line
        char *buffer = malloc(buffer_size);
        if (buffer == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        strncpy(buffer, request + strlen(method) + strlen(path) + 23, buffer_size - 1);
        buffer[buffer_size - 1] = '\0';
        printf("Buffer: %s\n", buffer);
        free(buffer);
    } else {
        printf("Unsupported HTTP method.\n");
    }
}

int main() {
    char request[MAX_REQUEST_SIZE];
    printf("Enter HTTP request:\n");
    fgets(request, sizeof(request), stdin);
    parse_request(request);
    return 0;
}
