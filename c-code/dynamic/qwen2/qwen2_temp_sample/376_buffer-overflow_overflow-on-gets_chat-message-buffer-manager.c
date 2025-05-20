#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void log_message(const char* message) {
    char buffer[BUFFER_SIZE];
    // Vulnerable line: copying message into buffer without checking length
    gets(buffer);
    printf("Logged: %s\n", buffer);
}

int main() {
    printf("Welcome to the chat message buffer manager!\n");
    while (1) {
        char input[256];
        printf("Enter your message (type 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        log_message(input);
    }
    return 0;
}
