#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100

void read_chat_message(char* buffer) {
    memset(buffer, '\0', BUFFER_SIZE);
    read(0, buffer, BUFFER_SIZE);
}

void print_chat_message(char* buffer) {
    write(1, buffer, strlen(buffer));
}

void main() {
    char message_buffer[BUFFER_SIZE];

    for(;;) {
        read_chat_message(message_buffer);
        char* token = strtok(message_buffer, "\n");

        // Accessing memory past the allocated buffer size
        char* username = token + strlen(token);
        char* message = username + 1;

        print_chat_message(message);
        printf("\n");
    }
}
