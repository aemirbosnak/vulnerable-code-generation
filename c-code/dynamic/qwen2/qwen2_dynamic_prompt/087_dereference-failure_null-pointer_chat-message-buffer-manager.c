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

void send_message(MessageBuffer *buf, const char *message) {
    if (buf->buffer == NULL) {
        printf("Error: Buffer is not initialized.\n");
        return;
    }
    snprintf(buf->buffer, buf->size, "%s", message);
}

void print_message(MessageBuffer *buf) {
    if (buf->buffer == NULL) {
        printf("Error: Buffer is not initialized.\n");
        return;
    }
    printf("Message: %s\n", buf->buffer);
}

int main() {
    MessageBuffer msg_buf;
    init_buffer(&msg_buf, BUFFER_SIZE);

    send_message(&msg_buf, "Hello, world!");
    print_message(&msg_buf);

    // Intentionally set buffer to NULL to simulate a dereference failure
    msg_buf.buffer = NULL;

    // This will cause a null pointer dereference
    print_message(&msg_buf);

    free_buffer(&msg_buf);
    return 0;
}
