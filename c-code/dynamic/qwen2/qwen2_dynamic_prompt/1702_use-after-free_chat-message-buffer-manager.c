#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *buffer;
} MessageBuffer;

MessageBuffer* create_buffer() {
    MessageBuffer *buf = (MessageBuffer*)malloc(sizeof(MessageBuffer));
    buf->buffer = (char*)malloc(BUFFER_SIZE);
    return buf;
}

void free_buffer(MessageBuffer *buf) {
    if (buf && buf->buffer) {
        free(buf->buffer);
        buf->buffer = NULL;
    }
}

void send_message(MessageBuffer *buf, const char *message) {
    if (buf && buf->buffer) {
        strncpy(buf->buffer, message, BUFFER_SIZE - 1);
        buf->buffer[BUFFER_SIZE - 1] = '\0';
    }
}

void print_message(MessageBuffer *buf) {
    if (buf && buf->buffer) {
        printf("Message: %s\n", buf->buffer);
    } else {
        printf("No message to print.\n");
    }
}

int main() {
    MessageBuffer *buf = create_buffer();
    send_message(buf, "Hello, world!");
    print_message(buf);

    // Free the buffer
    free_buffer(buf);

    // Use after free vulnerability
    print_message(buf); // This will cause undefined behavior

    return 0;
}
