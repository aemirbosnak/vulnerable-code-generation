#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 20

void send_message(char *message) {
    char buffer[BUFFER_SIZE];
    printf("Sending message: %s\n", message);
    strcpy(buffer, message); // Vulnerable to buffer overflow
}

int main() {
    char input[100];

    printf("Enter your message: ");
    fgets(input, sizeof(input), stdin);

    send_message(input);

    return 0;
}
