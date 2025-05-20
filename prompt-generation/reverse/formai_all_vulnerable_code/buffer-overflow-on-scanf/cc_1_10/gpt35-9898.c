//FormAI DATASET v1.0 Category: Email Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of each field in the email
#define MAX_SUBJECT_SIZE 100
#define MAX_BODY_SIZE 1000
#define MAX_EMAILS 100

struct Email {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_BODY_SIZE];
};

// Global array of emails
struct Email emails[MAX_EMAILS];

// Global counter for the number of emails
int email_count = 0;

// Function to add an email to the global array
void add_email() {
    struct Email new_email;
    printf("New Email:\n");
    printf("From: ");
    scanf("%s", new_email.sender);
    printf("To: ");
    scanf("%s", new_email.recipient);
    printf("Subject: ");
    scanf("%s", new_email.subject);
    printf("Body: ");
    scanf("%s", new_email.body);
    emails[email_count++] = new_email;
    printf("Email added successfully.\n");
}

// Function to print all emails in the global array
void print_emails() {
    printf("Emails:\n");
    for (int i = 0; i < email_count; i++) {
        printf("Email %d:\n", i + 1);
        printf("From: %s\n", emails[i].sender);
        printf("To: %s\n", emails[i].recipient);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n", emails[i].body);
        printf("--------------------\n");
    }
}

int main() {
    printf("Welcome to the C Email Client!\n\n");

    // Loop until the user chooses to exit
    while (1) {
        printf("Options:\n");
        printf("1. Compose New Email\n");
        printf("2. View Inbox\n");
        printf("3. Exit\n");
        printf("Enter Selection: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                print_emails();
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid selection. Please try again.\n");
        }
    }
    return 0;
}