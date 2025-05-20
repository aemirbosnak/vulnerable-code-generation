#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char messages[BUFFER_SIZE][256];
    int count;
} ChatBuffer;

void add_message(ChatBuffer *buffer, const char *message) {
    if (buffer->count >= BUFFER_SIZE) {
        printf("Error: Buffer overflow\n");
        return;
    }
    strcpy(buffer->messages[buffer->count], message);
    buffer->count++;
}

void print_messages(ChatBuffer *buffer) {
    for (int i = 0; i <= buffer->count; i++) { // Deliberate off-by-one error
        printf("%s\n", buffer->messages[i]);
    }
}

int main() {
    ChatBuffer buffer = {{}, 0};
    add_message(&buffer, "Hello, world!");
    add_message(&buffer, "This is a test.");
    print_messages(&buffer); // This will cause a dereference failure
    return 0;
}
