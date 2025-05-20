#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_message(char* buffer) {
    printf("Enter a chat message (max 1024 chars): ");
    gets(buffer);
}

void display_message(const char* message) {
    printf("Message: %s\n", message);
}

int main() {
    char buffer[BUFFER_SIZE];
    char* messages[10];
    int messages_count = 0;

    while (true) {
        read_message(buffer);
        messages[messages_count] = buffer;
        messages_count++;
        if (messages_count >= 10) break;
    }

    for (int i = 0; i < messages_count; i++) {
        display_message(messages[i]);
    }

    return 0;
}
