//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 100

typedef struct {
    char emails[MAX_EMAILS][EMAIL_LENGTH];
    int count;
} MailingList;

void initializeList(MailingList* list) {
    list->count = 0;
}

void addEmail(MailingList* list, const char* email) {
    if (list->count < MAX_EMAILS) {
        strncpy(list->emails[list->count], email, EMAIL_LENGTH - 1);
        list->emails[list->count][EMAIL_LENGTH - 1] = '\0'; // Ensure null-termination
        list->count++;
        printf("Peacefully added: %s\n", email);
    } else {
        printf("The list is full, can't add more emails.\n");
    }
}

void removeEmail(MailingList* list, const char* email) {
    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            found = 1;
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            printf("Serenely removed: %s\n", email);
            break;
        }
    }
    if (!found) {
        printf("Email not found in the list.\n");
    }
}

void displayEmails(const MailingList* list) {
    if (list->count == 0) {
        printf("The mailing list is currently empty.\n");
    } else {
        printf("Current Mailing List:\n");
        for (int i = 0; i < list->count; i++) {
            printf(" - %s\n", list->emails[i]);
        }
    }
}

void menu() {
    printf("\nPeaceful Mailing List Manager\n");
    printf("1. Add Email\n");
    printf("2. Remove Email\n");
    printf("3. Display Emails\n");
    printf("4. Exit\n");
}

int main() {
    MailingList myList;
    initializeList(&myList);
    int choice;
    char email[EMAIL_LENGTH];

    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter the email to add: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Strip newline character
                addEmail(&myList, email);
                break;

            case 2:
                printf("Enter the email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Strip newline character
                removeEmail(&myList, email);
                break;

            case 3:
                displayEmails(&myList);
                break;

            case 4:
                printf("Exiting the peaceful mailing list manager...\n");
                return 0;

            default:
                printf("Invalid choice, please select a valid option.\n");
        }
    }
    
    return 0;
}