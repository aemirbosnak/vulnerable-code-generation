#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void process_message(char *message) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, message);
    printf("Received: %s\n", buffer);
}

int main() {
    char input[20];
    printf("Enter a message: ");
    fgets(input, sizeof(input), stdin);

    // Simulate processing the message
    process_message(input);

    return 0;
}
