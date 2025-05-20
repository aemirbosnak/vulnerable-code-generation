//Falcon-180B DATASET v1.0 Category: Email Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

// Struct to hold email data
typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

// Function to print an email
void print_email(Email *email) {
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
    printf("Timestamp: %s\n", ctime(&email->timestamp));
}

// Function to send an email
void send_email(Email *email) {
    // Code to actually send the email goes here
    printf("Email sent successfully!\n");
}

// Function to receive an email
Email receive_email() {
    Email email;
    printf("Enter subject (max %d characters): ", MAX_SUBJECT_LENGTH - 1);
    scanf("%[^\n]", email.subject);
    email.subject[strcspn(email.subject, "\n")] = '\0';

    printf("Enter body (max %d characters): ", MAX_BODY_LENGTH - 1);
    scanf("%[^\n]", email.body);
    email.body[strcspn(email.body, "\n")] = '\0';

    time(&email.timestamp);
    return email;
}

// Main function
int main() {
    Email email;

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Send email\n");
        printf("2. Receive email\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Code to send email goes here
            break;
        case 2:
            email = receive_email();
            print_email(&email);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}