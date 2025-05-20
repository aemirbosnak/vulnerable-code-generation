//Gemma-7B DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <string.h>

#define MAX_MESSAGES 10

typedef struct Message {
    char *subject;
    char *body;
    struct Message *next;
} Message;

Message *addMessage(Message *head) {
    Message *new_message = malloc(sizeof(Message));
    new_message->subject = malloc(20);
    new_message->body = malloc(100);
    new_message->next = NULL;

    // Get the subject and body from the user
    printf("Enter the subject: ");
    scanf("%s", new_message->subject);

    printf("Enter the body: ");
    scanf("%[^\n]", new_message->body);

    // Add the new message to the head of the list
    if (head == NULL) {
        head = new_message;
    } else {
        new_message->next = head;
        head = new_message;
    }

    return head;
}

void printMessages(Message *head) {
    while (head) {
        printf("Subject: %s\n", head->subject);
        printf("Body: %s\n", head->body);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Message *head = NULL;

    // Add some messages to the list
    head = addMessage(head);
    addMessage(head);
    addMessage(head);

    // Print the messages
    printMessages(head);

    return 0;
}