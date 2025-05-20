#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *messages[BUFFER_SIZE];
    int count;
} MessageBuffer;

void addMessage(MessageBuffer *buffer, const char *message) {
    if (buffer->count >= BUFFER_SIZE) {
        printf("Buffer is full!\n");
        return;
    }
    buffer->messages[buffer->count] = strdup(message);
    buffer->count++;
}

void printMessages(MessageBuffer *buffer) {
    for (int i = 0; i < buffer->count; i++) {
        printf("%s\n", buffer->messages[i]);
    }
}

void freeBuffer(MessageBuffer *buffer) {
    for (int i = 0; i < buffer->count; i++) {
        free(buffer->messages[i]); // Free each message
    }
    buffer->count = 0; // Reset count after freeing all messages
}

int main() {
    MessageBuffer buffer;
    buffer.count = 0;

    addMessage(&buffer, "Hello, world!");
    addMessage(&buffer, "This is a test.");
    addMessage(&buffer, "Dereference failure example.");

    printMessages(&buffer);

    freeBuffer(&buffer); // Free all allocated messages

    // Intentional dereference failure: accessing freed memory
    printf("%s\n", buffer.messages[0]); // This will cause a segmentation fault

    return 0;
}
