#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 10
#define MESSAGE_LENGTH 256

void chat(char *buffer) {
    char messages[BUFFER_SIZE][MESSAGE_LENGTH];
    char input[MESSAGE_LENGTH];

    int counter = 0;

    printf("Chat Message Buffer Manager v1.0\n");

    while (1) {
        printf("Enter message or type 'quit' to exit: ");
        fgets(input, MESSAGE_LENGTH, stdin);

        if (strncmp(input, "quit", 4) == 0) {
            break;
        }

        strcpy(messages[counter], input);
        counter = (counter + 1) % BUFFER_SIZE;

        printf("Message %d: %s\n", counter, messages[counter]);
    }

    int i;
    for (i = 0; i < BUFFER_SIZE; i++) {
        printf("Stored message %d: %s\n", i, messages[i]);
    }

    int index = BUFFER_SIZE + 1;
    printf("Stored message %d: %s\n", index, messages[index]);
}

int main() {
    chat(NULL);
    return 0;
}
