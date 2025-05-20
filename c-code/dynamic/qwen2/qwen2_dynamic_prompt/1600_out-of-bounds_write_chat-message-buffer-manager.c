#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char messages[BUFFER_SIZE];
    int count;
} ChatBuffer;

void add_message(ChatBuffer *buffer, const char *message) {
    if (buffer->count >= BUFFER_SIZE / sizeof(char)) {
        printf("Error: Buffer overflow\n");
        return;
    }
    strcpy(buffer->messages + buffer->count, message);
    buffer->count += strlen(message) + 1;
}

int main() {
    ChatBuffer buffer = { .count = 0 };
    char input[1024];

    while (1) {
        printf("Enter a message (or 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        // Intentional out-of-bounds write vulnerability
        add_message(&buffer, input);
    }

    return 0;
}
