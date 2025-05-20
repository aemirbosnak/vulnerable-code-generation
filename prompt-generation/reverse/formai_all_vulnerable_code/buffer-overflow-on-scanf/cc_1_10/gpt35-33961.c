//FormAI DATASET v1.0 Category: Email Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define maximum email size and number of emails
#define MAX_EMAIL_SIZE 1000
#define MAX_NUM_EMAILS 100

// Define email struct
typedef struct {
    char* sender;
    char* recipient;
    char* subject;
    char* body;
} Email;

// Define email database struct
typedef struct {
    Email emails[MAX_NUM_EMAILS];
    int num_emails;
} EmailDatabase;

// Function to create a new email
Email createEmail(char* sender, char* recipient, char* subject, char* body) {
    Email email;
    email.sender = malloc(strlen(sender) + 1);
    strcpy(email.sender, sender);
    email.recipient = malloc(strlen(recipient) + 1);
    strcpy(email.recipient, recipient);
    email.subject = malloc(strlen(subject) + 1);
    strcpy(email.subject, subject);
    email.body = malloc(strlen(body) + 1);
    strcpy(email.body, body);
    return email;
}

// Function to add a new email to the database
void addEmailToDatabase(EmailDatabase* db, Email email) {
    // Check if number of emails is less than maximum
    if (db->num_emails < MAX_NUM_EMAILS) {
        db->emails[db->num_emails++] = email;
        printf("Email added successfully!\n");
    } else {
        printf("Error: Maximum number of emails has been reached.\n");
    }
}

// Function to print the contents of an email
void printEmail(Email email) {
    printf("Sender: %s\nRecipient: %s\nSubject: %s\nBody: %s\n", email.sender, email.recipient, email.subject, email.body);
}

// Function to search for an email by sender or recipient
void searchEmails(EmailDatabase db, char* search_term) {
    for (int i = 0; i < db.num_emails; i++) {
        if (strcmp(db.emails[i].sender, search_term) == 0 || strcmp(db.emails[i].recipient, search_term) == 0) {
            printf("Search result:\n");
            printEmail(db.emails[i]);
        }
    }
}

// Function to delete an email by index
void deleteEmail(EmailDatabase* db, int index) {
    // Shift all emails after the deleted email one position to the left
    for (int i = index; i < db->num_emails - 1; i++) {
        db->emails[i] = db->emails[i+1];
    }
    db->num_emails--;
    printf("Email deleted successfully!\n");
}

int main() {
    EmailDatabase db;
    db.num_emails = 0;
    char option, sender[MAX_EMAIL_SIZE], recipient[MAX_EMAIL_SIZE], subject[MAX_EMAIL_SIZE], body[MAX_EMAIL_SIZE];
    int index;
    bool running = true;

    while (running) {
        printf("\n");
        printf("Please choose an option:\n");
        printf("1) Compose new email\n");
        printf("2) View all emails\n");
        printf("3) Search for an email\n");
        printf("4) Delete an email\n");
        printf("5) Exit\n");
        printf("Option: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                printf("Sender email address: ");
                scanf("%s", sender);
                printf("Recipient email address: ");
                scanf("%s", recipient);
                printf("Email subject: ");
                scanf("%s", subject);
                printf("Email body: ");
                scanf(" %[^\n]s", body);
                addEmailToDatabase(&db, createEmail(sender, recipient, subject, body));
                break;
            case '2':
                if (db.num_emails == 0) {
                    printf("No emails found.\n");
                } else {
                    printf("All emails:\n");
                    for (int i = 0; i < db.num_emails; i++) {
                        printf("Email %d:\n", i+1);
                        printEmail(db.emails[i]);
                    }
                }
                break;
            case '3':
                printf("Search term (sender or recipient email address): ");
                scanf("%s", sender);
                searchEmails(db, sender);
                break;
            case '4':
                printf("Enter index of email to delete: ");
                scanf("%d", &index);
                if (index < 1 || index > db.num_emails) {
                    printf("Error: Invalid index.\n");
                } else {
                    deleteEmail(&db, index-1);
                }
                break;
            case '5':
                running = false;
                break;
            default:
                printf("Error: Invalid option.\n");
                break;
        }
    }

    // Free memory allocated for email data
    for (int i = 0; i < db.num_emails; i++) {
        free(db.emails[i].sender);
        free(db.emails[i].recipient);
        free(db.emails[i].subject);
        free(db.emails[i].body);
    }

    return 0;
}