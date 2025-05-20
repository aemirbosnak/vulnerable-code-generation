#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10
#define MAX_MESSAGE_LENGTH 200

void handle_input(char *buffer, int *num_messages) {
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter a chat message: ");
    fgets(message, sizeof(message), stdin);

    int message_length = strlen(message);
    if (message_length > (BUFFER_SIZE - *num_messages - 1)) {
        printf("Message too long.\n");
        return;
    }

    strcpy(buffer + (*num_messages) * BUFFER_SIZE, message);
    (*num_messages)++;
}

int main() {
    char chat_buffer[BUFFER_SIZE][BUFFER_SIZE];
    int num_messages = 0;

    while (1) {
        handle_input(chat_buffer[num_messages], &num_messages);
    }

    return 0;
}
