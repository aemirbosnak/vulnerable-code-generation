//FormAI DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_EMAILS 100

typedef struct Email {
    char sender[MAX_BUFFER_SIZE];
    char recipient[MAX_BUFFER_SIZE];
    char subject[MAX_BUFFER_SIZE];
    char message[MAX_BUFFER_SIZE];
} Email;

void add_email(Email emails[], int *num_emails) {
    Email email;
    printf("Enter sender: ");
    scanf("%s", email.sender);
    printf("Enter recipient: ");
    scanf("%s", email.recipient);
    printf("Enter subject: ");
    scanf("%s", email.subject);
    printf("Enter message: ");
    scanf("%s", email.message);

    emails[*num_emails] = email;
    (*num_emails)++;
}

void delete_email(Email emails[], int *num_emails, char recipient[MAX_BUFFER_SIZE], int index) {
    if (strcmp(emails[index].recipient, recipient) == 0) {
        for (int i = index; i < *num_emails - 1; i++) {
            emails[i] = emails[i+1];
        }
        (*num_emails)--;
    }
}

void display_emails(Email emails[], int num_emails, char recipient[MAX_BUFFER_SIZE]) {
    for (int i = 0; i < num_emails; i++) {   
        if (strcmp(emails[i].recipient, recipient) == 0) {
            printf("\nSender: %s\nRecipient: %s\nSubject: %s\nMessage: %s\n", 
                emails[i].sender, emails[i].recipient, emails[i].subject, emails[i].message);
        }
    }
}

int main() {
    Email emails[MAX_EMAILS];
    int num_emails = 0;
    int choice;
    char recipient[MAX_BUFFER_SIZE];
    int index;

    do {
        printf("\nMenu Options:\n");
        printf("1. Add email\n");
        printf("2. Delete email\n");
        printf("3. Display emails\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email(emails, &num_emails);
                break;
            case 2:
                printf("Enter recipient of email to delete: ");
                scanf("%s", recipient);

                for (int i = 0; i < num_emails; i++) {
                    delete_email(emails, &num_emails, recipient, i);
                }
                break;
            case 3:
                printf("Enter recipient of emails to display: ");
                scanf("%s", recipient);

                display_emails(emails, num_emails, recipient);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}