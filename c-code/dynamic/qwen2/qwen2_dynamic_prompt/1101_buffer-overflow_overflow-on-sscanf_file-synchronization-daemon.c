#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void handle_client(char *input) {
    char buffer[MAX_BUFFER_SIZE];
    if (sscanf(input, "%s", buffer) == 1) {
        printf("Received: %s\n", buffer);
    } else {
        printf("Invalid input.\n");
    }
}

int main() {
    char client_input[MAX_BUFFER_SIZE];

    while (1) {
        printf("Enter data to sync: ");
        fgets(client_input, sizeof(client_input), stdin);

        // Remove newline character if present
        size_t len = strlen(client_input);
        if (len > 0 && client_input[len - 1] == '\n') {
            client_input[len - 1] = '\0';
        }

        handle_client(client_input);
    }

    return 0;
}
