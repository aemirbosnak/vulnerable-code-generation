#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

typedef struct Message {
    char data[BUFFER_SIZE];
    struct Message *next;
} Message;

void append_message(Message **head, const char *message) {
    Message *new_message = (Message *)malloc(sizeof(Message));
    strcpy(new_message->data, message);
    new_message->next = *head;
    *head = new_message;
}

void print_messages(Message *head) {
    Message *current = head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main() {
    Message *chat_history = NULL;

    append_message(&chat_history, "Hello, world!");
    append_message(&chat_history, NULL); // Dereference failure

    print_messages(chat_history);

    return 0;
}
