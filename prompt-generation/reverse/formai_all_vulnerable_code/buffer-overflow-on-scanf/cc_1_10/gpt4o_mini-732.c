//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_LENGTH 100

typedef struct {
    char emails[MAX_EMAILS][MAX_LENGTH];
    int count;
} MailingList;

void initMailingList(MailingList *list) {
    list->count = 0;
}

void addEmail(MailingList *list, const char *email) {
    if (list->count < MAX_EMAILS) {
        strcpy(list->emails[list->count], email);
        list->count++;
        printf("Email added: %s\n", email);
    } else {
        printf("Failed to add email: Mailing list is full!\n");
    }
}

void removeEmail(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            printf("Email removed: %s\n", email);
            return;
        }
    }
    printf("Failed to remove email: %s not found!\n", email);
}

void displayEmails(const MailingList *list) {
    if (list->count == 0) {
        printf("Mailing list is empty.\n");
        return;
    }
    printf("Current mailing list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->emails[i]);
    }
}

void clearList(MailingList *list) {
    list->count = 0;
    printf("All emails have been removed from the mailing list.\n");
}

int main() {
    MailingList list;
    initMailingList(&list);
    
    int choice;
    char email[MAX_LENGTH];

    do {
        printf("\n--- Mailing List Manager ---\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Emails\n");
        printf("4. Clear List\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the number input

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, MAX_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove the trailing newline
                addEmail(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, MAX_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove the trailing newline
                removeEmail(&list, email);
                break;
            case 3:
                displayEmails(&list);
                break;
            case 4:
                clearList(&list);
                break;
            case 5:
                printf("Exiting the Mailing List Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}