#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    char message[100];
    char* next;
} Message;

Message* head = NULL;
Message* current = NULL;

void add_message(char* name, char* message) {
    Message* new_message = (Message*) malloc(sizeof(Message));
    strcpy(new_message->name, name);
    strcpy(new_message->message, message);
    new_message->next = NULL;

    if (head == NULL) {
        head = new_message;
        current = head;
    } else {
        current->next = new_message;
        current = current->next;
    }
}

void print_chat() {
    Message* temp = head;
    while (temp != NULL) {
        printf("%s: %s\n", temp->name, temp->message);
        temp = temp->next;
    }
}

int main() {
    char name1[20] = "John";
    char message1[100] = "Hello, this is John!";
    char message2[100] = "This is not a secure chat program! Don't use it for sensitive data!";
    add_message(name1, message1);
    add_message(NULL, message2); // Invalidate pointer
    print_chat();
    return 0;
}
