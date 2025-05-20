#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 16

void handle_message(char *message) {
    char buffer[BUFFER_SIZE];
    printf("Received message: %s\n", message);
    strcpy(buffer, message); // Vulnerable to buffer overflow
}

int main() {
    char input[256];
    printf("Enter your message: ");
    scanf("%255s", input); // Safe read up to 255 characters
    handle_message(input);
    return 0;
}
