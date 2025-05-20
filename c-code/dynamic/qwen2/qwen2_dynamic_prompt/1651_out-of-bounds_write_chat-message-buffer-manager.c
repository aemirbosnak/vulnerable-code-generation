#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

char buffer[BUFFER_SIZE];

void send_message(const char* message) {
    strcpy(buffer, message);
}

int main() {
    printf("Chat Buffer Manager\n");
    
    // Simulate sending messages
    send_message("Hello, world!");
    printf("Buffer: %s\n", buffer);

    // Intentional out-of-bounds write
    send_message("This is a very long message that will overflow the buffer intentionally.");
    printf("Buffer: %s\n", buffer);

    return 0;
}
