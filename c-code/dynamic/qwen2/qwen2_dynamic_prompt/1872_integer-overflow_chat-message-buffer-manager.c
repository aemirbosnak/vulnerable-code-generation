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
    if (buf->length + strlen(message) >= BUFFER_SIZE) {
        printf("Error: Buffer overflow\n");
        exit(1);
    }
    strcpy(buf->buffer + buf->length, message);
    buf->length += strlen(message);
}

void print_buffer(MessageBuffer *buf) {
    printf("Buffer content: %s\n", buf->buffer);
}

int main() {
    MessageBuffer msgBuf;
    initialize_buffer(&msgBuf);

    // Simulate appending messages to the buffer
    append_to_buffer(&msgBuf, "Hello, ");
    append_to_buffer(&msgBuf, "world!");
    print_buffer(&msgBuf);

    // Deliberate integer overflow vulnerability
    int overflow_size = -1; // This will cause an overflow when added to BUFFER_SIZE
    append_to_buffer(&msgBuf, "This is a test message that should cause an overflow.");
    print_buffer(&msgBuf);

    free(msgBuf.buffer);
    return 0;
}
