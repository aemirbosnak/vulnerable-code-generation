#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void http_parser(char *buffer) {
    char method[8], url[256], version[16];
    char request[BUFFER_SIZE];
    char *token;

    strcpy(request, buffer);

    // Parse HTTP request
    token = strtok(request, " ");
    strncpy(method, token, strlen(token) > 7 ? 7 : strlen(token));
    method[strlen(token)] = '\0';

    token = strtok(NULL, " ");
    strncpy(url, token, strlen(token) > 255 ? 255 : strlen(token));
    url[strlen(token)] = '\0';

    token = strtok(NULL, "\r\n");
    strncpy(version, token, strlen(token) > 15 ? 15 : strlen(token));
    version[strlen(token)] = '\0';

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("Version: %s\n", version);

    // Buffer overflow vulnerability
    char buffer2[BUFFER_SIZE];
    fscanf(stdin, "%s", buffer2);
}

int main() {
    char buffer[BUFFER_SIZE];
    printf("Enter an HTTP request:\n");
    fgets(buffer, BUFFER_SIZE, stdin);
    http_parser(buffer);

    return 0;
}
