#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 16

void receive_message(char *buffer) {
    printf("Enter your message: ");
    gets(buffer); // Vulnerable to buffer overflow
}

int main() {
    char message[BUFFER_SIZE];
    receive_message(message);
    printf("Your message: %s\n", message);
    return 0;
}
