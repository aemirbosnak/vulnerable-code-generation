//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: protected
/*
 * Unique C Memory Management Example Program in a Protected Style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char* buffer;
    size_t capacity;
    size_t length;
} Buffer;

Buffer* create_buffer(size_t capacity) {
    Buffer* buffer = (Buffer*)malloc(sizeof(Buffer));
    buffer->buffer = (char*)malloc(capacity * sizeof(char));
    buffer->capacity = capacity;
    buffer->length = 0;
    return buffer;
}

void destroy_buffer(Buffer* buffer) {
    free(buffer->buffer);
    free(buffer);
}

void print_buffer(Buffer* buffer) {
    printf("%s", buffer->buffer);
}

void append_to_buffer(Buffer* buffer, const char* str) {
    size_t len = strlen(str);
    if (buffer->length + len > buffer->capacity) {
        buffer->capacity = buffer->length + len;
        buffer->buffer = (char*)realloc(buffer->buffer, buffer->capacity * sizeof(char));
    }
    strcpy(buffer->buffer + buffer->length, str);
    buffer->length += len;
}

int main() {
    Buffer* buffer = create_buffer(BUFFER_SIZE);
    append_to_buffer(buffer, "Hello");
    append_to_buffer(buffer, ", ");
    append_to_buffer(buffer, "World!");
    print_buffer(buffer);
    destroy_buffer(buffer);
    return 0;
}