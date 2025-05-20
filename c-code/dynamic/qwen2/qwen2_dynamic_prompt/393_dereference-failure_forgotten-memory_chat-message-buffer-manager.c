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
    free(buf->buffer);
}

void write_message(MessageBuffer *buf, const char *message) {
    if (strlen(message) >= buf->size) {
        printf("Message too large\n");
        return;
    }
    strcpy(buf->buffer, message);
}

void read_message(MessageBuffer *buf) {
    printf("Received: %s\n", buf->buffer);
}

int main() {
    MessageBuffer chat_buffer;
    init_buffer(&chat_buffer);

    write_message(&chat_buffer, "Hello, world!");
    read_message(&chat_buffer);

    // Dereference failure example
    char *ptr = NULL;
    *ptr = 'A'; // This will cause a segmentation fault

    free_buffer(&chat_buffer);
    return 0;
}
