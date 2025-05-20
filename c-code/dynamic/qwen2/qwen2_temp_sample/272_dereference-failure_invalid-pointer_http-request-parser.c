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

void parseRequest(const char *request, HttpRequest *httpRequest) {
    const char *method = strtok(request, " ");
    if (!method) return;

    strcpy(httpRequest->method, method);

    const char *path = strtok(NULL, " ");
    if (!path) return;

    strcpy(httpRequest->path, path);

    const char *portStr = strtok(NULL, " ");
    if (portStr && !strncmp(portStr, ":", 1)) {
        httpRequest->port = atoi(portStr + 1);
    } else {
        httpRequest->port = 80; // Default to HTTP port
    }
}

int main() {
    char buffer[MAX_REQUEST_SIZE];
    printf("Enter an HTTP request: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character

    HttpRequest req;
    parseRequest(buffer, &req);

    if (strcmp(req.method, "GET") != 0) {
        printf("Invalid HTTP method\n");
        return 1;
    }

    if (req.port == 0) {
        printf("Port number not specified\n");
        return 1;
    }

    // Deliberate invalid pointer dereference
    const char *invalidPtr = NULL;
    printf("%s %s:%d\n", req.method, req.path, req.port);
    printf("This is an intentional dereference failure example\n");

    // Dereferencing null pointer
    printf("Dereferencing invalid pointer: %s\n", invalidPtr); // This will crash

    return 0;
}
