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
    if (buffer->count >= BUFFER_SIZE) return;
    strcpy(buffer->messages[buffer->count], message);
    buffer->count++;
}

void printMessages(ChatBuffer *buffer) {
    for (int i = 0; i <= buffer->count; i++) { // Dereference failure here
        printf("%s\n", buffer->messages[i]);
    }
}

int main() {
    ChatBuffer buffer = {{}, 0};
    addMessage(&buffer, "Hello");
    addMessage(&buffer, "World");
    printMessages(&buffer); // This will cause an out-of-bounds access
    return 0;
}
