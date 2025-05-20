#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void readMessage(char* buffer) {
    printf("Enter message: ");
    fgets(buffer, BUFFER_SIZE, stdin);
}

void printMessage(char* buffer) {
    printf("Message: %s\n", buffer);
}

int main() {
    char message[BUFFER_SIZE];

    while (1) {
        readMessage(message);
        printf("Storing message in buffer...\n");

        // OOB (Read) Vulnerability - Reading past the end of the buffer
        printf("message[%d]: %c\n", BUFFER_SIZE + 1, message[BUFFER_SIZE]);

        printMessage(message);
    }

    return 0;
}
