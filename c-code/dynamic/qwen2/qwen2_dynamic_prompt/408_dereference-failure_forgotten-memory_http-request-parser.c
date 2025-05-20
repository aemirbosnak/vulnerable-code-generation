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

HttpRequest* parse_request(char *request) {
    HttpRequest *req = malloc(sizeof(HttpRequest));
    if (!req) return NULL;

    req->method = strtok(request, " ");
    req->uri = strtok(NULL, " ");
    req->version = strtok(NULL, "\r\n");

    return req;
}

void free_request(HttpRequest *req) {
    free(req->method);
    free(req->uri);
    free(req->version);
    free(req);
}

int main() {
    char buffer[MAX_LINE_LENGTH];
    printf("Enter an HTTP request:\n");
    fgets(buffer, sizeof(buffer), stdin);

    HttpRequest *req = parse_request(buffer);
    if (!req) {
        fprintf(stderr, "Failed to allocate memory for request.\n");
        return 1;
    }

    printf("Method: %s\n", req->method);
    printf("URI: %s\n", req->uri);
    printf("Version: %s\n", req->version);

    // Intentional dereference failure (forgotten memory)
    // Freeing req twice
    free_request(req);
    free_request(req); // This line causes the vulnerability

    return 0;
}
