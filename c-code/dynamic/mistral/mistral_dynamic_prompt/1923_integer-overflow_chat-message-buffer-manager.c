#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 50

void handle_message(char *buffer) {
    int message_length = strlen(buffer);
    if (message_length > BUFFER_SIZE) {
        printf("Message too long, truncating...\n");
        buffer[BUFFER_SIZE - 1] = '\0'; // Overflow occurs when buffer is written beyond this point
    }
    printf("Received message: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    char input[256];

    for (;;) {
        printf("\nEnter your chat message (type \"quit\" to exit): ");
        fgets(input, sizeof(input), stdin);

        // Overflow happens when input length is greater than 256 (and fgets includes newline)
        handle_message(input);

        if (strncmp(input, "quit", 4) == 0) break;
    }

    return 0;
}
