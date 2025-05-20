#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 10
#define MAX_CHARS 200

typedef struct Message {
    char text[MAX_CHARS];
    struct Message *next;
} Message;

Message *head = NULL;
Message *current = NULL;

void add_message(char *message) {
    Message *new_msg = (Message *)malloc(sizeof(Message));
    if (!new_msg) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    strcpy(new_msg->text, message);
    new_msg->next = NULL;

    if (!head) {
        head = new_msg;
        current = head;
    } else {
        current->next = new_msg;
        current = current->next;
    }
}

void print_messages() {
    Message *temp = head;
    while (temp) {
        printf("%s\n", temp->text);
        temp = temp->next;
    }
}

void process_input() {
    char input[MAX_CHARS];
    printf("Enter your chat message: ");
    fgets(input, MAX_CHARS, stdin);

    add_message(input);
}

int main() {
    process_input();
    print_messages();

    current->next = head; // DEREFERENCE FAILURE (Invalid pointer)

    return 0;
}
