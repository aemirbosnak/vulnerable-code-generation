//Gemma-7B DATASET v1.0 Category: Email Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 10

typedef struct Message {
    char sender[50];
    char recipient[50];
    char subject[50];
    char message[2000];
} Message;

Message messages[MAX_MESSAGES];

void display_messages(void) {
    int i = 0;
    for (i = 0; i < MAX_MESSAGES && messages[i].sender[0] != '\0'; i++) {
        printf("From: %s\n", messages[i].sender);
        printf("To: %s\n", messages[i].recipient);
        printf("Subject: %s\n", messages[i].subject);
        printf("Message: %s\n", messages[i].message);
        printf("\n");
    }
}

void add_message(void) {
    int i = 0;
    for (i = 0; i < MAX_MESSAGES && messages[i].sender[0] != '\0'; i++) {}
    messages[i].sender[0] = '\0';
    messages[i].recipient[0] = '\0';
    messages[i].subject[0] = '\0';
    messages[i].message[0] = '\0';

    printf("Enter the sender's name: ");
    scanf("%s", messages[i].sender);

    printf("Enter the recipient's name: ");
    scanf("%s", messages[i].recipient);

    printf("Enter the subject: ");
    scanf("%s", messages[i].subject);

    printf("Enter the message: ");
    scanf("%s", messages[i].message);

    printf("Message added successfully!\n");
}

int main(void) {
    display_messages();
    add_message();
    display_messages();

    return 0;
}