//FormAI DATASET v1.0 Category: Email Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT 50
#define MAX_BODY 500

// Email structure
typedef struct {
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
    char sender[MAX_BODY];
    char recipient[MAX_BODY];
} Email;

// Function prototypes
void createEmail(Email *email);
void printEmails(Email *emails, int count);

// Main function
int main() {
    Email emails[MAX_EMAILS];
    int count = 0;
    int choice;
    
    // User interface
    do {
        printf("Email Client\n");
        printf("1. Create Email\n");
        printf("2. View Emails\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice) {
            case 1:
                createEmail(&emails[count]);
                count++;
                break;
            case 2:
                printEmails(emails, count);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != 0);
    
    return 0;
}

// Function to create a new email
void createEmail(Email *email) {
    printf("New Email\n");
    printf("Enter recipient: ");
    scanf("%s", email->recipient);
    printf("Enter subject: ");
    scanf("%s", email->subject);
    printf("Enter body: ");
    scanf(" %[^\n]", email->body);
    printf("Enter sender: ");
    scanf("%s", email->sender);
    printf("Email sent!\n\n");
}

// Function to print all emails
void printEmails(Email *emails, int count) {
    printf("Emails (%d total)\n", count);
    for(int i = 0; i < count; i++) {
        printf("\nEmail %d:\n", i+1);
        printf("To: %s\n", emails[i].recipient);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n", emails[i].body);
        printf("From: %s\n", emails[i].sender);
    }
    printf("\n");
}