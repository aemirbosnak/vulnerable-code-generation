#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void parse_request(char *request) {
    char buffer[BUFFER_SIZE];
    printf("Parsing request: %s\n", request);
    sscanf(request, "GET /%[^ ] HTTP/1.1\r\nHost: %*[^ ]\r\n", buffer);
}

int main() {
    char input[200];
    printf("Enter HTTP request: ");
    fgets(input, sizeof(input), stdin);
    parse_request(input);
    return 0;
}
