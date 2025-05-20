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
    buf->length = 0;
    buf->buffer = (char *)malloc(BUFFER_SIZE);
}

void append_to_buffer(MessageBuffer *buf, const char *message) {
    if (buf->length + strlen(message) > BUFFER_SIZE) {
        printf("Error: Buffer overflow detected!\n");
        exit(1);
    }
    strcpy(buf->buffer + buf->length, message);
    buf->length += strlen(message);
}

void print_buffer(const MessageBuffer *buf) {
    printf("Buffer content: %s\n", buf->buffer);
}

int main() {
    MessageBuffer chat_buffer;
    initialize_buffer(&chat_buffer);

    // Simulate appending messages to the buffer
    append_to_buffer(&chat_buffer, "Hello, world!");
    append_to_buffer(&chat_buffer, "This is a test message.");
    append_to_buffer(&chat_buffer, "Another message to check.");

    // Intentionally create an overflow by appending a large message
    char large_message[BUFFER_SIZE];
    memset(large_message, 'A', BUFFER_SIZE - 1);
    large_message[BUFFER_SIZE - 1] = '\0';
    append_to_buffer(&chat_buffer, large_message);

    print_buffer(&chat_buffer);

    free(chat_buffer.buffer);
    return 0;
}
