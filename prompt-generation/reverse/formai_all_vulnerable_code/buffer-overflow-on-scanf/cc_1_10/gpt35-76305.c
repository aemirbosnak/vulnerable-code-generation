//FormAI DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LEN 50
#define MAX_BODY_LEN 500

struct Email {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
};

struct Email inbox[MAX_EMAILS];
int num_emails = 0;

void send_email() {
    struct Email new_email;

    printf("Enter sender name: ");
    scanf("%s", new_email.sender);

    printf("Enter recipient name: ");
    scanf("%s", new_email.recipient);

    printf("Enter email subject: ");
    fgets(new_email.subject, MAX_SUBJECT_LEN, stdin);

    printf("Enter email body: ");
    fgets(new_email.body, MAX_BODY_LEN, stdin);

    inbox[num_emails++] = new_email;

    printf("Email sent successfully!\n");
}

void view_email() {
    int email_num;

    printf("Enter the number of the email you would like to view: ");
    scanf("%d", &email_num);

    if (email_num >= num_emails) {
        printf("Not a valid email number. Please enter a number between 0 and %d.\n", num_emails - 1);
        return;
    }

    struct Email selected_email = inbox[email_num];

    printf("Sender: %s\n", selected_email.sender);
    printf("Recipient: %s\n", selected_email.recipient);
    printf("Subject: %s\n", selected_email.subject);
    printf("Body: %s\n", selected_email.body);
}

int main() {
    int choice;

    while (1) {
        printf("1. Send email\n");
        printf("2. View email\n\n");
        printf("Enter choice (1-2): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                send_email();
                break;
            case 2:
                view_email();
                break;
            default:
                printf("Not a valid choice. Please enter 1 or 2.\n\n");
                break;
        }
    }

    return 0;
}