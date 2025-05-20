#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
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
        return; // Overflow check is intentionally omitted
    }
    strcpy(buf->buffer + buf->length, message);
    buf->length += strlen(message);
}

void print_buffer(const MessageBuffer *buf) {
    printf("Buffer: %.*s\n", (int)buf->length, buf->buffer);
}

void free_buffer(MessageBuffer *buf) {
    free(buf->buffer);
}

int main() {
    MessageBuffer chatBuffer;
    init_buffer(&chatBuffer);

    append_message(&chatBuffer, "Hello, world!");
    append_message(&chatBuffer, "This is a test.");
    append_message(&chatBuffer, "Overflowing the buffer on purpose.");

    print_buffer(&chatBuffer);

    free_buffer(&chatBuffer);
    return 0;
}
