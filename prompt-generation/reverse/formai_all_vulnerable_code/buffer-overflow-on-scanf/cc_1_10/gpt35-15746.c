//FormAI DATASET v1.0 Category: Email Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print a menu and read the user's choice
char printMenu() {
    char choice;
    printf("\n===== C EMAIL CLIENT =====\n");
    printf("1. Compose Email\n");
    printf("2. Check Inbox\n");
    printf("3. Delete Email\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);
    return choice;
}

// Function to add a new email to the inbox
void addNewEmail(char sender[], char subject[], char message[], char inbox[][50], int *emailCount) {
    int i;
    for (i = 0; i < *emailCount; i++) { // Check if email already exists in inbox
        if (strcmp(inbox[i], subject) == 0) {
            printf("Error: Email with subject '%s' already exists.\n", subject);
            return;
        }
    }
    strcpy(inbox[*emailCount], subject); // Add the email to the inbox
    (*emailCount)++;
    printf("Email sent to %s with subject '%s' and message: '%s'\n", sender, subject, message);
}

int main() {
    char inbox[10][50]; // Array to store inbox emails
    int emailCount = 0; // Amount of emails in inbox
    char choice, sender[20], subject[50], message[100];

    do {
        choice = printMenu(); // Print menu and read choice
        switch (choice) {
            case '1': // Compose email
                printf("Enter the sender's name: ");
                scanf(" %s", sender);
                printf("Enter the subject: ");
                scanf(" %s", subject);
                printf("Enter the message: ");
                scanf(" %s", message);
                addNewEmail(sender, subject, message, inbox, &emailCount); // Add email to inbox
                break;
            case '2': // Check inbox
                printf("\nINBOX:\n");
                if (emailCount == 0) {
                    printf("No emails.\n");
                } else {
                    int i;
                    for (i = 0; i < emailCount; i++) {
                        printf("%d. %s\n", i+1, inbox[i]);
                    }
                }
                break;
            case '3': // Delete email
                if (emailCount == 0) {
                    printf("Error: No emails to delete.\n");
                } else {
                    int i, emailNumber;
                    printf("Enter email number to delete: ");
                    scanf(" %d", &emailNumber);
                    if (emailNumber < 1 || emailNumber > emailCount) {
                        printf("Error: Invalid email number.\n");
                    } else {
                        for (i = emailNumber-1; i < emailCount-1; i++) {
                            strcpy(inbox[i], inbox[i+1]); // Shift emails to remove the deleted email
                        }
                        emailCount--; // Decrement email count
                        printf("Email deleted.\n");
                    }
                }
                break;
            case '4': // Exit
                printf("Exiting program.\n");
                break;
            default: // Invalid input
                printf("Error: Invalid input.\n");
        }
    } while (choice != '4');

    return 0;
}