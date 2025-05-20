#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void main() {
    char messages[10][BUFFER_SIZE];
    int numMessages = 0;

    while (1) {
        printf("Enter a chat message (or type 'quit' to exit): ");
        char input[BUFFER_SIZE];
        fgets(input, BUFFER_SIZE, stdin);

        if (strncmp(input, "quit", 4) == 0) {
            break;
        }

        numMessages++;
        strcpy(messages[numMessages-1], input);

        printf("Message stored: %s\n", messages[numMessages-1]);

        // Dereference non-existent memory
        printf("Stored messages:\n");
        for (int i = 0; i < numMessages+1; i++) {
            printf("%s\n", messages[i]);
        }
    }
}
