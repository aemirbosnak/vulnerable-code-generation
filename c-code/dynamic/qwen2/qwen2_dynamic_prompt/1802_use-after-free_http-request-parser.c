#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REQUEST_SIZE 1024

typedef struct {
    char *method;
    char *uri;
    char *version;
} HttpRequest;

HttpRequest* parse_request(const char *request) {
    HttpRequest *req = (HttpRequest*)malloc(sizeof(HttpRequest));
    req->method = NULL;
    req->uri = NULL;
    req->version = NULL;

    const char *delimiters = " \r\n";
    char *token = strtok((char *)request, delimiters);
    if (token != NULL) {
        req->method = strdup(token);
    }
    token = strtok(NULL, delimiters);
    if (token != NULL) {
        req->uri = strdup(token);
    }
    token = strtok(NULL, delimiters);
    if (token != NULL) {
        req->version = strdup(token);
    }

    return req;
}

void process_request(HttpRequest *req) {
    printf("Method: %s\n", req->method);
    printf("URI: %s\n", req->uri);
    printf("Version: %s\n", req->version);

    // Simulate processing time
    sleep(1);
}

int main() {
    char buffer[MAX_REQUEST_SIZE];
    printf("Enter HTTP request:\n");
    fgets(buffer, sizeof(buffer), stdin);

    HttpRequest *req = parse_request(buffer);
    process_request(req);

    // Free allocated memory
    free(req->method);
    free(req->uri);
    free(req->version);
    free(req);

    // Use-after-free vulnerability
    printf("Method after free: %s\n", req->method); // This line will cause undefined behavior

    return 0;
}
