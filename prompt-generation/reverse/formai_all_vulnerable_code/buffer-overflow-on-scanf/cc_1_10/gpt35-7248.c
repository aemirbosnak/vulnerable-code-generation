//FormAI DATASET v1.0 Category: Email Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char sender[100];
    char receiver[100];
    char message[500];
} Email;

typedef struct {
    int size;
    Email *emails;
} Inbox;

Inbox *create_inbox() {
    Inbox *inbox = (Inbox *)malloc(sizeof(Inbox));
    inbox->size = 0;
    inbox->emails = NULL;
    return inbox;
}

void add_email(Inbox *inbox, Email email) {
    int size = inbox->size;
    inbox->emails = (Email *)realloc(inbox->emails, (size + 1) * sizeof(Email));
    inbox->emails[size] = email;
    inbox->size++;
}

void print_emails(Inbox *inbox, char receiver[100]) {
    int i;
    for (i = 0; i < inbox->size; i++) {
        if (strcmp(inbox->emails[i].receiver, receiver) == 0) {
            printf("Email #%d:\n", i+1);
            printf("Sender: %s\n", inbox->emails[i].sender);
            printf("Message: %s\n", inbox->emails[i].message);
            printf("------------------\n");
        }
    }
}

int main() {
    char sender[100];
    char receiver[100];
    char message[500];
    int option;
    Inbox *inbox = create_inbox();

    do {
        printf("Welcome to My Email Client\n");
        printf("[1] Send Email\n");
        printf("[2] View Inbox\n");
        printf("[3] Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter Sender Email: ");
                scanf("%s", sender);
                printf("Enter Receiver Email: ");
                scanf("%s", receiver);
                printf("Enter Message: ");
                scanf("%s", message);

                Email email;
                strcpy(email.sender, sender);
                strcpy(email.receiver, receiver);
                strcpy(email.message, message);
                add_email(inbox, email);

                printf("Email Sent!\n");
                break;
            case 2:
                printf("Enter Email to View Inbox: ");
                scanf("%s", receiver);
                print_emails(inbox, receiver);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Option!\n");
                break;
        }
    } while (option != 3);

    return 0;
}