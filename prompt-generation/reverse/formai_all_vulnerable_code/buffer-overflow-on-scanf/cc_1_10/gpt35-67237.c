//FormAI DATASET v1.0 Category: Email Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_LENGTH 1024
#define MAX_EMAILS 100

typedef struct {
    char* sender;
    char* receiver;
    char* subject;
    char* body;
} Email;

void printMenu() {
    printf("1. Send email\n");
    printf("2. View inbox\n");
    printf("3. Exit\n");
    printf("Enter an option: ");
}

void sendEmail(Email** emails, int* numEmails) {
    char* sender = malloc(MAX_BUFFER_LENGTH * sizeof(char));
    char* receiver = malloc(MAX_BUFFER_LENGTH * sizeof(char));
    char* subject = malloc(MAX_BUFFER_LENGTH * sizeof(char));
    char* body = malloc(MAX_BUFFER_LENGTH * sizeof(char));

    printf("Sender: ");
    scanf("%s", sender);
    printf("Receiver: ");
    scanf("%s", receiver);
    printf("Subject: ");
    scanf("%s", subject);
    printf("Body: ");
    scanf("%s", body);

    Email* email = malloc(sizeof(Email));
    email->sender = sender;
    email->receiver = receiver;
    email->subject = subject;
    email->body = body;

    emails[*numEmails] = email;
    (*numEmails)++;

    printf("\nEmail sent!\n\n");
}

void viewInbox(Email** emails, int numEmails) {
    if (numEmails == 0) {
        printf("\nNo emails to show.\n\n");
        return;
    }

    printf("\n");

    for (int i = 0; i < numEmails; i++) {
        printf("Email %d:\n", i + 1);
        printf("Sender: %s\n", emails[i]->sender);
        printf("Receiver: %s\n", emails[i]->receiver);
        printf("Subject: %s\n", emails[i]->subject);
        printf("Body: %s\n\n", emails[i]->body);
    }
}

int main() {
    Email** emails = malloc(MAX_EMAILS * sizeof(Email*));
    int numEmails = 0;

    int option = 0;
    while(option != 3) {
        printMenu();
        scanf("%d", &option);

        switch(option) {
            case 1:
                sendEmail(emails, &numEmails);
                break;
            case 2:
                viewInbox(emails, numEmails);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option. Try again.\n\n");
                break;
        }
    }

    return 0;
}