//FormAI DATASET v1.0 Category: Email Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100 // Maximum number of emails that can be stored
#define MAX_SUBJECT_LENGTH 50 // Maximum length of subject for each email
#define MAX_BODY_LENGTH 1000 // Maximum length of body for each email
#define MAX_EMAIL_LENGTH (MAX_SUBJECT_LENGTH + MAX_BODY_LENGTH + 20) // Maximum length of email including header

// Structure to hold information about an email
typedef struct email {
   char sender[MAX_EMAIL_LENGTH];
   char recipient[MAX_EMAIL_LENGTH];
   char subject[MAX_SUBJECT_LENGTH];
   char body[MAX_BODY_LENGTH];
} Email;

// Function to read in an email from the user
Email read_email() {
    Email new_email;
    printf("Please enter the sender of the email: ");
    fgets(new_email.sender, MAX_EMAIL_LENGTH, stdin);
    printf("Please enter the recipient of the email: ");
    fgets(new_email.recipient, MAX_EMAIL_LENGTH, stdin);
    printf("Please enter the subject of the email: ");
    fgets(new_email.subject, MAX_SUBJECT_LENGTH, stdin);
    printf("Please enter the body of the email: ");
    fgets(new_email.body, MAX_BODY_LENGTH, stdin);
    printf("Email successfully added.\n");
    return new_email;
}

// Function to send an email
void send_email(Email *emails, int *num_emails) {
    if (*num_emails >= MAX_EMAILS) {
        printf("Error: maximum number of emails reached.\n");
        return;
    }
    emails[*num_emails] = read_email();
    *num_emails = *num_emails + 1;
}

// Function to print out a list of all emails
void list_emails(Email *emails, int num_emails) {
    if (num_emails == 0) {
        printf("No emails found.\n");
        return;
    }
    for (int i = 0; i < num_emails; i++) {
        printf("Email %d:\n", i+1);
        printf("\tFrom: %s", emails[i].sender);
        printf("\tTo: %s", emails[i].recipient);
        printf("\tSubject: %s", emails[i].subject);
        printf("\tBody: %s", emails[i].body);
    }
}

// Function to search for an email by subject
void search_emails(Email *emails, int num_emails) {
    char search_subject[MAX_SUBJECT_LENGTH];
    printf("Please enter the subject to search for: ");
    fgets(search_subject, MAX_SUBJECT_LENGTH, stdin);
    for (int i = 0; i < num_emails; i++) {
        if (strstr(emails[i].subject, search_subject) != NULL) {
            printf("Subject found in Email %d:\n", i+1);
            printf("\tFrom: %s", emails[i].sender);
            printf("\tTo: %s", emails[i].recipient);
            printf("\tSubject: %s", emails[i].subject);
            printf("\tBody: %s", emails[i].body);
        }
    }
}

// Main function to run the email client
int main() {
    Email emails[MAX_EMAILS];
    int num_emails = 0;
    int choice = -1;
    while (choice != 0) {
        printf("Please choose an option:\n");
        printf("1. Send an email.\n");
        printf("2. List all emails.\n");
        printf("3. Search for an email by subject.\n");
        printf("0. Exit.\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character left in buffer after scanf
        switch(choice) {
            case 1:
                send_email(emails, &num_emails);
                break;
            case 2:
                list_emails(emails, num_emails);
                break;
            case 3:
                search_emails(emails, num_emails);
                break;
            case 0:
                printf("Exiting program.");
                break;
            default:
                printf("Invalid choice, please enter a number between 0 and 3.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}