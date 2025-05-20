#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

void send_message(const char* message) {
    char buffer[MAX_BUFFER_SIZE];
    strcpy(buffer, message); // Vulnerable to buffer overflow if message is too long
}

int main() {
    char input[1024];
    printf("Enter your message: ");
    fgets(input, sizeof(input), stdin);
    send_message(input);
    return 0;
}
