#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Message {
    char *content;
    struct Message *next;
} Message;

void add_message(Message **head, char *msg) {
    Message *new_msg = (Message *)malloc(sizeof(Message));
    new_msg->content = (char *)malloc(sizeof(char) * 1024);
    strcpy(new_msg->content, msg);
    new_msg->next = *head;
    *head = new_msg;
}

void print_messages(Message *head) {
    Message *current = head;
    while (current != NULL) {
        printf("%s\n", current->content);
        current = current->next;
    }
}

int main() {
    Message *messages = NULL;

    char input[1024];
    for (int i = 0; i < 500; ++i) {
        printf("Enter a message (type 'quit' to exit): ");
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "quit\n") == 0)
            break;
        add_message(&messages, input);
    }

    print_messages(messages);

    Message *current = messages;
    while (current != NULL) {
        Message *temp = current;
        current = current->next;
        free(temp->content);
        free(temp);
    }

    return 0;
}
