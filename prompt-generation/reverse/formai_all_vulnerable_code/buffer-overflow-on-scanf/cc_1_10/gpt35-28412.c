//FormAI DATASET v1.0 Category: Email Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000

// struct for an email message
typedef struct email {
    char sender[100];
    char recipient[100];
    char subject[200];
    char body[1000];
} email;

// array to hold all emails
email inbox[MAX_EMAILS];
int num_emails = 0;

// function to send a new email
void send_email() {
    email new_email;

    // get recipient's email address
    printf("Enter recipient's email address: ");
    scanf("%s", new_email.recipient);

    // get subject of email
    printf("Enter subject of email: ");
    getchar(); // clear buffer before reading string
    fgets(new_email.subject, 200, stdin);

    // get body of email
    printf("Enter body of email: ");
    fgets(new_email.body, 1000, stdin);

    // add sender's email address to new email
    strcpy(new_email.sender, "user@example.com");

    // add new email to inbox
    inbox[num_emails++] = new_email;

    printf("Email sent successfully\n");
}

// function to display all emails in inbox
void view_inbox() {
    if (num_emails == 0) {
        printf("No emails in inbox\n");
    } else {
        printf("Inbox:\n");
        for (int i = 0; i < num_emails; i++) {
            printf("From: %s\n", inbox[i].sender);
            printf("To: %s\n", inbox[i].recipient);
            printf("Subject: %s", inbox[i].subject);
            printf("Body: %s\n", inbox[i].body);
            printf("\n");
        }
    }
}

// main function
int main() {
    int choice;

    do {
        // display menu to user
        printf("\n\n*** Email Client Menu ***\n");
        printf("1. Send Email\n");
        printf("2. View Inbox\n");
        printf("3. Quit\n");
        printf("Enter choice: ");

        // get user's choice
        scanf("%d", &choice);

        // perform action based on user's choice
        switch (choice) {
            case 1: send_email(); break;
            case 2: view_inbox(); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}