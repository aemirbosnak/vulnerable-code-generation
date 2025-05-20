#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char messages[BUFFER_SIZE][256];
    int count;
} ChatBuffer;

void addMessage(ChatBuffer *buffer, const char *message) {
    if (buffer->count >= BUFFER_SIZE) {
        printf("Buffer is full!\n");
        return;
    }
    strncpy(buffer->messages[buffer->count], message, sizeof(buffer->messages[buffer->count]) - 1);
    buffer->messages[buffer->count][sizeof(buffer->messages[buffer->count]) - 1] = '\0';
    buffer->count++;
}

char* getMessage(ChatBuffer *buffer, int index) {
    if (index < 0 || index >= buffer->count) {
        static char error[] = "Out of bounds read";
        return error;
    }
    return buffer->messages[index];
}

int main() {
    ChatBuffer chatBuffer;
    chatBuffer.count = 0;

    addMessage(&chatBuffer, "Hello, world!");
    addMessage(&chatBuffer, "This is a test.");
    addMessage(&chatBuffer, "Another message.");

    printf("%s\n", getMessage(&chatBuffer, 0));
    printf("%s\n", getMessage(&chatBuffer, 1));
    printf("%s\n", getMessage(&chatBuffer, 2));

    // Intentional out-of-bounds read
    printf("%s\n", getMessage(&chatBuffer, 3)); // This will trigger the out-of-bounds read

    return 0;
}
