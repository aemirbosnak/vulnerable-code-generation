#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void handle_message(char *buffer) {
    printf("Received message: %s\n", buffer);
}

int main() {
    char message[BUFFER_SIZE];
    printf("Enter chat message (up to %d characters): ", BUFFER_SIZE);
    gets(message);
    handle_message(message);
    return 0;
}
