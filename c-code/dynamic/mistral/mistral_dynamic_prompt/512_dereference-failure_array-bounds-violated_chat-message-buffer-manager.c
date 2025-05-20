#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 100
#define NUM_MESSAGES 10

void process_message(char *buffer);

int main(int argc, char *argv[]) {
    char messages[NUM_MESSAGES][BUFFER_SIZE];
    char *input;
    int i = 0;

    while (1) {
        printf("Enter a chat message (or Q to quit): ");
        input = malloc(BUFFER_SIZE * sizeof(char));
        fgets(input, BUFFER_SIZE, stdin);

        if (strcmp(input, "Q\n") == 0) {
            break;
        }

        strcpy(messages[i], input);
        process_message(messages[i]);
        i = (i + 1) % NUM_MESSAGES;
        free(input);
    }

    return 0;
}

void process_message(char *buffer) {
    int len = strlen(buffer);
    printf("Message processed: %s\n", buffer);
    printf("Length of message: %d\n", len);
    printf("Char at index %d: %c\n", len + 1, buffer[len + 1]); // Dereference failure vulnerability
}
