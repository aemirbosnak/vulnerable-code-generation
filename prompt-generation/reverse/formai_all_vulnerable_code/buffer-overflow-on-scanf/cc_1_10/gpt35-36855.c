//FormAI DATASET v1.0 Category: Email Client ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_EMAILS 1000
#define MAX_SENDER_LENGTH 50
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

struct email {
    char sender[MAX_SENDER_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
};

void print_menu() {
    printf("\nWelcome to C Email Client\n");
    printf("========================\n");
    printf("1. Compose Email\n");
    printf("2. Read Emails\n");
    printf("3. Exit\n");
}

void compose_email(struct email inbox[], int* num_emails) {
    if (*num_emails == MAX_EMAILS) {
        printf("Maximum number of emails reached. Please delete an email to make room for a new one.\n");
        return;
    }
    printf("\nEnter sender name: ");
    scanf("%s", inbox[*num_emails].sender);
    printf("Enter email subject: ");
    scanf("%s", inbox[*num_emails].subject);
    printf("Enter email message: ");
    scanf("%s", inbox[*num_emails].message);
    (*num_emails)++;
}

void read_emails(struct email inbox[], int num_emails) {
    if (num_emails == 0) {
        printf("Inbox is empty.\n");
        return;
    }
    for (int i = 0; i < num_emails; i++) {
        printf("\nEmail %d:\n", i+1);
        printf("Sender: %s\n", inbox[i].sender);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Message: %s\n", inbox[i].message);
    }
}

int main() {
    struct email inbox[MAX_EMAILS];
    int num_emails = 0;
    int choice;
    do {
        print_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                compose_email(inbox, &num_emails);
                break;
            case 2:
                read_emails(inbox, num_emails);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}