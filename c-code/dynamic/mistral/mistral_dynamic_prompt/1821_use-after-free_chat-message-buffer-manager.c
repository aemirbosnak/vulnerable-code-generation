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

void add_message(Message **head, char *message) {
    Message *new_message = (Message *)malloc(sizeof(Message));
    new_message->content = (char *)malloc(strlen(message) * sizeof(char));
    strcpy(new_message->content, message);
    new_message->next = *head;
    *head = new_message;
}

void print_messages(Message *head) {
    Message *current = head;
    while (current != NULL) {
        printf("%s\n", current->content);
        current = current->next;
    }
}

void free_messages(Message **head) {
    Message *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp->content);
        free(temp);
    }
}

int main() {
    Message *messages = NULL;

    add_message(&messages, "Hello, World!");
    add_message(&messages, "This is a simple chat message buffer manager tool.");
    add_message(&messages, "Remember, this program has no bounds checks or safety features.");
    add_message(&messages, "Happy hacking!");

    print_messages(messages);

    free(messages->content);
    messages = NULL;

    add_message(&messages, "A new message has been added after freeing the previous list.");
    print_messages(messages);

    free_messages(&messages);

    return 0;
}
