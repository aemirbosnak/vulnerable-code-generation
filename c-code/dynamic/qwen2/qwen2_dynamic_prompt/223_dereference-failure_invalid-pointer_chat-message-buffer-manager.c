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

void init_buffer(MessageBuffer *buf) {
    buf->size = BUFFER_SIZE;
    buf->buffer = (char *)malloc(buf->size);
}

void free_buffer(MessageBuffer *buf) {
    if (buf->buffer != NULL) {
        free(buf->buffer);
        buf->buffer = NULL;
    }
}

void write_message(MessageBuffer *buf, const char *message) {
    if (buf->buffer == NULL) return;
    snprintf(buf->buffer, buf->size, "%s", message);
}

void read_message(MessageBuffer *buf) {
    if (buf->buffer == NULL) return;
    printf("Message: %s\n", buf->buffer);
}

int main() {
    MessageBuffer buf;
    init_buffer(&buf);

    write_message(&buf, "Hello, world!");
    read_message(&buf);

    // Intentional invalid pointer dereference
    char *invalid_ptr = (char *)0xDEADBEEF;
    *invalid_ptr = 'X'; // This will cause a segmentation fault

    free_buffer(&buf);
    return 0;
}
