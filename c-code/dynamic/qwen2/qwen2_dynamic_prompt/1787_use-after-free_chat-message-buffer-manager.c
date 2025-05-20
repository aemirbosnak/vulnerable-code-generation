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
    free(buf->buffer);
    free(buf);
}

void append_message(MessageBuffer *buf, const char *message) {
    if (strlen(message) + strlen(buf->buffer) > buf->length) {
        printf("Buffer overflow!\n");
        exit(1);
    }
    strcat(buf->buffer, message);
}

int main() {
    MessageBuffer *chat_buffer = create_buffer(BUFFER_SIZE);

    // Simulate appending messages
    append_message(chat_buffer, "Hello, world!");
    append_message(chat_buffer, "This is a test.");
    append_message(chat_buffer, "Use after free vulnerability demonstration.");

    // Free the buffer
    destroy_buffer(chat_buffer);

    // Use after free: Accessing freed memory
    printf("%s\n", chat_buffer->buffer); // This will cause undefined behavior

    return 0;
}
