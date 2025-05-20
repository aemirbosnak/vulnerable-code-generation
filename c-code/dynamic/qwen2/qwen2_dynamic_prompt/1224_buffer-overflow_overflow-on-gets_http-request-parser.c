#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void parse_request(char *request) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, request);
}

int main() {
    char request[20] = "GET /index.html HTTP/1.1\r\nHost: example.com";
    parse_request(request);
    return 0;
}
