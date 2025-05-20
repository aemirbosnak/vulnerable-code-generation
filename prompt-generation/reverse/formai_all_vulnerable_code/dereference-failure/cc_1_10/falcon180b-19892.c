//Falcon-180B DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    size_t size;
} Buffer;

void buffer_init(Buffer *buffer) {
    buffer->data = NULL;
    buffer->size = 0;
}

void buffer_free(Buffer *buffer) {
    if (buffer->data!= NULL) {
        free(buffer->data);
        buffer->data = NULL;
        buffer->size = 0;
    }
}

void buffer_resize(Buffer *buffer, size_t new_size) {
    if (new_size <= buffer->size) {
        return;
    }

    char *new_data = realloc(buffer->data, new_size);
    if (new_data == NULL) {
        fprintf(stderr, "Error: failed to resize buffer\n");
        exit(EXIT_FAILURE);
    }

    buffer->data = new_data;
    buffer->size = new_size;
}

void buffer_append(Buffer *buffer, const char *str) {
    size_t len = strlen(str);

    if (buffer->size - buffer->size < len) {
        buffer_resize(buffer, buffer->size + len + 1);
    }

    strcpy(buffer->data + buffer->size, str);
    buffer->size += len;
}

void buffer_clear(Buffer *buffer) {
    buffer->size = 0;
    buffer->data[0] = '\0';
}

int main() {
    Buffer buffer;
    buffer_init(&buffer);

    buffer_append(&buffer, "Hello, world!");
    printf("Buffer: %s\n", buffer.data);

    buffer_clear(&buffer);
    printf("Buffer after clear: %s\n", buffer.data);

    buffer_append(&buffer, "This is a test");
    printf("Buffer after append: %s\n", buffer.data);

    buffer_free(&buffer);
    return 0;
}