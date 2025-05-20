#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

typedef struct ChatMessage {
    char message[BUFFER_SIZE];
    struct ChatMessage *next;
} Message;

Message *head = NULL;

void append_message(char *message) {
    Message *new_msg = (Message *) malloc(sizeof(Message));
    strcpy(new_msg->message, message);
    new_msg->next = NULL;

    if (head == NULL) {
        head = new_msg;
    } else {
        Message *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_msg;
    }
}

void print_messages() {
    Message *temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->message);
        temp = temp->next;
    }
}

void free_messages() {
    Message *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    append_message("Hello, World!");
    append_message("Let's chat!");
    print_messages();

    // Free the first message but keep a pointer to it
    Message *first_message = head;
    free_messages();
    head = first_message;

    print_messages(); // Use the now-freed memory

    return 0;
}
