#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void handle_message(char *buffer) {
    char message[BUFFER_SIZE];
    printf("Enter your message: ");
    fscanf(stdin, "%s", message);
    printf("Received message: %s\n", message);
}

int main() {
    char buffer[20];
    while (1) {
        printf("Buffer status: %.*s\n", BUFFER_SIZE, buffer);
        handle_message(buffer);
    }
    return 0;
}
