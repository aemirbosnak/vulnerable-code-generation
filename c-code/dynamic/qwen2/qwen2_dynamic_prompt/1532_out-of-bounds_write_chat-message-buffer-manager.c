#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void send_message(char *message) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, message);
}

int main() {
    char input[20];
    printf("Enter your message: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    send_message(input);

    return 0;
}
