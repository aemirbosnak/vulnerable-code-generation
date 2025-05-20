//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 100

typedef struct MailingList {
    char emails[MAX_EMAILS][EMAIL_LENGTH];
    int count;
} MailingList;

void initializeList(MailingList *list) {
    list->count = 0;
}

int addEmail(MailingList *list, const char *email) {
    if (list->count >= MAX_EMAILS) {
        printf("Mailing list is full, cannot add more emails.\n");
        return -1;
    }
    strncpy(list->emails[list->count], email, EMAIL_LENGTH);
    list->emails[list->count][EMAIL_LENGTH - 1] = '\0'; // Ensure null-termination
    list->count++;
    printf("Email %s added successfully.\n", email);
    return 0;
}

int removeEmail(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                strncpy(list->emails[j], list->emails[j + 1], EMAIL_LENGTH);
            }
            list->count--;
            printf("Email %s removed successfully.\n", email);
            return 0;
        }
    }
    printf("Email %s not found in the mailing list.\n", email);
    return -1;
}

void displayEmails(const MailingList *list) {
    printf("Current Mailing List Emails:\n");
    for (int i = 0; i < list->count; i++) {
        printf(" - %s\n", list->emails[i]);
    }
    if (list->count == 0) {
        printf("No emails in the mailing list.\n");
    }
}

void freeMailingList(MailingList *list) {
    // In this basic example, we do nothing special to free the list,
    // but this function could be used for potential future enhancements.
    // Here just showing how it could be utilized.
}

int main() {
    MailingList list;
    initializeList(&list);

    int choice;
    char email[EMAIL_LENGTH];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Emails\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                addEmail(&list, email);
                break;

            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeEmail(&list, email);
                break;

            case 3:
                displayEmails(&list);
                break;

            case 4:
                printf("Exiting the program...\n");
                freeMailingList(&list);
                break;
                
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}