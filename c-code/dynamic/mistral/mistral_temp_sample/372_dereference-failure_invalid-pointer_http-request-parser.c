#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 8192

void parse_request(char* buffer) {
    char* method = NULL;
    char* path = NULL;
    char* version = NULL;
    char* host = NULL;
    char* content_length = NULL;

    method = strtok(buffer, " ");
    path = strtok(NULL, " ");
    version = strtok(NULL, "\r\n");

    char* headers_start = strchr(buffer, '\n') + 1;
    char* headers_end = strchr(headers_start, '\r') - 1;

    // Invalid pointer dereference vulnerability intentionally introduced here
    int content_length_int = atoi(strtok(headers_start, ":") + 1);
    char* content = malloc(content_length_int);
    strncpy(content, strchr(headers_start, '\n'), content_length_int);

    // Accessing an uninitialized pointer at this line will cause a dereference failure
    // when 'content_length_int' is less than strlen(content)
    printf("Content: %s\n", content);

    free(method);
    free(path);
    free(version);
    free(host);
    free(content);
}

int main(int argc, char** argv) {
    char buffer[BUFFER_SIZE];
    char* data = "GET /example HTTP/1.1\r\nContent-Length: 10\r\n\r\nSome Content";

    strncpy(buffer, data, strlen(data));
    parse_request(buffer);

    return 0;
}
