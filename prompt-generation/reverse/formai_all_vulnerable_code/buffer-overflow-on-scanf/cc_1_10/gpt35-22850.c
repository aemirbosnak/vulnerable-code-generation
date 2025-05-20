//FormAI DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
// The Case of the Missing Emails
#include <stdio.h>
#include <stdlib.h>

// Struct to hold email information
typedef struct email {
    char sender[50];
    char receiver[50];
    char subject[100];
    char message[1000];
} Email;

// Function to input an email
Email inputEmail() {
    Email newEmail;
    printf("\nEnter the sender: ");
    fgets(newEmail.sender, 50, stdin);
    printf("\nEnter the receiver: ");
    fgets(newEmail.receiver, 50, stdin);
    printf("\nEnter the subject: ");
    fgets(newEmail.subject, 100, stdin);
    printf("\nEnter the message: ");
    fgets(newEmail.message, 1000, stdin);
    return newEmail;
}

// Function to display an email
void displayEmail(Email email) {
    printf("\nFrom: %s", email.sender);
    printf("\nTo: %s", email.receiver);
    printf("\nSubject: %s", email.subject);
    printf("\nMessage: %s", email.message);
}

// Main function
int main(void) {
    // Introductory messages
    printf("Welcome to the Email Client program.\n");
    printf("You are the owner of an Email server and a customer has reported that their emails are missing.\n");
    printf("Your task is to search through all the emails in the server and find the missing emails.\n");
    printf("Good luck! Let's get started.\n");

    // Getting the number of emails
    int numEmails;
    printf("\nHow many emails are there in the server? ");
    scanf("%d", &numEmails);
    getchar();

    // Creating an array of emails
    Email *emails = (Email *) malloc(numEmails * sizeof(Email));

    // Inputting the emails
    for (int i = 0; i < numEmails; i++) {
        printf("\nEmail #%d:", i+1);
        emails[i] = inputEmail();
    }

    // Displaying all the emails
    printf("\n\nAll emails in the server:\n");
    for (int i = 0; i < numEmails; i++) {
        printf("\nEmail #%d:", i+1);
        displayEmail(emails[i]);
    }

    // Searching for the missing email
    printf("\n\nNow we will search for the missing email.");
    printf("\nEnter the sender of the missing email: ");
    char missingSender[50];
    fgets(missingSender, 50, stdin);
    printf("\nEnter the receiver of the missing email: ");
    char missingReceiver[50];
    fgets(missingReceiver, 50, stdin);
    printf("\nEnter the subject of the missing email: ");
    char missingSubject[100];
    fgets(missingSubject, 100, stdin);

    Email *missingEmail = NULL;

    for (int i = 0; i < numEmails; i++) {
        if (strcmp(missingSender, emails[i].sender) == 0 
            && strcmp(missingReceiver, emails[i].receiver) == 0
            && strcmp(missingSubject, emails[i].subject) == 0) {
            missingEmail = &emails[i];
            break;
        }
    }

    // Displaying the missing email
    if (missingEmail == NULL) {
        printf("\nUnfortunately, the missing email was not found.\n");
    } else {
        printf("\n\nThe missing email has been found!\n");
        printf("====================================\n");
        displayEmail(*missingEmail);
        printf("====================================\n");
    }

    // Freeing up memory
    free(emails);

    // Closing message
    printf("\nThank you for using the Email Client program.");
    return 0;
}