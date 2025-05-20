//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 100

typedef struct {
    char emails[MAX_EMAILS][EMAIL_LENGTH]; // Array to store email addresses
    int count; // Current number of emails
} MailingList;

// Function to initialize the mailing list
void initMailingList(MailingList *list) {
    list->count = 0;
}

// Function to add an email to the mailing list
int addEmail(MailingList *list, const char *email) {
    if (list->count >= MAX_EMAILS) {
        printf("Mailing list is full. Cannot add more emails.\n");
        return -1;
    }
    if (strlen(email) >= EMAIL_LENGTH) {
        printf("Email too long. Cannot add to mailing list.\n");
        return -1;
    }
    
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            printf("Email already exists in the mailing list.\n");
            return -1;
        }
    }
    
    strncpy(list->emails[list->count++], email, EMAIL_LENGTH);
    printf("Email '%s' added to the mailing list.\n", email);
    return 0;
}

// Function to remove an email from the mailing list
int removeEmail(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            // Shift following emails down
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            printf("Email '%s' removed from the mailing list.\n", email);
            return 0;
        }
    }
    printf("Email '%s' not found in the mailing list.\n", email);
    return -1;
}

// Function to display the mailing list
void displayMailingList(const MailingList *list) {
    if (list->count == 0) {
        printf("The mailing list is currently empty.\n");
        return;
    }
    printf("Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->emails[i]);
    }
}

// Main function to test the mailing list manager
int main() {
    MailingList myList;
    initMailingList(&myList);
    
    int choice;
    char email[EMAIL_LENGTH];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Mailing List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline
                addEmail(&myList, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline
                removeEmail(&myList, email);
                break;
            case 3:
                displayMailingList(&myList);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}