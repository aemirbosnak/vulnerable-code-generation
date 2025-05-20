//FormAI DATASET v1.0 Category: Email Client ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_EMAILS 10
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 1000
#define MAX_EMAIL_LENGTH 30

struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char recipient[MAX_EMAIL_LENGTH];
    bool is_read;
};

int main() {
    // Initialize email array
    struct email emails[MAX_EMAILS];
    for (int i = 0; i < MAX_EMAILS; i++) {
        strcpy(emails[i].subject, "");
        strcpy(emails[i].body, "");
        strcpy(emails[i].recipient, "");
        emails[i].is_read = false;
    }

    char option;
    int current_email_index = 0;
    bool quit = false;

    while (!quit) {
        printf("\n\n[C Email Client]\n");
        printf("Select an option:\n");
        printf("1. Compose email\n");
        printf("2. Read email\n");
        printf("3. List emails\n");
        printf("0. Quit\n\n");

        printf("> ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                if (current_email_index >= MAX_EMAILS) {
                    printf("No more space for emails.\n");
                    break;
                } else {
                    // Compose email
                    printf("Subject: ");
                    scanf(" %[^\n]s", emails[current_email_index].subject);

                    printf("Recipient: ");
                    scanf(" %[^\n]s", emails[current_email_index].recipient);

                    printf("Body:\n");
                    scanf(" %[^\n]s", emails[current_email_index].body);

                    printf("Email sent to %s.\n", emails[current_email_index].recipient);

                    current_email_index++;
                }
                break;
            case '2':
                // Read email
                printf("Enter email index: ");
                int email_index;
                scanf("%d", &email_index);

                if (email_index > current_email_index) {
                    printf("Email not found.\n");
                    break;
                } else {
                    printf("\n\nSubject:\n%s\n\n", emails[email_index].subject);
                    printf("Body:\n%s\n\n", emails[email_index].body);
                    emails[email_index].is_read = true;
                }
                break;
            case '3':
                // List emails
                printf("\n\n[Inbox]\n");
                for (int i = 0; i < current_email_index; i++) {
                    printf("%d. %s\n", i, emails[i].subject);
                }
                break;
            case '0':
                // Quit program
                printf("\nGoodbye.\n");
                quit = true;
                break;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}