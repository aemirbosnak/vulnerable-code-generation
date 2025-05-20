//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Email;

typedef struct {
    Email emails[MAX_LIST_SIZE];
    int count;
} MailingList;

void initializeList(MailingList *list) {
    list->count = 0;
    printf("🐦 Welcome to the Curious Mailing List Manager! 🐦\n");
}

int isDuplicate(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i].email, email) == 0) {
            return 1; // Found a duplicate
        }
    }
    return 0; // No duplicates found
}

void addEmail(MailingList *list, const char *email) {
    if (list->count < MAX_LIST_SIZE) {
        if (!isDuplicate(list, email)) {
            strncpy(list->emails[list->count].email, email, MAX_EMAIL_LENGTH);
            list->emails[list->count].email[MAX_EMAIL_LENGTH - 1] = '\0';  // Ensure null termination
            list->count++;
            printf("✅ '%s' has been added to the list!\n", email);
        } else {
            printf("❌ '%s' is already in the list! Duplicates are not allowed.\n", email);
        }
    } else {
        printf("⚠️ Oh no! The mailing list is full! Cannot add more emails.\n");
    }
}

void removeEmail(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i].email, email) == 0) {
            // Shift the remaining emails down
            for (int j = i; j < list->count - 1; j++) {
                list->emails[j] = list->emails[j + 1];
            }
            list->count--;
            printf("✅ '%s' has been removed from the list!\n", email);
            return;
        }
    }
    printf("❌ '%s' is not in the list! Cannot remove...\n", email);
}

void displayEmails(MailingList *list) {
    if (list->count == 0) {
        printf("📭 The mailing list is currently empty!\n");
    } else {
        printf("📬 Here are the emails in the mailing list:\n");
        for (int i = 0; i < list->count; i++) {
            printf(" - [%d] %s\n", i + 1, list->emails[i].email);
        }
    }
}

int main() {
    MailingList list;
    initializeList(&list);

    int choice;
    char email[MAX_EMAIL_LENGTH];
    while (1) {
        printf("\n🌟 Menu:\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Emails\n");
        printf("4. Exit\n");
        printf("What would you like to do? (1-4): ");
        scanf("%d", &choice);
        getchar(); // clear newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter the email to add: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                addEmail(&list, email);
                break;
            case 2:
                printf("Enter the email to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                removeEmail(&list, email);
                break;
            case 3:
                displayEmails(&list);
                break;
            case 4:
                printf("👋 Thank you for using the Curious Mailing List Manager! Goodbye!\n");
                exit(0);
            default:
                printf("🚫 Invalid choice! Please select a number between 1 and 4.\n");
        }
    }

    return 0;
}