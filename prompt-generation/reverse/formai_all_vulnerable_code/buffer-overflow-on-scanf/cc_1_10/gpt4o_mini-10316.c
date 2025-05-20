//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 100

typedef struct {
    char emails[MAX_EMAILS][EMAIL_LENGTH];
    int count;
} MailingList;

// Function prototypes
void initializeList(MailingList *list);
void addEmail(MailingList *list, const char *email);
void removeEmail(MailingList *list, const char *email);
void displayEmails(const MailingList *list);
void clearList(MailingList *list);

int main() {
    MailingList mailingList;
    initializeList(&mailingList);

    int choice;
    char email[EMAIL_LENGTH];

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Emails\n");
        printf("4. Clear List\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline after choice input

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                addEmail(&mailingList, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                removeEmail(&mailingList, email);
                break;
            case 3:
                displayEmails(&mailingList);
                break;
            case 4:
                clearList(&mailingList);
                printf("Mailing list cleared!\n");
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}

void initializeList(MailingList *list) {
    list->count = 0;
}

void addEmail(MailingList *list, const char *email) {
    if (list->count >= MAX_EMAILS) {
        printf("Mailing list is full! Cannot add more emails.\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            printf("Email already exists in the list.\n");
            return;
        }
    }
    strcpy(list->emails[list->count++], email);
    printf("Added email: %s\n", email);
}

void removeEmail(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            // Shift emails down
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            printf("Removed email: %s\n", email);
            return;
        }
    }
    printf("Email not found in the list.\n");
}

void displayEmails(const MailingList *list) {
    if (list->count == 0) {
        printf("The mailing list is empty.\n");
        return;
    }
    printf("Current Emails in Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->emails[i]);
    }
}

void clearList(MailingList *list) {
    list->count = 0;
}