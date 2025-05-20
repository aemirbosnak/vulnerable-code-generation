#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <ctype.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 8192

void parse_request_line(char *request_line) {
    char method[8], uri[256], version[16];
    char *token, *next_token;

    token = strtok(request_line, " ");
    strncpy(method, token, sizeof(method) - 1);
    method[sizeof(method) - 1] = '\0';

    token = strtok(NULL, " ");
    strncpy(uri, token, sizeof(uri) - 1);
    uri[sizeof(uri) - 1] = '\0';

    token = strtok(NULL, "\r\n");
    strncpy(version, token, sizeof(version) - 1);
    version[sizeof(version) - 1] = '\0';

    // Dereference failure vulnerability: buffer overflow in uri
    char buffer[10];
    strncpy(buffer, uri, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    printf("Method: %s\n", method);
    printf("URI: %s\n", buffer);
    printf("HTTP Version: %s\n", version);
}

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <HTTP request>\n", argv[0]);
        return 1;
    }

    strncpy(buffer, argv[1], BUFFER_SIZE - 1);
    buffer[BUFFER_SIZE - 1] = '\0';

    parse_request_line(buffer);

    return 0;
}
