#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void process_message(char *buffer) {
    printf("Processing message: %s\n", buffer);
}

int main() {
    char message[BUFFER_SIZE];

    printf("Enter a chat message (max 100 characters): ");
    fgets(message, BUFFER_SIZE, stdin);

    process_message(message);

    return 0;
}
