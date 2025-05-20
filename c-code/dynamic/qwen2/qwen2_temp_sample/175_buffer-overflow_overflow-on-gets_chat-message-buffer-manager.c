#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

void handle_message(char *message) {
    char buffer[BUFFER_SIZE];
    printf("Received: %s\n", message);
    strcpy(buffer, message); // Vulnerable line
}

int main() {
    char input[20];

    while (1) {
        printf("Enter a message: ");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        handle_message(input);
    }

    return 0;
}
