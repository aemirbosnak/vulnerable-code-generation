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
    if (buf->buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

void free_buffer(MessageBuffer *buf) {
    free(buf->buffer);
    buf->buffer = NULL;
    buf->length = 0;
}

int append_message(MessageBuffer *buf, const char *message) {
    size_t new_length = buf->length + strlen(message) + 1;
    if (new_length > BUFFER_SIZE) {
        return -1; // Buffer overflow
    }
    strcpy(buf->buffer + buf->length, message);
    buf->length = new_length;
    return 0;
}

void print_buffer(MessageBuffer *buf) {
    printf("Buffer: %.*s\n", (int)buf->length, buf->buffer);
}

int main() {
    MessageBuffer msg_buf;
    init_buffer(&msg_buf);

    append_message(&msg_buf, "Hello, world!");
    print_buffer(&msg_buf);

    // Deliberate dereference failure
    char *ptr = NULL;
    *ptr = 'X'; // Invalid pointer dereference

    free_buffer(&msg_buf);
    return 0;
}
