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
    char buffer[BUFFER_SIZE];
    receive_message(buffer);
    printf("Your message: %s\n", buffer);
    return 0;
}
