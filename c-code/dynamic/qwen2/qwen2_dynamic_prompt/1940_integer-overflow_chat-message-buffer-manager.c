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

void initialize_buffer(MessageBuffer *buf) {
    buf->length = 0;
    buf->buffer = (char *)malloc(BUFFER_SIZE);
}

void append_to_buffer(MessageBuffer *buf, const char *message) {
    if (buf->length + strlen(message) > BUFFER_SIZE) {
        printf("Error: Buffer overflow detected!\n");
        exit(1);
    }
    strcpy(buf->buffer + buf->length, message);
    buf->length += strlen(message);
}

int main() {
    MessageBuffer msg_buf;
    initialize_buffer(&msg_buf);

    // Simulate appending messages to the buffer
    append_to_buffer(&msg_buf, "Hello, world!");
    append_to_buffer(&msg_buf, "This is a test message.");
    append_to_buffer(&msg_buf, "Another message to check.");

    printf("Buffer content: %s\n", msg_buf.buffer);

    free(msg_buf.buffer);
    return 0;
}
