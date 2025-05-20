#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void process_request(char *request) {
    char buffer[BUFFER_SIZE];
    printf("Received request:\n%s\n", request);
    strcpy(buffer, request);
    printf("Processing buffer contents:\n%s\n", buffer);
    gets(buffer); // buffer overflow vulnerability
    printf("After getting input, the buffer contains:\n%s\n", buffer);
}

int main(int argc, char *argv[]) {
    char request[1024];

    if (argc != 2) {
        printf("Usage: %s <HTTP request>\n", argv[0]);
        return 1;
    }

    strcpy(request, argv[1]);
    process_request(request);

    return 0;
}
