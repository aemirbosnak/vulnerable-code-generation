//FormAI DATASET v1.0 Category: Email Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LEN 50
#define MAX_BODY_LEN 1000

typedef struct Email {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
} Email;

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    Email inbox[MAX_EMAILS]; // array to store emails
    int email_count = 0; // keeps track of number of emails
    int choice;

    printf("Welcome to the C Email Client!\n");

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Send an email\n");
        printf("2. View inbox\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1: // Send an email
                if (email_count >= MAX_EMAILS) {
                    printf("Inbox full.\n");
                    break;
                }

                // Get input from user
                printf("\nEnter sender's email address:\n");
                fgets(inbox[email_count].sender, 50, stdin);
                inbox[email_count].sender[strcspn(inbox[email_count].sender, "\n")] = '\0';

                printf("Enter recipient's email address:\n");
                fgets(inbox[email_count].recipient, 50, stdin);
                inbox[email_count].recipient[strcspn(inbox[email_count].recipient, "\n")] = '\0';

                printf("Enter subject of email:\n");
                fgets(inbox[email_count].subject, MAX_SUBJECT_LEN, stdin);
                inbox[email_count].subject[strcspn(inbox[email_count].subject, "\n")] = '\0';

                printf("Enter body of email:\n");
                fgets(inbox[email_count].body, MAX_BODY_LEN, stdin);
                inbox[email_count].body[strcspn(inbox[email_count].body, "\n")] = '\0';

                printf("Email sent successfully!\n");
                email_count++;
                break;

            case 2: // View inbox
                if (email_count == 0) {
                    printf("Inbox empty.\n");
                    break;
                }

                // Print all emails in inbox
                printf("\n--- INBOX ---\n");
                for (int i = 0; i < email_count; i++) {
                    printf("\nEmail %d:\n", i+1);
                    printf("From: %s\n", inbox[i].sender);
                    printf("To: %s\n", inbox[i].recipient);
                    printf("Subject: %s\n", inbox[i].subject);
                    printf("Body: %s\n", inbox[i].body);
                }
                break;

            case 3: // Exit
                printf("\nGoodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    return 0;
}