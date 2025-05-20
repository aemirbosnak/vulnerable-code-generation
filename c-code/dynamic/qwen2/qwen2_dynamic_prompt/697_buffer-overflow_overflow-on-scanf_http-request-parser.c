#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void parse_request(char *request) {
    char method[BUFFER_SIZE];
    char path[BUFFER_SIZE];
    char version[BUFFER_SIZE];

    sscanf(request, "%s %s %s", method, path, version);
}

int main() {
    char input[200];
    printf("Enter HTTP request: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    parse_request(input);

    return 0;
}
