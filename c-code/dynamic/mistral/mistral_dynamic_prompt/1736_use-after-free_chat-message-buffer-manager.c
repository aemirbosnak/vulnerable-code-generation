#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *message;
    int capacity;
    int size;
} ChatBuffer;

ChatBuffer *create_buffer(int capacity) {
    ChatBuffer *buffer = (ChatBuffer *)malloc(sizeof(ChatBuffer));
    buffer->message = (char *)malloc(capacity * sizeof(char));
    buffer->capacity = capacity;
    buffer->size = 0;
    return buffer;
}

void free_buffer(ChatBuffer *buffer) {
    free(buffer->message);
    free(buffer);
}

void add_message(ChatBuffer *buffer, const char *message, int length) {
    if (buffer->size + length > buffer->capacity) {
        buffer->message = realloc(buffer->message, (buffer->capacity * 2) * sizeof(char));
        buffer->capacity *= 2;
    }
    memcpy(buffer->message + buffer->size, message, length);
    buffer->size += length;
    buffer->message[buffer->size] = '\0';
}

void display_messages(const ChatBuffer *buffer) {
    for (int i = 0; i < buffer->size; ++i) {
        printf("%c", buffer->message[i]);
    }
    printf("\n");
}

int main() {
    ChatBuffer *buffer = create_buffer(10);
    add_message(buffer, "Hello, World!", 13);
    add_message(buffer, "This is a chat buffer manager.", 25);
    display_messages(buffer);

    // Free the buffer
    free_buffer(buffer);

    // Use the freed buffer without checking if it is still valid
    add_message(buffer, "Oops! Forgot to check if the buffer is valid.", 45);

    return 0;
}
