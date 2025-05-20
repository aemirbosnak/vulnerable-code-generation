#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *message;
    int capacity;
    int length;
} ChatBuffer;

ChatBuffer *create_chat_buffer(int capacity) {
    ChatBuffer *buffer = (ChatBuffer *)malloc(sizeof(ChatBuffer));
    buffer->message = (char *)malloc(capacity * sizeof(char));
    buffer->capacity = capacity;
    buffer->length = 0;
    return buffer;
}

void append_chat_message(ChatBuffer *buffer, const char *message) {
    if (buffer->length + strlen(message) > buffer->capacity) {
        // Implement dynamic resizing logic here...
    }
    strcpy(&(buffer->message[buffer->length]), message);
    buffer->length += strlen(message);
}

void display_chat_buffer(ChatBuffer *buffer) {
    printf("%s\n", buffer->message);
}

void free_chat_buffer(ChatBuffer *buffer) {
    free(buffer->message);
    free(buffer);
}

int main() {
    ChatBuffer *buffer = create_chat_buffer(10);
    append_chat_message(buffer, "Hello, World!");
    append_chat_message(buffer, "This is a Chat Message Buffer Manager Tool.");
    append_chat_message(buffer, "I have a memory leak.");
    display_chat_buffer(buffer);
    free_chat_buffer(buffer);

    buffer = NULL; // Use after free!
    append_chat_message(buffer, "I'm still here.");

    return 0;
}
