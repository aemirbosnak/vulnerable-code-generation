//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 50

typedef struct {
    char emails[MAX_EMAILS][EMAIL_LENGTH];
    int count;
} MailingList;

void initMailingList(MailingList* list) {
    list->count = 0;
}

void addEmail(MailingList* list, const char* email) {
    if (list->count < MAX_EMAILS) {
        strncpy(list->emails[list->count], email, EMAIL_LENGTH - 1);
        list->emails[list->count][EMAIL_LENGTH - 1] = '\0';  // Ensure null termination
        list->count++;
        printf("Email '%s' added successfully!\n", email);
    } else {
        printf("Mailing list is full. Can't add new email!\n");
    }
}

void removeEmail(MailingList* list, const char* email) {
    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            found = 1;
            printf("Removing email '%s'...\n", email);
            for (int j = i; j < list->count - 1; j++) {
                strncpy(list->emails[j], list->emails[j + 1], EMAIL_LENGTH);
            }
            list->count--;
            break;
        }
    }
    if (!found) {
        printf("Email '%s' not found to remove.\n", email);
    }
}

void displayEmails(const MailingList* list) {
    if (list->count == 0) {
        printf("No emails in the mailing list.\n");
        return;
    }
    printf("Current Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->emails[i]);
    }
}

int main() {
    MailingList myList;
    initMailingList(&myList);

    int choice;
    char email[EMAIL_LENGTH];

    do {
        printf("\n----- Mailing List Manager -----\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Emails\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                addEmail(&myList, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                removeEmail(&myList, email);
                break;
            case 3:
                displayEmails(&myList);
                break;
            case 4:
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}