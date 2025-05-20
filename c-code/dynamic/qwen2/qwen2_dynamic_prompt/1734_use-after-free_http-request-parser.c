#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REQUEST_SIZE 1024

typedef struct {
    char *method;
    char *url;
    char *version;
} HttpRequest;

HttpRequest* parse_request(const char *request) {
    HttpRequest *req = (HttpRequest*)malloc(sizeof(HttpRequest));
    req->method = NULL;
    req->url = NULL;
    req->version = NULL;

    const char *space1 = strchr(request, ' ');
    if (!space1) return req;

    req->method = strndup(request, space1 - request);
    const char *space2 = strchr(space1 + 1, ' ');
    if (!space2) return req;

    req->url = strndup(space1 + 1, space2 - space1 - 1);
    req->version = strdup(space2 + 1);

    return req;
}

void process_request(HttpRequest *req) {
    printf("Method: %s\n", req->method);
    printf("URL: %s\n", req->url);
    printf("Version: %s\n", req->version);
}

int main() {
    char buffer[MAX_REQUEST_SIZE];
    fgets(buffer, sizeof(buffer), stdin);

    HttpRequest *req = parse_request(buffer);
    process_request(req);

    // Use-after-free vulnerability
    free(req->method);
    free(req->url);
    free(req->version);

    // Deliberate use after free
    printf("After free: %s\n", req->method); // This line will cause undefined behavior

    return 0;
}
