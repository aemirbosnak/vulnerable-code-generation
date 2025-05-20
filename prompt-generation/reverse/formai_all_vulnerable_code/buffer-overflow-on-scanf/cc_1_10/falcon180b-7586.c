//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

// Struct to hold email data
typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

// Function to read in an email from the user
void readEmail(Email *email) {
    printf("Enter email subject (max %d characters): ", MAX_SUBJECT_LENGTH - 1);
    fgets(email->subject, MAX_SUBJECT_LENGTH, stdin);
    email->subject[strcspn(email->subject, "\n")] = '\0'; // Remove newline character

    printf("Enter email body (max %d characters): ", MAX_BODY_LENGTH - 1);
    fgets(email->body, MAX_BODY_LENGTH, stdin);
    email->body[strcspn(email->body, "\n")] = '\0'; // Remove newline character
}

// Function to print an email
void printEmail(Email email) {
    printf("Subject: %s\n", email.subject);
    printf("Body: %s\n", email.body);
}

// Function to send an email
void sendEmail(Email email) {
    // TODO: Implement sending email functionality
}

// Main function
int main() {
    Email email;

    while (1) {
        printf("\n");
        printf("1. Read email\n");
        printf("2. Send email\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            readEmail(&email);
            printEmail(email);
            break;
        case 2:
            sendEmail(email);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}