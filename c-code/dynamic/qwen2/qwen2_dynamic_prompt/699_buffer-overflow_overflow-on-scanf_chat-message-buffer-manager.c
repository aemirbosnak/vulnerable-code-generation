#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 16

void send_message(char *message) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, message);
    printf("Message sent: %s\n", buffer);
}

int main() {
    char input[256];
    printf("Enter your message: ");
    scanf("%s", input); // Vulnerability here: no bounds checking
    send_message(input);
    return 0;
}
