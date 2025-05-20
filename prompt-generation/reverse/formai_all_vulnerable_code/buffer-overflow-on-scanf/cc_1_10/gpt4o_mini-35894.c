//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_SIZE 256

typedef struct {
    char sender[EMAIL_SIZE];
    char recipient[EMAIL_SIZE];
    char subject[EMAIL_SIZE];
    char body[EMAIL_SIZE * 2];
} Email;

Email email_list[MAX_EMAILS];
int email_count = 0;

void send_email() {
    if (email_count >= MAX_EMAILS) {
        printf("Email limit reached. Cannot send more emails.\n");
        return;
    }

    Email new_email;
    printf("Enter sender's email: ");
    scanf("%s", new_email.sender);
    printf("Enter recipient's email: ");
    scanf("%s", new_email.recipient);
    printf("Enter subject: ");
    scanf(" %[^\n]", new_email.subject); // Read string with spaces
    printf("Enter body: ");
    scanf(" %[^\n]", new_email.body);

    email_list[email_count] = new_email;
    email_count++;
    printf("Email sent successfully!\n");
}

void read_email() {
    if (email_count == 0) {
        printf("No emails to read.\n");
        return;
    }

    for (int i = 0; i < email_count; i++) {
        printf("\n---- Email %d ----\n", i + 1);
        printf("From: %s\n", email_list[i].sender);
        printf("To: %s\n", email_list[i].recipient);
        printf("Subject: %s\n", email_list[i].subject);
        printf("Body: %s\n", email_list[i].body);
    }
}

void list_emails() {
    if (email_count == 0) {
        printf("No emails in the system.\n");
        return;
    }

    printf("You have %d email(s):\n", email_count);
    for (int i = 0; i < email_count; i++) {
        printf("%d. %s - %s: %s\n", i + 1, email_list[i].sender, email_list[i].recipient, email_list[i].subject);
    }
}

void clear_emails() {
    email_count = 0;
    printf("All emails cleared.\n");
}

void display_menu() {
    printf("\nEmail Client Menu:\n");
    printf("1. Send Email\n");
    printf("2. Read Emails\n");
    printf("3. List Emails\n");
    printf("4. Clear All Emails\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                send_email();
                break;
            case 2:
                read_email();
                break;
            case 3:
                list_emails();
                break;
            case 4:
                clear_emails();
                break;
            case 5:
                printf("Exiting the Email Client. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}