//FormAI DATASET v1.0 Category: Email Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LEN 50
#define MAX_BODY_LEN 500
#define MAX_EMAIL_LEN 50

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    char email[MAX_EMAIL_LEN];
} Email;

Email inbox[MAX_EMAILS];
int num_emails = 0;

void read_email(int email_index) {
    printf("Email from: %s\n", inbox[email_index].email);
    printf("Subject: %s\n", inbox[email_index].subject);
    printf("Body: %s\n", inbox[email_index].body);
}

void compose_email() {
    Email new_email;
    printf("Enter recipient email address: ");
    scanf("%s", new_email.email);
    printf("Enter subject: ");
    scanf("%s", new_email.subject);
    printf("Enter body: ");
    scanf("%s", new_email.body);
    inbox[num_emails++] = new_email;
    printf("Email sent to %s\n", new_email.email);
}

int main() {
    int choice = -1;
    while (choice != 0) {
        printf("\nEmail menu:\n");
        printf("1. View Inbox\n");
        printf("2. Compose Email\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (num_emails == 0) {
                    printf("Inbox is empty!\n");
                } else {
                    printf("You have %d emails in your inbox:\n", num_emails);
                    for (int i = 0; i < num_emails; i++) {
                        printf("Email %d:\n", i + 1);
                        read_email(i);
                    }
                }
                break;
            case 2:
                compose_email();
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}