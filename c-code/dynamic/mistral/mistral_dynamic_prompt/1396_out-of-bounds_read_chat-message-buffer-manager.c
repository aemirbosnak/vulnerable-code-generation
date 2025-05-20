#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define NUM_MESSAGES 10

struct Message {
    char message[BUFFER_SIZE];
    struct Message *next;
};

void display_messages(struct Message *head) {
    struct Message *current = head;
    while (current != NULL) {
        printf("%s\n", current->message);
        current = current->next;
    }
}

void add_message(struct Message **head, const char *message) {
    struct Message *new_message = (struct Message *)malloc(sizeof(struct Message));
    strncpy(new_message->message, message, BUFFER_SIZE);
    new_message->next = *head;
    *head = new_message;
}

int main(int argc, char *argv[]) {
    struct Message *messages = NULL;

    if (argc < 2) {
        printf("Usage: %s <chat_message>\n", argv[0]);
        return 1;
    }

    int i;
    for (i = 1; i < argc; i++) {
        add_message(&messages, argv[i]);
    }

    char user_input[BUFFER_SIZE];
    printf("Enter messages to add (Type -1 to stop):\n");

    while (1) {
        fgets(user_input, BUFFER_SIZE, stdin);
        int len = strlen(user_input);
        if (user_input[len - 1] == '\n') {
            user_input[len - 1] = '\0';
            len--;
        }

        if (atoi(user_input) == -1) {
            break;
        }

        add_message(&messages, user_input);
    }

    display_messages(messages);

    return 0;
}
