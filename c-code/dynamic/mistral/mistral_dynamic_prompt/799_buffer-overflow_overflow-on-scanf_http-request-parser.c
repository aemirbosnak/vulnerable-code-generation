#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _HTTPRequest {
    char method[10];
    char uri[256];
    char version[16];
    char headers[4096];
    char body[65536];
} HTTPRequest;

int main(int argc, char *argv[]) {
    HTTPRequest req;
    size_t bufsize = sizeof(HTTPRequest);

    printf("HTTP request parsing tool v1.0\n");
    printf("Enter HTTP request: ");

    fgets(req.method, sizeof(req.method), stdin);
    fgets(req.uri, sizeof(req.uri), stdin);
    fgets(req.version, sizeof(req.version), stdin);

    gets(req.headers); // INTENTIONALLY vulnerable to buffer overflow
    fgets(req.body, sizeof(req.body), stdin);

    printf("\nParsed request:\n");
    printf("Method: %s\n", req.method);
    printf("URI: %s\n", req.uri);
    printf("Version: %s\n", req.version);
    printf("Headers:\n%s\n", req.headers);
    printf("Body: %s\n", req.body);

    return 0;
}
