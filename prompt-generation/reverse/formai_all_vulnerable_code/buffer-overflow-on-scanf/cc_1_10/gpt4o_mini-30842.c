//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 100

typedef struct {
    char emails[MAX_EMAILS][EMAIL_LENGTH];
    int count;
} MailingList;

void initMailingList(MailingList *list) {
    list->count = 0;
}

int addEmail(MailingList *list, const char *email) {
    if (list->count < MAX_EMAILS) {
        strncpy(list->emails[list->count], email, EMAIL_LENGTH);
        list->emails[list->count][EMAIL_LENGTH - 1] = '\0'; // Ensure null-termination
        list->count++;
        return 1; // Success
    }
    return 0; // Failure
}

int removeEmail(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            // Shift emails to fill the gap
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            return 1; // Success
        }
    }
    return 0; // Failure
}

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

void showMenu() {
    printf("Mailing List Manager\n");
    printf("1. Add Email\n");
    printf("2. Remove Email\n");
    printf("3. Display Mailing List\n");
    printf("4. Exit\n");
}

int main() {
    MailingList list;
    initMailingList(&list);
    int choice;
    char email[EMAIL_LENGTH];

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // Clear input buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                if (addEmail(&list, email)) {
                    printf("Email added successfully!\n");
                } else {
                    printf("Failed to add email. List may be full.\n");
                }
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                if (removeEmail(&list, email)) {
                    printf("Email removed successfully!\n");
                } else {
                    printf("Email not found.\n");
                }
                break;
            case 3:
                displayMailingList(&list);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}