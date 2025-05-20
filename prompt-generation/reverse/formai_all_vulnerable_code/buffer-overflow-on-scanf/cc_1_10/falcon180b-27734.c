//Falcon-180B DATASET v1.0 Category: Email Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 1024

typedef struct {
    char subject[MAX_EMAIL_LENGTH];
    char sender[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Email inbox is full.\n");
        return;
    }

    printf("Enter email subject: ");
    scanf("%s", emails[num_emails].subject);

    printf("Enter email sender: ");
    scanf("%s", emails[num_emails].sender);

    printf("Enter email body: ");
    scanf("%s", emails[num_emails].body);

    num_emails++;
}

void view_emails() {
    if (num_emails == 0) {
        printf("No emails in inbox.\n");
        return;
    }

    printf("Email inbox:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("Subject: %s\nSender: %s\nBody:\n%s\n\n", emails[i].subject, emails[i].sender, emails[i].body);
    }
}

int main() {
    printf("Welcome to the retro email client!\n");

    while (1) {
        printf("Choose an option:\n");
        printf("1. Add email\n2. View emails\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                view_emails();
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}