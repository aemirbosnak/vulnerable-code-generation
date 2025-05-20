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
    char input[200];
    printf("Enter an HTTP request: ");
    fgets(input, sizeof(input), stdin);
    parse_request(input);
    return 0;
}
