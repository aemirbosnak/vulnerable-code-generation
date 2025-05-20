#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void read_chat_message(char *buffer, int size) {
    scanf("%s", buffer);
}

void display_chat_message(char *message) {
    printf("Message: %s\n", message);
}

void manage_chat_messages() {
    char messages[10][256];
    int num_messages = 0;

    while (1) {
        printf("Enter a chat message (or type 'exit' to quit):\n");

        char message[256];
        read_chat_message(message, sizeof(message));

        if (strcasecmp(message, "exit") == 0) {
            break;
        }

        strcpy(messages[num_messages], message);
        num_messages++;

        if (num_messages >= 10) {
            printf("Chat buffer is full. Please remove messages to add more.\n");
        }
    }

    int i;
    for (i = 0; i < num_messages; i++) {
        display_chat_message(messages[i]);
    }
}

int main() {
    manage_chat_messages();
    return 0;
}
