#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define NUM_MESSAGES 10

struct message {
    char buffer[BUFFER_SIZE];
    struct message *next;
};

struct message *head = NULL;

void add_message(char *message) {
    struct message *new_message = (struct message *) malloc(sizeof(struct message));
    strcpy(new_message->buffer, message);
    new_message->next = head;
    head = new_message;
}

void print_messages() {
    struct message *temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->buffer);
        temp = temp->next;
    }
}

void send_message(int index) {
    struct message *temp = head;
    for (int i = 0; i < index; i++) {
        if (temp == NULL) {
            printf("Invalid index.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Message: %s\n", temp->buffer);
    free(head);
    head = temp;
    struct message *iterator;
    while (temp->next != NULL) {
        iterator = temp;
        temp = temp->next;
        free(iterator);
    }
}

int main() {
    add_message("Hello, World!");
    add_message("This is a simple chat buffer manager tool.");
    add_message("Please, do not forget to break its security on purpose.");
    add_message("Remember, there's no safety checks or bounds validation.");
    add_message("Have fun exploring the code!");

    print_messages();
    send_message(3);
    print_messages();

    return 0;
}
