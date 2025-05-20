//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Claude Shannon
// This program is a simple mailing list manager that utilizes linked lists to store email addresses
// It was crafted with inspiration from Claude Shannon's seminal work on information theory
// By: [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the struct for each email address
struct email {
    char address[50]; // keep the email address to 50 characters
    struct email *next; // pointer to next email in list
};

// define the main mailing list
struct email *mailList = NULL;

// function to display the current mailing list
void displayList() {
    struct email *current = mailList;
    printf("\nCurrent mailing list:\n");
    while (current != NULL) {
        printf("%s\n", current->address);
        current = current->next;
    }
}

// function to add a new email address to the mailing list
void addEmail() {
    char address[50];
    printf("\nEnter email address to add: ");
    scanf("%s", address);

    // create new email struct and initialize values
    struct email *newEmail = malloc(sizeof(struct email));
    strncpy(newEmail->address, address, 50);
    newEmail->next = NULL;

    // check if list is empty
    if (mailList == NULL) {
        mailList = newEmail;
    }
    else {
        // iterate through list until end is reached
        struct email *current = mailList;
        while (current->next != NULL) {
            current = current->next;
        }

        // add new email to end of list
        current->next = newEmail;
    }

    printf("Email address %s added to mailing list.\n", address);
}

// function to remove an email address from the mailing list
void removeEmail() {
    char address[50];
    printf("\nEnter email address to remove: ");
    scanf("%s", address);

    // handle case where list is empty
    if (mailList == NULL) {
        printf("Mailing list is empty, cannot remove address.\n");
        return;
    }

    // handle case where first email in list is to be removed
    if (strcmp(mailList->address, address) == 0) {
        mailList = mailList->next;
        printf("Email address %s removed from mailing list.\n", address);
        return;
    }

    // iterate through list until email is found or end is reached
    struct email *current = mailList;
    while (current->next != NULL && strcmp(current->next->address, address) != 0) {
        current = current->next;
    }

    // if email is not found, display error message
    if (current->next == NULL) {
        printf("Email address %s not found in mailing list, cannot remove.\n", address);
        return;
    }

    // remove email from list
    struct email *toRemove = current->next;
    current->next = toRemove->next;

    printf("Email address %s removed from mailing list.\n", address);
}

// main function that displays menu and handles user input
int main() {
    printf("Welcome to the mailing list manager!\n");

    int choice = 0;
    while (choice != 4) {
        printf("\nPlease choose an option:\n");
        printf("1. Display mailing list\n");
        printf("2. Add email address to list\n");
        printf("3. Remove email address from list\n");
        printf("4. Quit\n");
        printf("Choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList();
                break;
            case 2:
                addEmail();
                break;
            case 3:
                removeEmail();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please choose again.\n");
                break;
        }
    }

    return 0;
}