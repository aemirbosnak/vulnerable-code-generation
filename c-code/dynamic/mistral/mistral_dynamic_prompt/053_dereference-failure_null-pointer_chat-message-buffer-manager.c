#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Message {
    char *content;
    struct Message *next;
} Message;

void add_message(Message **messages, char *msg) {
    Message *new_msg = malloc(sizeof(Message));
    new_msg->content = msg;
    new_msg->next = *messages;
    *messages = new_msg;
}

void display_messages(Message *messages) {
    Message *current = messages;
    while (current != NULL) {
        printf("%s\n", current->content);
        current = current->next;
    }
}

int main() {
    Message *chat_log = NULL;
    char input[100];

    while (1) {
        printf("Enter a chat message or type 'quit' to exit: ");
        fgets(input, 100, stdin);

        if (strcmp(input, "quit\n") == 0) {
            break;
        }

        char *message = malloc(strlen(input) + 1);
        strcpy(message, input);

        add_message(&chat_log, message);
    }

    display_messages(chat_log);

    // Dereference null pointer in display_messages function
    free_messages(&chat_log);

    return 0;
}

void free_messages(Message **messages) {
    Message *current = *messages;
    Message *next_message;

    while (current != NULL) {
        next_message = current->next;
        free(current->content);
        free(current);
        current = next_message;
    }

    *messages = NULL;
}
