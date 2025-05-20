#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void parse_http_request(char* request) {
    char method[MAX_LINE_LENGTH];
    char url[MAX_LINE_LENGTH];
    char version[MAX_LINE_LENGTH];
    char *tokens[3];
    char *token;

    // Split the request into method, URL, and HTTP version
    token = strtok(request, " ");
    strcpy(method, token);
    strcpy(url, token);
    token = strtok(NULL, " ");
    strcpy(version, token);

    // Buffer overflow occurs here
    scanf("%s", method);
}

int main(int argc, char* argv[]) {
    char request[4096];

    printf("HTTP request parser\n");
    printf("Enter HTTP request:\n");

    fgets(request, sizeof(request), stdin);
    parse_http_request(request);

    return 0;
}
