#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_message(char *buffer) {
    printf("Enter your message (max 1024 characters): ");
    fgets(buffer, BUFFER_SIZE, stdin);
}

void process_message(char *buffer) {
    // Processing logic for a real-world application (fake for this example)
    printf("Processing message: %s\n", buffer);
}

int main() {
    char message[BUFFER_SIZE];

    for (;;) {
        read_message(message);
        process_message(message);
    }

    return 0;
}
