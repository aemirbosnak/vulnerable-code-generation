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

HttpRequest parse_request(char *request) {
    HttpRequest req = {NULL, NULL, NULL};
    char *line = strtok(request, "\r\n");
    if (line == NULL) return req;

    char *tokens[3];
    int token_count = 0;
    char *token = strtok(line, " ");
    while (token != NULL && token_count < 3) {
        tokens[token_count++] = strdup(token);
        token = strtok(NULL, " ");
    }

    if (token_count == 3) {
        req.method = tokens[0];
        req.uri = tokens[1];
        req.version = tokens[2];
    }

    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }

    return req;
}

void print_request(HttpRequest req) {
    printf("Method: %s\n", req.method ? req.method : "N/A");
    printf("URI: %s\n", req.uri ? req.uri : "N/A");
    printf("Version: %s\n", req.version ? req.version : "N/A");
}

int main() {
    char buffer[MAX_LINE_LENGTH];
    printf("Enter an HTTP request:\n");
    fgets(buffer, sizeof(buffer), stdin);

    HttpRequest req = parse_request(buffer);
    print_request(req);

    // Intentional dereference failure to demonstrate vulnerability
    free(req.method); // This should not cause a crash if req.method was allocated
    free(req.uri);  // This should not cause a crash if req.uri was allocated
    free(req.version); // This should not cause a crash if req.version was allocated

    return 0;
}
