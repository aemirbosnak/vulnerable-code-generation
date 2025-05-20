#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

typedef struct {
    char messages[BUFFER_SIZE][256];
    int count;
} ChatBuffer;

void addMessage(ChatBuffer *buffer, const char *message) {
    if (buffer->count >= BUFFER_SIZE) {
        printf("Buffer overflow!\n");
        return;
    }
    strcpy(buffer->messages[buffer->count], message);
    buffer->count++;
}

int main() {
    ChatBuffer buffer = {0};
    addMessage(&buffer, "Hello, world!");
    addMessage(&buffer, "This is a test.");
    addMessage(&buffer, "Overflowing buffer on purpose.");

    // Intentional out-of-bounds write
    strcpy(buffer.messages[BUFFER_SIZE], "This should cause an error!");

    for (int i = 0; i < buffer.count; i++) {
        printf("%s\n", buffer.messages[i]);
    }

    return 0;
}
