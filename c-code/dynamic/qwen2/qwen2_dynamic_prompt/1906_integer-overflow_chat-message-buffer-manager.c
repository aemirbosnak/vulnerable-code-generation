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
}

void append_message(MessageBuffer *buf, const char *message) {
    if (buf->length + strlen(message) > BUFFER_SIZE - 1) {
        printf("Error: Buffer overflow\n");
        return;
    }
    strcpy(buf->buffer + buf->length, message);
    buf->length += strlen(message);
}

int main() {
    MessageBuffer msg_buf;
    init_buffer(&msg_buf);

    // Simulate appending messages to the buffer
    for (int i = 0; i < 1000; i++) {
        char temp[10];
        snprintf(temp, sizeof(temp), "Message %d", i);
        append_message(&msg_buf, temp);
    }

    free(msg_buf.buffer);
    return 0;
}
