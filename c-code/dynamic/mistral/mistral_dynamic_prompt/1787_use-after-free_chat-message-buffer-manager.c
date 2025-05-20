#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ChatMessage {
    char* message;
    struct ChatMessage* next;
} Message;

Message* head = NULL;

void addMessage(char* msg) {
    Message* new_msg = (Message*)malloc(sizeof(Message));
    new_msg->message = (char*)malloc(strlen(msg) + 1);
    strcpy(new_msg->message, msg);
    new_msg->next = head;
    head = new_msg;
}

void displayMessages() {
    Message* temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->message);
        temp = temp->next;
    }
}

void freeChatMessages() {
    Message* temp = head;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->message);
        free(temp);
    }
    head = NULL;
}

int main() {
    int i;
    char input[100];

    printf("Chat Message Buffer Manager\n");
    printf("Enter messages, type 'quit' to exit.\n");

    for (i = 0; i < 100; i++) {
        printf("> ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) break;
        addMessage(input);
    }

    displayMessages();
    freeChatMessages();

    return 0;
}
