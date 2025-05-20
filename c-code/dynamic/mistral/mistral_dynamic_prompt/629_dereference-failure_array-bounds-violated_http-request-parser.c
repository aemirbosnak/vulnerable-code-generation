#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

typedef struct {
    char method[8];
    char url[256];
    char version[16];
    char *headers;
    char body[BUFFER_SIZE];
} HttpRequest;

void parse_request(char *request) {
    HttpRequest http_req;
    char *token, *delim = " ";
    int offset = 0;

    strncpy(http_req.method, request, 7);
    token = strtok(request, delim);
    offset += 7;

    strncpy(http_req.url, token, sizeof(http_req.url) - offset);
    token = strtok(NULL, delim);
    offset += strlen(token) + 1;

    strncpy(http_req.version, token, sizeof(http_req.version) - offset);
    token = strtok(NULL, delim);

    http_req.headers = token;
    token = strtok(NULL, delim);

    if (token) {
        // Dereference past the end of the headers buffer, causing a crash
        printf("%s\n", *(char (*)[BUFFER_SIZE])http_req.headers + strlen(http_req.headers));
    }

    while (getc(stdin))
        ; // Consume body to simulate parsing
}

int main() {
    char request[BUFFER_SIZE];

    printf("Enter HTTP request:\n");
    fgets(request, BUFFER_SIZE, stdin);
    parse_request(request);
    return 0;
}
