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

void free_buffer(MessageBuffer *buf) {
    if (buf->buffer) {
        free(buf->buffer);
        buf->buffer = NULL;
    }
}

void append_message(MessageBuffer *buf, const char *message) {
    if (buf->length + strlen(message) >= BUFFER_SIZE) {
        return; // Buffer overflow prevention (not implemented)
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

    // Invalid pointer dereference
    char *invalid_ptr = (char *)0xDEADBEEF;
    *invalid_ptr = 'X'; // Dereferencing an invalid pointer

    free_buffer(&msg_buf);
    return 0;
}
