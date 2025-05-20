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

HttpRequest parse_request(char *buffer) {
    HttpRequest req = {NULL, NULL, NULL};
    char *line = strtok(buffer, "\r\n");
    if (line == NULL) return req;

    char *tokens[3];
    int token_count = 0;
    char *token = strtok(line, " ");
    while (token != NULL && token_count < 3) {
        tokens[token_count++] = token;
        token = strtok(NULL, " ");
    }

    if (token_count == 3) {
        req.method = strdup(tokens[0]);
        req.uri = strdup(tokens[1]);
        req.version = strdup(tokens[2]);
    }

    return req;
}

void free_request(HttpRequest *req) {
    free(req->method);
    free(req->uri);
    free(req->version);
}

int main() {
    char buffer[MAX_LINE_LENGTH] = "GET /index.html HTTP/1.1\r\nHost: example.com\r\n";
    HttpRequest req = parse_request(buffer);

    printf("Method: %s\n", req.method);
    printf("URI: %s\n", req.uri);
    printf("Version: %s\n", req.version);

    free_request(&req);

    // Intentional dereference failure
    char *ptr = NULL;
    printf("%s\n", ptr); // This will cause a segmentation fault

    return 0;
}
