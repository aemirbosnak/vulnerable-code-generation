#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_REQUEST_SIZE 1024

typedef struct {
    char method[8];
    char path[256];
    int port;
} HttpRequest;

int parse_request(char *request, HttpRequest *parsed_request) {
    char *line = strtok(request, "\r\n");
    if (!line) return -1; // No first line

    // Parse method and path
    sscanf(line, "%s %s", parsed_request->method, parsed_request->path);

    // Find host header
    while ((line = strtok(NULL, "\r\n")) != NULL) {
        if (strncmp(line, "Host:", 5) == 0) {
            char *host_port = strchr(line, ':');
            if (host_port) {
                *host_port++ = '\0';
                parsed_request->port = atoi(host_port);
            } else {
                parsed_request->port = 80;
            }
            break;
        }
    }

    return 0;
}

int main() {
    char request[MAX_REQUEST_SIZE] = "GET /index.html HTTP/1.1\r\nHost: example.com:8080\r\n\r\n";
    HttpRequest parsed_request;

    if (parse_request(request, &parsed_request) != 0) {
        printf("Failed to parse request.\n");
        return 1;
    }

    printf("Method: %s\n", parsed_request.method);
    printf("Path: %s\n", parsed_request.path);
    printf("Port: %d\n", parsed_request.port);

    // Deliberate invalid pointer dereference
    char *invalid_ptr = NULL;
    printf("%s\n", invalid_ptr); // This will cause a segmentation fault

    return 0;
}
