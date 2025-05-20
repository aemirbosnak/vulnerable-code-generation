#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *buffer;
    int size;
} MessageBuffer;

void init_buffer(MessageBuffer *buf, int size) {
    buf->size = size;
    buf->buffer = (char *)malloc(size);
}

void free_buffer(MessageBuffer *buf) {
    if (buf->buffer != NULL) {
        free(buf->buffer);
        buf->buffer = NULL;
    }
}

void write_message(MessageBuffer *buf, const char *message) {
    if (buf->buffer == NULL) {
        printf("Error: Buffer is not initialized.\n");
        return;
    }
    snprintf(buf->buffer, buf->size, "%s", message);
}

void read_message(MessageBuffer *buf) {
    if (buf->buffer == NULL) {
        printf("Error: Buffer is not initialized.\n");
        return;
    }
    printf("Message: %s\n", buf->buffer);
}

int main() {
    MessageBuffer msgBuf;
    init_buffer(&msgBuf, BUFFER_SIZE);

    write_message(&msgBuf, "Hello, world!");
    read_message(&msgBuf);

    // Intentionally set buffer to NULL to simulate dereference failure
    msgBuf.buffer = NULL;

    // This will cause a null pointer dereference
    read_message(&msgBuf);

    free_buffer(&msgBuf);
    return 0;
}
