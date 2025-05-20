//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 50

typedef struct {
    char emails[MAX_EMAILS][EMAIL_LENGTH];
    int count;
} MailingList;

void initMailingList(MailingList* ml) {
    ml->count = 0;
}

void addEmail(MailingList* ml, const char* email) {
    if (ml->count < MAX_EMAILS) {
        strcpy(ml->emails[ml->count], email);
        ml->count++;
        printf("Email '%s' added successfully!\n", email);
    } else {
        printf("Mailing list is full! Cannot add more emails.\n");
    }
}

void removeEmail(MailingList* ml, const char* email) {
    for (int i = 0; i < ml->count; i++) {
        if (strcmp(ml->emails[i], email) == 0) {
            printf("Removing email '%s' from mailing list...\n", email);
            for (int j = i; j < ml->count - 1; j++) {
                strcpy(ml->emails[j], ml->emails[j + 1]);
            }
            ml->count--;
            printf("Email '%s' removed successfully!\n", email);
            return;
        }
    }
    printf("Email '%s' not found in the mailing list!\n", email);
}

void displayEmails(const MailingList* ml) {
    if (ml->count == 0) {
        printf("The mailing list is currently empty.\n");
    } else {
        printf("Current Mailing List:\n");
        for (int i = 0; i < ml->count; i++) {
            printf("%d: %s\n", i + 1, ml->emails[i]);
        }
    }
}

int main() {
    MailingList mailingList;
    initMailingList(&mailingList);

    char email[EMAIL_LENGTH];
    int choice;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Emails\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after choice

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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}