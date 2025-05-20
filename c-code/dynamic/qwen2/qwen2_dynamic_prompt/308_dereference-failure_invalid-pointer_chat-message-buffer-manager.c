#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *messages[BUFFER_SIZE];
    int count;
} MessageBuffer;

void init_buffer(MessageBuffer *buf) {
    buf->count = 0;
}

int add_message(MessageBuffer *buf, const char *msg) {
    if (buf->count >= BUFFER_SIZE) {
        return -1; // Buffer is full
    }
    buf->messages[buf->count] = strdup(msg);
    if (!buf->messages[buf->count]) {
        return -1; // Memory allocation failed
    }
    buf->count++;
    return 0;
}

void print_messages(MessageBuffer *buf) {
    for (int i = 0; i < buf->count; i++) {
        printf("%s\n", buf->messages[i]);
    }
}

void free_buffer(MessageBuffer *buf) {
    for (int i = 0; i < buf->count; i++) {
        free(buf->messages[i]);
    }
    buf->count = 0;
}

int main() {
    MessageBuffer buffer;
    init_buffer(&buffer);

    add_message(&buffer, "Hello");
    add_message(&buffer, "World");

    print_messages(&buffer);

    // Deliberate dereference failure: accessing freed memory
    free_buffer(&buffer);
    printf("%s\n", buffer.messages[0]); // Invalid pointer access

    return 0;
}
