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

void initialize_buffer(MessageBuffer *buf) {
    buf->size = BUFFER_SIZE;
    buf->buffer = (char *)malloc(buf->size);
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
    MessageBuffer chatBuffer;
    initialize_buffer(&chatBuffer);

    send_message(&chatBuffer, "Hello, world!");
    print_message(&chatBuffer);

    // Intentionally set buffer to NULL to simulate a dereference failure
    chatBuffer.buffer = NULL;

    // This will cause a null pointer dereference
    print_message(&chatBuffer);

    free_buffer(&chatBuffer);
    return 0;
}
