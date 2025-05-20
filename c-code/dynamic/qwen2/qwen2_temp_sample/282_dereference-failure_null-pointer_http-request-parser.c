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

HttpRequest parse_request(char *request) {
    HttpRequest req = {NULL, NULL, NULL};
    char *token;

    token = strtok(request, " ");
    if (token != NULL) {
        req.method = strdup(token);
    }

    token = strtok(NULL, " ");
    if (token != NULL) {
        req.url = strdup(token);
    }

    token = strtok(NULL, "\r\n");
    if (token != NULL) {
        req.version = strdup(token);
    }

    return req;
}

int main() {
    char *http_request = "GET /index.html HTTP/1.1\r\nHost: www.example.com\r\n";
    HttpRequest parsed_req = parse_request(http_request);

    printf("Method: %s\n", parsed_req.method);
    printf("URL: %s\n", parsed_req.url);
    printf("Version: %s\n", parsed_req.version);

    free(parsed_req.method);
    free(parsed_req.url);
    free(parsed_req.version);

    return 0;
}
