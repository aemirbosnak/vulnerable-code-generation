//FormAI DATASET v1.0 Category: Mailing list manager ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

// Struct to hold email information
typedef struct Email {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Email;

// Function to print email information
void printEmail(Email email) {
    printf("%s <%s>\n", email.name, email.email);
}

// Function to add an email to the mailing list
int addEmail(Email newEmail, Email* mailingList, int numEmails) {
    
    // Check if email already exists in mailing list
    for (int i = 0; i < numEmails; i++) {
        if (strcmp(newEmail.email, mailingList[i].email) == 0) {
            printf("Error: Email already exists in mailing list.\n");
            return numEmails;
        }
    }
    
    // Check if mailing list is full
    if (numEmails == MAX_EMAILS) {
        printf("Error: Mailing list is full.\n");
        return numEmails;
    }
    
    // Add new email to mailing list
    mailingList[numEmails] = newEmail;
    numEmails++;
    printf("Email added to mailing list.\n");
    return numEmails;
}

// Function to remove an email from the mailing list
int removeEmail(char* emailToRemove, Email* mailingList, int numEmails) {
    
    // Find index of email to remove
    int indexToRemove = -1;
    for (int i = 0; i < numEmails; i++) {
        if (strcmp(emailToRemove, mailingList[i].email) == 0) {
            indexToRemove = i;
            break;
        }
    }
    
    // Check if email was found
    if (indexToRemove == -1) {
        printf("Error: Email not found in mailing list.\n");
        return numEmails;
    }
    
    // Shift emails to fill removed email's spot
    for (int i = indexToRemove; i < numEmails - 1; i++) {
        mailingList[i] = mailingList[i + 1];
    }
    numEmails--;
    printf("Email removed from mailing list.\n");
    return numEmails;
}

int main() {
    Email mailingList[MAX_EMAILS];
    int numEmails = 0;
    char input[50];
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int choice;
    
    // Main program loop
    while (1) {
        printf("Mailing List Manager:\n");
        printf("1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Print mailing list\n");
        printf("4. Quit program\n");
        printf("Enter choice: ");
        fgets(input, 50, stdin);
        sscanf(input, "%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                printf("Enter email: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                Email newEmail = {0};
                strncpy(newEmail.name, name, strlen(name) - 1);
                strncpy(newEmail.email, email, strlen(email) - 1);
                numEmails = addEmail(newEmail, mailingList, numEmails);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                numEmails = removeEmail(email, mailingList, numEmails);
                break;
            case 3:
                printf("Mailing List:\n");
                for (int i = 0; i < numEmails; i++) {
                    printEmail(mailingList[i]);
                }
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid input.\n");
                break;
        }
    }
    return 0;
}