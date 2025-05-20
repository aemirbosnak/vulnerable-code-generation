//FormAI DATASET v1.0 Category: Email Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct representing an email message
struct email {
    char sender[50];
    char receiver[50];
    char subject[100];
    char body[500];
};

// Function to send an email
void send_email(struct email new_email) {
    printf("Sending email...\n");
    printf("From: %s\nTo: %s\nSubject: %s\nBody: %s\n\n", new_email.sender, new_email.receiver, new_email.subject, new_email.body);
}

// Function to read in user input and create a new email
struct email create_email() {
    struct email new_email;
    printf("Enter sender: ");
    scanf("%s", new_email.sender);
    printf("Enter receiver: ");
    scanf("%s", new_email.receiver);
    printf("Enter subject: ");
    scanf("%s", new_email.subject);
    printf("Enter body: ");
    scanf("%s", new_email.body);
    return new_email;
}

int main() {
    // Welcome message
    printf("Welcome to the C Email Client!\n");

    // Menu options
    int choice;
    do {
        printf("\n1. Compose new email\n2. Exit\n");
        printf("What would you like to do? ");
        scanf("%d", &choice);

        // Execute user's choice
        switch(choice) {
            case 1: {
                struct email new_email = create_email();
                send_email(new_email);
                break;
            }
            case 2:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 2);

    return 0;
}