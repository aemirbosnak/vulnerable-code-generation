//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char emails[MAX_EMAILS][MAX_EMAIL_LENGTH];
    int count;
} MailingList;

void initializeList(MailingList *list) {
    list->count = 0;
}

void addEmail(MailingList *list, const char *email) {
    if (list->count < MAX_EMAILS) {
        strcpy(list->emails[list->count], email);
        list->count++;
        printf("Email added: %s\n", email);
    } else {
        printf("Mailing list is full! Cannot add %s.\n", email);
    }
}

void removeEmail(MailingList *list, const char *email) {
    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            found = 1;
            // Shift emails to the left
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            printf("Email removed: %s\n", email);
            break;
        }
    }
    if (!found) {
        printf("Email %s not found in the mailing list.\n", email);
    }
}

void displayEmails(const MailingList *list) {
    if (list->count == 0) {
        printf("Mailing list is empty.\n");
    } else {
        printf("Mailing List Emails:\n");
        for (int i = 0; i < list->count; i++) {
            printf("%d: %s\n", i + 1, list->emails[i]);
        }
    }
}

void searchEmail(const MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            printf("Email %s found at position %d\n", email, i + 1);
            return;
        }
    }
    printf("Email %s not found in the mailing list.\n", email);
}

int main() {
    MailingList myMailingList;
    initializeList(&myMailingList);
    
    int choice;
    char email[MAX_EMAIL_LENGTH];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Emails\n");
        printf("4. Search Email\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                addEmail(&myMailingList, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;
                removeEmail(&myMailingList, email);
                break;
            case 3:
                displayEmails(&myMailingList);
                break;
            case 4:
                printf("Enter email to search: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;
                searchEmail(&myMailingList, email);
                break;
            case 5:
                printf("Exiting Mailing List Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}