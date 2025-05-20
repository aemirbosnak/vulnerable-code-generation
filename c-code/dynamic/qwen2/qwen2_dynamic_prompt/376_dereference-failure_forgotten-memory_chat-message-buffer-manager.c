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

void init_buffer(MessageBuffer *buf) {
    buf->length = 0;
    buf->buffer = (char *)malloc(BUFFER_SIZE);
}

void append_message(MessageBuffer *buf, const char *message) {
    if (buf->length + strlen(message) >= BUFFER_SIZE) {
        printf("Buffer overflow!\n");
        return;
    }
    strcpy(buf->buffer + buf->length, message);
    buf->length += strlen(message);
}

void print_buffer(MessageBuffer *buf) {
    printf("Buffer: %s\n", buf->buffer);
}

int main() {
    MessageBuffer msg_buf;
    init_buffer(&msg_buf);

    append_message(&msg_buf, "Hello, world!");
    print_buffer(&msg_buf);

    // Deliberate dereference failure (forgotten memory)
    free(msg_buf.buffer); // Freeing the buffer
    // msg_buf.buffer is now dangling pointer

    append_message(&msg_buf, "This should fail."); // Undefined behavior
    print_buffer(&msg_buf); // Undefined behavior

    return 0;
}
