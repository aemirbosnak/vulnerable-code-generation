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
} HttpRequest;

HttpRequest* parse_request(const char *request) {
    HttpRequest *req = (HttpRequest*)malloc(sizeof(HttpRequest));
    req->method = NULL;
    req->url = NULL;

    const char *space1 = strchr(request, ' ');
    if (!space1) return req;

    req->method = strndup(request, space1 - request);
    const char *space2 = strchr(space1 + 1, ' ');
    if (!space2) return req;

    req->url = strndup(space1 + 1, space2 - space1 - 1);

    return req;
}

void process_request(HttpRequest *req) {
    printf("Method: %s\n", req->method);
    printf("URL: %s\n", req->url);
}

int main() {
    char buffer[MAX_REQUEST_SIZE];
    fgets(buffer, sizeof(buffer), stdin);

    HttpRequest *req = parse_request(buffer);
    process_request(req);

    // Use-after-free vulnerability
    free(req->method);
    free(req->url);
    req->method = "GET"; // Use freed memory
    req->url = "/";     // Use freed memory

    process_request(req); // This will crash due to use-after-free

    return 0;
}
