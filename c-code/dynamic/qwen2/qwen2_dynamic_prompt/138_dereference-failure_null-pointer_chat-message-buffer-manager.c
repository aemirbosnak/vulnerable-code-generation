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

void add_message(MessageBuffer *buf, const char *msg) {
    if (buf->count >= BUFFER_SIZE) {
        printf("Buffer overflow!\n");
        return;
    }
    buf->messages[buf->count] = strdup(msg);
    buf->count++;
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

    add_message(&buffer, "Hello, world!");
    add_message(&buffer, "This is a test.");
    add_message(&buffer, "Dereference failure coming up...");

    // Intentional null pointer dereference
    char *msg = NULL;
    printf("Message: %s\n", msg); // This will cause a segmentation fault

    print_messages(&buffer);
    free_buffer(&buffer);

    return 0;
}
