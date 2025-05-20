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

void free_request(HttpRequest *req) {
    free(req->method);
    free(req->uri);
    free(req->version);
    free(req);
}

int main() {
    char buffer[MAX_LINE_LENGTH];
    printf("Enter HTTP request: ");
    fgets(buffer, sizeof(buffer), stdin);

    HttpRequest *req = parse_request(buffer);
    printf("Method: %s\n", req->method);
    printf("URI: %s\n", req->uri);
    printf("Version: %s\n", req->version);

    // Use-after-free vulnerability
    free_request(req);
    printf("Method after free: %s\n", req->method); // Use-after-free

    return 0;
}
