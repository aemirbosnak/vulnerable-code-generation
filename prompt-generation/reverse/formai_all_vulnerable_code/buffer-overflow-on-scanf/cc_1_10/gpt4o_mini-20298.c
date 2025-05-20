//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 100

typedef struct {
    char emails[MAX_LIST_SIZE][MAX_EMAIL_LENGTH];
    int count;
} MailingList;

// Function prototypes
void addEmail(MailingList *list, const char *email);
void removeEmail(MailingList *list, const char *email);
void displayEmails(const MailingList *list);
int emailExists(const MailingList *list, const char *email);

// Main function
int main() {
    MailingList mailingList;
    mailingList.count = 0;
    
    int choice;
    char email[MAX_EMAIL_LENGTH];

    while(1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Emails\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch(choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove trailing newline
                addEmail(&mailingList, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove trailing newline
                removeEmail(&mailingList, email);
                break;
            case 3:
                displayEmails(&mailingList);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}

// Function to add an email to the mailing list
void addEmail(MailingList *list, const char *email) {
    if (list->count >= MAX_LIST_SIZE) {
        printf("Mailing list is full! Cannot add more emails.\n");
        return;
    }
    if (emailExists(list, email)) {
        printf("Email already exists in the mailing list.\n");
        return;
    }

    strcpy(list->emails[list->count], email);
    list->count++;
    printf("Email '%s' added successfully!\n", email);
}

// Function to remove an email from the mailing list
void removeEmail(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            printf("Email '%s' removed successfully!\n", email);
            return;
        }
    }
    printf("Email '%s' not found in the mailing list.\n", email);
}

// Function to display all emails in the mailing list
void displayEmails(const MailingList *list) {
    if (list->count == 0) {
        printf("The mailing list is empty.\n");
        return;
    }
    printf("Current Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->emails[i]);
    }
}

// Function to check if an email exists in the mailing list
int emailExists(const MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            return 1; // Email exists
        }
    }
    return 0; // Email does not exist
}