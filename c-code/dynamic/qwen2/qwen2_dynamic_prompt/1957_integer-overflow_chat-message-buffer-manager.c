#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *buffer;
    size_t length;
} MessageBuffer;

void init_buffer(MessageBuffer *buf) {
    buf->length = 0;
    buf->buffer = (char *)malloc(BUFFER_SIZE);
}

void append_message(MessageBuffer *buf, const char *message) {
    size_t msg_len = strlen(message);
    if (msg_len + buf->length > BUFFER_SIZE) {
        printf("Buffer overflow detected!\n");
        return;
    }
    strcpy(buf->buffer + buf->length, message);
    buf->length += msg_len;
}

int main() {
    MessageBuffer chat_buffer;
    init_buffer(&chat_buffer);

    // Simulate appending messages to the buffer
    append_message(&chat_buffer, "Hello, world!");
    append_message(&chat_buffer, "This is a test.");
    append_message(&chat_buffer, "Overflowing the buffer intentionally.");

    free(chat_buffer.buffer);
    return 0;
}
