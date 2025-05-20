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
    HttpRequest *req = (HttpRequest*)malloc(sizeof(HttpRequest));
    req->method = NULL;
    req->uri = NULL;
    req->version = NULL;

    char *line = strtok(request, "\r\n");
    if (line != NULL) {
        char *space1 = strchr(line, ' ');
        char *space2 = strchr(space1 + 1, ' ');

        if (space1 != NULL && space2 != NULL) {
            req->method = strndup(line, space1 - line);
            req->uri = strndup(space1 + 1, space2 - space1 - 1);
            req->version = strdup(space2 + 1);
        }
    }

    return req;
}

void process_request(HttpRequest *req) {
    printf("Method: %s\n", req->method);
    printf("URI: %s\n", req->uri);
    printf("Version: %s\n", req->version);

    // Use-after-free vulnerability
    free(req->method);
    free(req->uri);
    free(req->version);

    // Accessing freed memory
    printf("Method after free: %s\n", req->method);
    printf("URI after free: %s\n", req->uri);
    printf("Version after free: %s\n", req->version);
}

int main() {
    char request[MAX_LINE_LENGTH];
    fgets(request, sizeof(request), stdin);

    HttpRequest *req = parse_request(request);
    process_request(req);

    free(req); // Freeing the pointer to avoid dangling pointer issues

    return 0;
}
