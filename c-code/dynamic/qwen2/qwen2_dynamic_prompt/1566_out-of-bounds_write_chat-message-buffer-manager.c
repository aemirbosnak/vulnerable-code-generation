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
        printf("Buffer is full!\n");
        return;
    }
    strcpy(buffer->messages[buffer->count], message);
    buffer->count++;
}

void printMessages(ChatBuffer *buffer) {
    for (int i = 0; i < buffer->count; i++) {
        printf("%s\n", buffer->messages[i]);
    }
}

int main() {
    ChatBuffer buffer;
    buffer.count = 0;

    addMessage(&buffer, "Hello, world!");
    addMessage(&buffer, "This is a test.");
    addMessage(&buffer, "Another message.");

    // Intentional out-of-bounds write vulnerability
    strcpy(buffer.messages[3], "This should cause an error!");

    printMessages(&buffer);

    return 0;
}
