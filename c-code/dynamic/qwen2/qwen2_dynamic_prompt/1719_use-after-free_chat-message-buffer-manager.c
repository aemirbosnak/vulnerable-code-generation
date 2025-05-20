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
    free(buf->buffer);
    free(buf);
}

void send_message(MessageBuffer *buf, const char *message) {
    strcpy(buf->buffer, message);
}

void read_message(MessageBuffer *buf) {
    printf("Received: %s\n", buf->buffer);
}

int main() {
    MessageBuffer *buf = create_buffer();
    send_message(buf, "Hello, world!");
    read_message(buf);

    // Free the buffer
    free_buffer(buf);

    // Use-after-free vulnerability
    send_message(buf, "This should cause an error!");

    return 0;
}
