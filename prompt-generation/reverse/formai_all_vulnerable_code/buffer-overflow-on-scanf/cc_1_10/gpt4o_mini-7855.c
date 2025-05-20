//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_LENGTH 100

typedef struct {
    char emails[MAX_EMAILS][MAX_LENGTH];
    int count;
} MailingList;

void initializeList(MailingList* list) {
    list->count = 0;
}

int addEmail(MailingList* list, const char* email) {
    if (list->count >= MAX_EMAILS) {
        printf("Mailing list is full.\n");
        return 0; // failure
    }
    strcpy(list->emails[list->count], email);
    list->count++;
    printf("Added: %s\n", email);
    return 1; // success
}

int removeEmail(MailingList* list, const char* email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            printf("Removed: %s\n", email);
            return 1; // success
        }
    }
    printf("Email not found: %s\n", email);
    return 0; // failure
}

void displayEmails(const MailingList* list) {
    if (list->count == 0) {
        printf("No emails in the list.\n");
        return;
    }
    printf("Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->emails[i]);
    }
}

void clearList(MailingList* list) {
    list->count = 0;
    printf("Mailing list cleared.\n");
}

void showMenu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Email\n");
    printf("2. Remove Email\n");
    printf("3. Display Emails\n");
    printf("4. Clear List\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    MailingList myList;
    initializeList(&myList);
    char email[MAX_LENGTH];
    int choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                addEmail(&myList, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeEmail(&myList, email);
                break;
            case 3:
                displayEmails(&myList);
                break;
            case 4:
                clearList(&myList);
                break;
            case 5:
                printf("Exiting...\n");
                return 0; // Exit program
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}