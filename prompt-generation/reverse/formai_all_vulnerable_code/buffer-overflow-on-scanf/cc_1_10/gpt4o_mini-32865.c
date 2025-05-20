//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 100

// Definition of the mailing list structure
typedef struct {
    char emails[MAX_EMAILS][EMAIL_LENGTH];
    int count;
} MailingList;

// Function declarations
void initMailingList(MailingList* list);
void addEmail(MailingList* list);
void removeEmail(MailingList* list);
void viewEmails(const MailingList* list);
void printGratefulMessage(const char* email);

// Main function
int main() {
    MailingList mailingList;
    initMailingList(&mailingList);
    
    int choice;
    do {
        printf("\nWelcome to the Mailing List Manager!\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. View Emails\n");
        printf("4. Exit\n");
        printf("Please enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEmail(&mailingList);
                break;
            case 2:
                removeEmail(&mailingList);
                break;
            case 3:
                viewEmails(&mailingList);
                break;
            case 4:
                printf("Thank you for using the Mailing List Manager! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option (1-4).\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to initialize mailing list
void initMailingList(MailingList* list) {
    list->count = 0;
}

// Function to add an email to the mailing list
void addEmail(MailingList* list) {
    if (list->count < MAX_EMAILS) {
        char email[EMAIL_LENGTH];
        printf("Please enter the email to add: ");
        scanf("%s", email);
        
        strcpy(list->emails[list->count], email);
        list->count++;
        
        printGratefulMessage(email);
    } else {
        printf("The mailing list is full! Can't add more emails.\n");
    }
}

// Function to remove an email from the mailing list
void removeEmail(MailingList* list) {
    if (list->count > 0) {
        char email[EMAIL_LENGTH];
        printf("Please enter the email to remove: ");
        scanf("%s", email);
        
        for (int i = 0; i < list->count; i++) {
            if (strcmp(list->emails[i], email) == 0) {
                for (int j = i; j < list->count - 1; j++) {
                    strcpy(list->emails[j], list->emails[j + 1]);
                }
                list->count--;
                printf("Successfully removed the email: %s.\n", email);
                return;
            }
        }
        
        printf("Email %s not found in the mailing list.\n", email);
    } else {
        printf("The mailing list is empty! No emails to remove.\n");
    }
}

// Function to view all emails in the mailing list
void viewEmails(const MailingList* list) {
    if (list->count == 0) {
        printf("The mailing list is currently empty.\n");
    } else {
        printf("Emails in the mailing list:\n");
        for (int i = 0; i < list->count; i++) {
            printf("%s\n", list->emails[i]);
        }
    }
}

// Function to print a grateful message when an email is added
void printGratefulMessage(const char* email) {
    printf("Thank you for adding: %s to our mailing list! You are awesome!\n", email);
}