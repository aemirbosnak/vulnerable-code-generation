//FormAI DATASET v1.0 Category: Email Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 2500
#define MAX_EMAILS 100

struct Email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char recipient[30];
    char sender[30];
};

int num_emails = 0;

void display_menu() {
    printf("\n----Email Client Application----\n");
    printf("1. Compose new email\n");
    printf("2. View sent emails\n");
    printf("3. View received emails\n");
    printf("4. Exit\n");
}

void compose_email(struct Email emails[MAX_EMAILS]) {
    char recipient[30], subject[MAX_SUBJECT_LENGTH], body[MAX_BODY_LENGTH];
    printf("\nEnter recipient name: ");
    scanf("%s", recipient);
    printf("Enter subject: ");
    scanf(" %[^\n]s", subject);
    printf("Enter message body:\n");
    scanf(" %[^\n]s", body);

    struct Email new_email;
    strcpy(new_email.sender, "Your Name");
    strcpy(new_email.recipient, recipient);
    strcpy(new_email.subject, subject);
    strcpy(new_email.body, body);

    emails[num_emails++] = new_email;
    printf("Email sent successfully!\n");
}

void view_emails(struct Email emails[MAX_EMAILS], bool sent) {
    printf("\n---%s Emails---\n", sent ? "Sent" : "Received");
    for(int i = 0; i < num_emails; i++) {
        if((sent && strcmp(emails[i].sender, "Your Name") == 0) || (!sent && strcmp(emails[i].recipient, "Your Name") == 0)) {
            printf("Subject: %s\n", emails[i].subject);
            printf("Body: %s\n", emails[i].body);
            printf("From: %s\n", emails[i].sender);
            printf("To: %s\n", emails[i].recipient);
            printf("\n");
        }
    }
}

int main() {
    struct Email emails[MAX_EMAILS];

    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                compose_email(emails);
                break;
            case 2:
                view_emails(emails, true);
                break;
            case 3:
                view_emails(emails, false);
                break;
            case 4:
                printf("Closing email client...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}