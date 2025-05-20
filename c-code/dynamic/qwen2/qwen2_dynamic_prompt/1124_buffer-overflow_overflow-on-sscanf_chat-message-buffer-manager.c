#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

void process_message(char *message) {
    char buffer[BUFFER_SIZE];
    if (sscanf(message, "%s", buffer) != 1) {
        printf("Failed to parse message.\n");
        return;
    }
    printf("Received: %s\n", buffer);
}

int main() {
    char input[200];
    printf("Enter a message: ");
    fgets(input, sizeof(input), stdin);
    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    process_message(input);
    return 0;
}
