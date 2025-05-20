#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *buffer;
    size_t length;
} MessageBuffer;

MessageBuffer* create_buffer(size_t size) {
    MessageBuffer *buf = (MessageBuffer*)malloc(sizeof(MessageBuffer));
    buf->buffer = (char*)malloc(size);
    buf->length = size;
    return buf;
}

void destroy_buffer(MessageBuffer *buf) {
    if (buf) {
        free(buf->buffer);
        free(buf);
    }
}

void append_message(MessageBuffer *buf, const char *message) {
    if (buf && message) {
        size_t new_length = strlen(message) + buf->length;
        buf->buffer = (char*)realloc(buf->buffer, new_length);
        strcat(buf->buffer, message);
        buf->length = new_length;
    }
}

void print_buffer(MessageBuffer *buf) {
    if (buf) {
        printf("%s\n", buf->buffer);
    } else {
        printf("Buffer is NULL\n");
    }
}

int main() {
    MessageBuffer *chat_buffer = create_buffer(BUFFER_SIZE);

    append_message(chat_buffer, "User1: Hello!");
    append_message(chat_buffer, "User2: Hi there!");

    print_buffer(chat_buffer);

    // Use after free vulnerability
    destroy_buffer(chat_buffer);
    chat_buffer->buffer[0] = 'X'; // Accessing freed memory

    return 0;
}
