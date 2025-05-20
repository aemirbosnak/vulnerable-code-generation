#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char messages[BUFFER_SIZE][256];
    int count;
} ChatBuffer;

void add_message(ChatBuffer *buffer, const char *message) {
    if (buffer->count >= BUFFER_SIZE) {
        printf("Buffer is full!\n");
        return;
    }
    strncpy(buffer->messages[buffer->count], message, sizeof(buffer->messages[buffer->count]) - 1);
    buffer->messages[buffer->count][sizeof(buffer->messages[buffer->count]) - 1] = '\0';
    buffer->count++;
}

char* get_message(ChatBuffer *buffer, int index) {
    if (index < 0 || index >= buffer->count) {
        static char error[] = "Out of bounds read";
        return error;
    }
    return buffer->messages[index];
}

int main() {
    ChatBuffer chat_buffer;
    chat_buffer.count = 0;

    add_message(&chat_buffer, "Hello, world!");
    add_message(&chat_buffer, "This is a test.");
    add_message(&chat_buffer, "Another message.");

    printf("%s\n", get_message(&chat_buffer, 0));
    printf("%s\n", get_message(&chat_buffer, 1));
    printf("%s\n", get_message(&chat_buffer, 2));

    // Intentional out-of-bounds read
    printf("%s\n", get_message(&chat_buffer, 3));

    return 0;
}
