#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char messages[BUFFER_SIZE][100];
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

void printMessages(ChatBuffer *buffer) {
    for (int i = 0; i <= buffer->count; i++) { // Deliberate off-by-one error
        printf("%s\n", buffer->messages[i]);
    }
}

int main() {
    ChatBuffer buffer = {{}, 0};
    addMessage(&buffer, "Hello, world!");
    addMessage(&buffer, "This is a test.");
    printMessages(&buffer); // This will cause a buffer overflow
    return 0;
}
