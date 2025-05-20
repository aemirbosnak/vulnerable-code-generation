#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *method;
    char *uri;
    char *version;
} HttpRequest;

HttpRequest parse_request(const char *request_line) {
    HttpRequest req = {NULL, NULL, NULL};
    char *line_copy = strdup(request_line);
    if (!line_copy) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(line_copy, " ");
    if (token) {
        req.method = strdup(token);
    }
    token = strtok(NULL, " ");
    if (token) {
        req.uri = strdup(token);
    }
    token = strtok(NULL, "\r\n");
    if (token) {
        req.version = strdup(token);
    }

    free(line_copy);
    return req;
}

void print_request(HttpRequest req) {
    printf("Method: %s\n", req.method ? req.method : "N/A");
    printf("URI: %s\n", req.uri ? req.uri : "N/A");
    printf("Version: %s\n", req.version ? req.version : "N/A");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <HTTP_REQUEST>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *request_line = argv[1];
    HttpRequest req = parse_request(request_line);

    print_request(req);

    // Intentional null pointer dereference to demonstrate vulnerability
    if (req.method) {
        free(req.method);
    }
    if (req.uri) {
        free(req.uri);
    }
    if (req.version) {
        free(req.version);
    }

    return EXIT_SUCCESS;
}
