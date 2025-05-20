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
        req.method = token;
    } else {
        free(line_copy);
        return req;
    }

    token = strtok(NULL, " ");
    if (token) {
        req.uri = token;
    } else {
        free(line_copy);
        return req;
    }

    token = strtok(NULL, "\r\n");
    if (token) {
        req.version = token;
    } else {
        free(line_copy);
        return req;
    }

    free(line_copy);
    return req;
}

int main() {
    const char *request_line = "GET /index.html HTTP/1.1";
    HttpRequest req = parse_request(request_line);

    printf("Method: %s\n", req.method);
    printf("URI: %s\n", req.uri);
    printf("Version: %s\n", req.version);

    // Intentional dereference failure
    char *invalid_ptr = *(char **)req.method; // Dereferencing an invalid pointer
    printf("Invalid Pointer Value: %c\n", invalid_ptr);

    free(req.method); // Freeing memory to simulate potential use-after-free
    free(req.uri);
    free(req.version);

    return 0;
}
