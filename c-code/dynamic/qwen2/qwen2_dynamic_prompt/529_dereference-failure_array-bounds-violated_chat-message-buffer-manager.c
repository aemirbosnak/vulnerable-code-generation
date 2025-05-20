#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

char buffer[BUFFER_SIZE];

void send_message(const char *message) {
    strcpy(buffer, message);
}

int main() {
    printf("Chat Buffer Manager\n");
    
    // Simulate sending messages
    send_message("Hello, world!");
    send_message("This is a test.");
    send_message("Another message to fill the buffer.");
    
    // Intentionally overflow the buffer
    char large_message[20];
    snprintf(large_message, sizeof(large_message), "A very long message that will overflow the buffer: %s", "x");
    send_message(large_message);
    
    // Print the buffer content
    printf("Buffer content: %s\n", buffer);
    
    return 0;
}
