#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Message {
    char content[1024];
    struct Message *next;
} Message;

void read_message(Message **head) {
    Message *new_message = (Message*)malloc(sizeof(Message));
    printf("Enter your chat message: ");
    fgets(new_message->content, 1024, stdin);
    new_message->next = *head;
    *head = new_message;
}

void display_messages(Message *head) {
    Message *current = head;
    while (current != NULL) {
        printf("%s", current->content);
        current = current->next;
    }
}

int main() {
    Message *messages_list = NULL;

    read_message(&messages_list);
    read_message(&messages_list);
    read_message(&messages_list);

    display_messages(messages_list);

    // Dereference failure example
    printf("%s\n", messages_list->content);

    return 0;
}
