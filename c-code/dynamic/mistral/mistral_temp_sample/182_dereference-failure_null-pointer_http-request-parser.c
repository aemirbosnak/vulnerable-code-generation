#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void parse_http_request(char *buffer) {
    char *method, *url, *protocol, *headers, *content;
    char *token, *next_token;
    method = strtok(buffer, " ");
    url = strtok(NULL, " ");
    protocol = strtok(NULL, "\r\n");

    headers = strtok(NULL, "\r\n");
    while (headers && strncmp(headers, "\r\n", 2)) {
        token = strtok(headers, ": ");
        next_token = strtok(NULL, "\r\n");
        printf("%s: %s\n", token, next_token);
        headers = strtok(NULL, "\r\n");
    }

    content = strtok(NULL, NULL);
    printf("Content:\n%s\n", content);
}

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    FILE *request_file = fopen(argv[1], "r");

    if (!request_file) {
        fprintf(stderr, "Error: Unable to open file.\n");
        return 1;
    }

    size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, request_file);
    buffer[bytes_read] = '\0';
    fclose(request_file);

    parse_http_request(buffer);

    return 0;
}
