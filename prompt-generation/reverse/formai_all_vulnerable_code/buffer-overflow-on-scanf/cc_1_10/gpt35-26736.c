//FormAI DATASET v1.0 Category: Email Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 50
#define MAX_SUBJECT_LEN 100
#define MAX_MESSAGE_LEN 500

struct email {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
};

int num_emails = 0;
struct email inbox[MAX_EMAILS];

void send_email(char *sender, char *recipient, char *subject, char *message) {
    if(num_emails < MAX_EMAILS) {
        strcpy(inbox[num_emails].sender, sender);
        strcpy(inbox[num_emails].recipient, recipient);
        strcpy(inbox[num_emails].subject, subject);
        strcpy(inbox[num_emails].message, message);
        num_emails++;
        printf("Email sent!\n");
    } else {
        printf("Error: inbox is full.\n");
    }
}

int main() {
    int option = -1;
    while(option != 0) {
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        if(option == 1) {
            char sender[50], recipient[50], subject[MAX_SUBJECT_LEN], message[MAX_MESSAGE_LEN];
            printf("Compose Email:\n");
            printf("From: ");
            scanf("%s", sender);
            printf("To: ");
            scanf("%s", recipient);
            printf("Subject: ");
            scanf("%s", subject);
            printf("Message: ");
            scanf("%s", message);
            send_email(sender, recipient, subject, message);
        } else if(option == 2) {
            printf("Inbox:\n");
            for(int i = 0; i < num_emails; i++) {
                printf("From: %s\n", inbox[i].sender);
                printf("Subject: %s\n", inbox[i].subject);
                printf("Message: %s\n", inbox[i].message);
                printf("----------------------------\n");
            }
        }
    }
    return 0;
}