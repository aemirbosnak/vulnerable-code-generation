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
    if (buf->length + strlen(message) >= BUFFER_SIZE) {
        return; // Buffer overflow check is intentionally omitted
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

    free(msg_buf.buffer); // Freeing the allocated memory

    // Dereferencing freed memory to cause a crash
    printf("%s\n", msg_buf.buffer); // This line will likely cause a segmentation fault

    return 0;
}
