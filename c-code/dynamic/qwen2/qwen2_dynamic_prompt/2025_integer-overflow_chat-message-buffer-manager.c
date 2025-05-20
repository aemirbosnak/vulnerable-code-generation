#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

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
    size_t msg_len = strlen(message);
    if (msg_len + buf->length > BUFFER_SIZE) {
        printf("Buffer overflow detected!\n");
        return;
    }
    strcpy(buf->buffer + buf->length, message);
    buf->length += msg_len;
}

int main() {
    MessageBuffer buffer;
    init_buffer(&buffer);

    // Simulate appending messages to cause an overflow
    for (int i = 0; i < 10; i++) {
        char msg[256];
        snprintf(msg, sizeof(msg), "Message %d\n", i);
        append_message(&buffer, msg);
    }

    free(buffer.buffer);
    return 0;
}
