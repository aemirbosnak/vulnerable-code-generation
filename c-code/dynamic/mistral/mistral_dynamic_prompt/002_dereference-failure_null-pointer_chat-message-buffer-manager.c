#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

struct ChatMessage {
    char message[BUFFER_SIZE];
    struct ChatMessage *next;
};

void add_message(struct ChatMessage **head_ref, char *str) {
    struct ChatMessage *new_message = (struct ChatMessage *)malloc(sizeof(struct ChatMessage));
    new_message->next = *head_ref;
    strcpy(new_message->message, str);
    *head_ref = new_message;
}

void print_messages(struct ChatMessage *node) {
    while (node != NULL) {
        printf("%s\n", node->message);
        node = node->next;
    }
}

int main() {
    struct ChatMessage *head = NULL;
    char input[BUFFER_SIZE];

    printf("Chat Message Buffer Manager\n");
    printf("Enter messages. Type 'END' to stop.\n");

    for (;;) {
        fgets(input, BUFFER_SIZE, stdin);
        if (strcmp(input, "END\n") == 0)
            break;

        add_message(&head, input);
    }

    print_messages(head);

    struct ChatMessage *current = head;
    while (current != NULL) {
        struct ChatMessage *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
