//FormAI DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_EMAIL_BODY_LENGTH 1000

// Function prototypes
void readEmail(char *to, char *subject, char *emailBody);
void sendEmail(char *to, char *subject, char *emailBody);
void printEmail(char *to, char *subject, char *emailBody);

int main() {
    char to[50], subject[MAX_SUBJECT_LENGTH], emailBody[MAX_EMAIL_BODY_LENGTH];
    int choice;

    printf("Welcome to the Email Client!\n\n");

    do {
        printf("What would you like to do?\n");
        printf("1. Read an email\n");
        printf("2. Send an email\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readEmail(to, subject, emailBody);
                printEmail(to, subject, emailBody);
                break;
            case 2:
                readEmail(to, subject, emailBody);
                sendEmail(to, subject, emailBody);
                break;
            case 3:
                printf("Exiting Email Client. Goodbye!");
                break;
            default:
                printf("Invalid Choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Read an email from the user
void readEmail(char *to, char *subject, char *emailBody) {
    printf("\nEnter the recipient email address: ");
    scanf("%s", to);

    printf("Enter the email subject (Max %d characters) : ", MAX_SUBJECT_LENGTH);
    scanf("%s", subject);

    printf("Enter the email body (Max %d characters) : ", MAX_EMAIL_BODY_LENGTH);
    scanf(" %[^\n]s", emailBody);
}

// Send an email to the user
void sendEmail(char *to, char *subject, char *emailBody) {
    printf("\nSending Email...\n");
    printf("To: %s\n", to);
    printf("Subject: %s\n", subject);
    printf("Email Body: %s\n", emailBody);
}

// Print the email to the user
void printEmail(char *to, char *subject, char *emailBody) {
    printf("\nEmail Details:\n");
    printf("To: %s\n", to);
    printf("Subject: %s\n", subject);
    printf("Email Body: %s\n", emailBody);
}