#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_MESSAGES 10
#define BUFFER_SIZE 200

void chat_manager() {
    char messages[MAX_MESSAGES][BUFFER_SIZE];
    int num_messages = 0;

    while (1) {
        printf("Enter a chat message (or enter 'quit' to exit): ");
        char input[BUFFER_SIZE];
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        strcpy(messages[num_messages], input);
        num_messages++;

        if (num_messages >= MAX_MESSAGES) {
            printf("Message buffer full. Please clear old messages to add new ones.\n");
        }
    }

    // Unsafe dereference to access non-existent messages after MAX_MESSAGES are filled
    printf("Last chat message: %s\n", messages[num_messages]);
}

int main() {
    chat_manager();
    return 0;
}
