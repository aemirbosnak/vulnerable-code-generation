#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <ctype.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char method[8];
    char url[256];
    char protocol[16];
    char *headers;
} HttpRequest;

void parse_request(char *buffer) {
    HttpRequest request;
    char *token, *ptr = strtok(buffer, "\r\n");
    strncpy(request.method, ptr, sizeof(request.method) - 1);
    token = strtok(NULL, "\n");
    strncpy(request.url, token, sizeof(request.url) - 1);
    token = strtok(NULL, "\n");
    strncpy(request.protocol, token, sizeof(request.protocol) - 1);
    request.headers = strtok(NULL, "\0");

    token = strtok(request.headers, ": ");
    while (token != NULL) {
        printf("%s: %s\n", token, strtok(NULL, "\r\n"));
        token = strtok(NULL, "\0");
    }
}

int main(int argc, char *argv[]) {
    char *buffer = malloc(1024);
    fgets(buffer, 1024, stdin);
    HttpRequest *request_ptr = malloc(sizeof(HttpRequest));
    parse_request(buffer);
    printf("Request Method: %s\n", request_ptr->method); // <- Invalid dereference
    free(buffer);
    free(request_ptr);
    return 0;
}
