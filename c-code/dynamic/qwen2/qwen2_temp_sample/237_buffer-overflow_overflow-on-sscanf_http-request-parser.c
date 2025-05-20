#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    char method[16], path[128], protocol[16];

    printf("Enter HTTP request: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Simulate buffer overflow using sscanf
    int result = sscanf(buffer, "%s %[^ ] %s", method, path, protocol);

    if (result != 3) {
        fprintf(stderr, "Invalid HTTP request format\n");
        return EXIT_FAILURE;
    }

    printf("Method: %s\nPath: %s\nProtocol: %s\n", method, path, protocol);

    return EXIT_SUCCESS;
}
