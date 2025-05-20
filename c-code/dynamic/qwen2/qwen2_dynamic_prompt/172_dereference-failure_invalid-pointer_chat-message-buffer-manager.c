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
    buf->length = BUFFER_SIZE;
    buf->buffer = (char *)malloc(buf->length);
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

void append_message(MessageBuffer *buf, const char *message) {
    size_t msg_len = strlen(message);
    if (msg_len + 1 > buf->length) {
        buf->length *= 2;
        buf->buffer = (char *)realloc(buf->buffer, buf->length);
        if (buf->buffer == NULL) {
            fprintf(stderr, "Realloc failed\n");
            exit(1);
        }
    }
    strcat(buf->buffer, message);
}

void print_buffer(const MessageBuffer *buf) {
    printf("Buffer: %s\n", buf->buffer);
}

int main() {
    MessageBuffer chat_buffer;
    initialize_buffer(&chat_buffer);

    append_message(&chat_buffer, "Hello, world!");
    print_buffer(&chat_buffer);

    // Deliberate invalid pointer dereference
    char *invalid_ptr = (char *)NULL;
    *invalid_ptr = 'X'; // This will cause a segmentation fault

    free_buffer(&chat_buffer);
    return 0;
}
