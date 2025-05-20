#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

typedef struct Message {
    char message[BUFFER_SIZE];
    struct Message *next;
} Message;

Message *head = NULL;

void add_message(char *message) {
    Message *new_msg = (Message *) malloc(sizeof(Message));
    strcpy(new_msg->message, message);
    new_msg->next = head;
    head = new_msg;
}

void print_messages() {
    Message *current = head;
    while (current != NULL) {
        printf("%s\n", current->message);
        current = current->next;
    }
}

int main() {
    char *messages[3] = {"Hello, World!", "I'm a chat message buffer manager application.", NULL};

    for (int i = 0; i < 3; i++) {
        add_message(messages[i]);
    }

    print_messages();

    // Intentionally dereferencing a null pointer
    printf("%s\n", head->next->message);

    return 0;
}
