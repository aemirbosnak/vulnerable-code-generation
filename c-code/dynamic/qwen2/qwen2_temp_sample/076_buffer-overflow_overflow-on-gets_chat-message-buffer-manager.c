#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 16

void handle_message(char *message) {
    char buffer[BUFFER_SIZE];
    printf("Received message: %s\n", message);
    strcpy(buffer, message); // Vulnerable to buffer overflow
}

int main() {
    char input[256];
    printf("Enter a message: ");
    fgets(input, sizeof(input), stdin);
    handle_message(input);
    return 0;
}
