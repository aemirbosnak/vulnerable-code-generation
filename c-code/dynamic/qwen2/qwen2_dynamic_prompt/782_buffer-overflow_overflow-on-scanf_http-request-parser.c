#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 16

void parse_request(char *request) {
    char buffer[BUFFER_SIZE];
    printf("Parsing request: %s\n", request);
    sscanf(request, "GET /%s HTTP/1.1", buffer); // Vulnerable to buffer overflow
}

int main() {
    char input[256];
    printf("Enter an HTTP GET request: ");
    fgets(input, sizeof(input), stdin);
    parse_request(input);
    return 0;
}
