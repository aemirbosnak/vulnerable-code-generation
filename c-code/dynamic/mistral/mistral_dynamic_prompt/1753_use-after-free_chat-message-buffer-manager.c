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

Message *head = NULL;

void add_message(char *message) {
    Message *new_msg = (Message*) malloc(sizeof(Message));
    new_msg->content = (char*) malloc(strlen(message) + 1);
    strcpy(new_msg->content, message);
    new_msg->next = head;
    head = new_msg;
}

void print_messages() {
    Message *current = head;
    while (current != NULL) {
        printf("%s\n", current->content);
        current = current->next;
    }
}

void free_messages() {
    Message *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->content);
        free(temp);
    }
    head = NULL;
}

int main() {
    add_message("Hello, world!");
    add_message("How's it going?");
    add_message("I'm doing well, thanks for asking.");

    print_messages();

    // free memory allocated for first message (use after free)
    free(head->content);

    add_message("What's new?");
    print_messages();

    free_messages();

    return 0;
}
