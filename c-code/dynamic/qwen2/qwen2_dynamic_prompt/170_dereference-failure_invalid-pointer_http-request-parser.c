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
    char version[16];
} HttpRequest;

void parse_request(char *request, HttpRequest *parsed_request) {
    char *token;
    token = strtok(request, " ");
    if (token != NULL) {
        strncpy(parsed_request->method, token, sizeof(parsed_request->method));
    }

    token = strtok(NULL, " ");
    if (token != NULL) {
        strncpy(parsed_request->path, token, sizeof(parsed_request->path));
    }

    token = strtok(NULL, "\r\n");
    if (token != NULL) {
        strncpy(parsed_request->version, token, sizeof(parsed_request->version));
    }
}

int main() {
    char request[MAX_REQUEST_SIZE];
    HttpRequest parsed_request;

    printf("Enter an HTTP request: ");
    fgets(request, sizeof(request), stdin);

    parse_request(request, &parsed_request);

    printf("Method: %s\n", parsed_request.method);
    printf("Path: %s\n", parsed_request.path);
    printf("Version: %s\n", parsed_request.version);

    return 0;
}
