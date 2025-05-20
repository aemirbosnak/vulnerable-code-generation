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
        size_t new_length = strlen(message) + 1;
        if (new_length > buf->length) {
            buf->buffer = realloc(buf->buffer, new_length);
            buf->length = new_length;
        }
        strcat(buf->buffer, message);
    }
}

int main() {
    MessageBuffer *chat_buffer = create_buffer(BUFFER_SIZE);

    append_message(chat_buffer, "Hello, world!");
    printf("Chat Buffer: %s\n", chat_buffer->buffer);

    // Use after free vulnerability
    destroy_buffer(chat_buffer);
    append_message(chat_buffer, "This should cause a use after free.");

    return 0;
}
