#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_http_request(char *request) {
    char method[8], path[256], version[16];
    char *token, headers[4096];
    int content_length, i = 0;

    sscanf(request, "%s %s %s", method, path, version);

    token = strtok(path, " ");
    strcpy(path, token);

    token = strtok(NULL, "\r\n");
    sscanf(token, "Content-Length: %d", &content_length);

    token = strtok(NULL, "\n");
    strcpy(headers, token);

    while ((token = strtok(NULL, "\n")) != NULL) {
        strcat(headers, token);
        strcat(headers, "\n");
    }

    char input_buffer[BUFFER_SIZE];
    printf("Content-Length: %d\n", content_length);

    read(0, input_buffer, content_length);

    for (i = 0; i < content_length; i++) {
        input_buffer[i] += strlen(path) + strlen(method) + strlen(version) + strlen(headers);
    }

    printf("Input Buffer: %s\n", input_buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./http_request_parser <http_request>\n");
        return 1;
    }

    parse_http_request(argv[1]);

    return 0;
}
