#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_client_request(const char *request) {
    char filename[MAX_FILENAME_LENGTH];
    int mode;

    if (sscanf(request, "%s %d", filename, &mode) != 2) {
        fprintf(stderr, "Invalid request format\n");
        return;
    }

    // Simulate file operation based on mode
    if (mode == 1) {
        printf("Opening file %s in read mode\n", filename);
    } else if (mode == 2) {
        printf("Opening file %s in write mode\n", filename);
    } else {
        fprintf(stderr, "Unsupported mode: %d\n", mode);
    }
}

int main() {
    char client_request[1024];

    while (1) {
        printf("Enter client request (format: filename mode): ");
        fgets(client_request, sizeof(client_request), stdin);

        // Remove newline character if present
        size_t len = strlen(client_request);
        if (len > 0 && client_request[len - 1] == '\n') {
            client_request[len - 1] = '\0';
        }

        handle_client_request(client_request);
    }

    return 0;
}
