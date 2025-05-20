//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_LENGTH 100

typedef struct {
    char email[MAX_LENGTH];
} Email;

typedef struct {
    Email emails[MAX_EMAILS];
    int count;
} MailingList;

// Function prototypes
void addEmail(MailingList *list, const char *email);
void removeEmail(MailingList *list, const char *email);
void printEmails(const MailingList *list);
void clearList(MailingList *list);
int emailExists(const MailingList *list, const char *email);

int main() {
    MailingList list = { .count = 0 };
    int choice;
    char email[MAX_LENGTH];

    do {
        printf("\n--- Mailing List Manager ---\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Print Emails\n");
        printf("4. Clear List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clean the newline from buffer

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, MAX_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline
                addEmail(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, MAX_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline
                removeEmail(&list, email);
                break;
            case 3:
                printEmails(&list);
                break;
            case 4:
                clearList(&list);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addEmail(MailingList *list, const char *email) {
    if (list->count < MAX_EMAILS) {
        if (!emailExists(list, email)) {
            strcpy(list->emails[list->count].email, email);
            list->count++;
            printf("Email added: %s\n", email);
        } else {
            printf("Email already exists: %s\n", email);
        }
    } else {
        printf("Mailing list is full! Unable to add: %s\n", email);
    }
}

void removeEmail(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i].email, email) == 0) {
            // Shift remaining emails left
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j].email, list->emails[j + 1].email);
            }
            list->count--;
            printf("Email removed: %s\n", email);
            return;
        }
    }
    printf("Email not found: %s\n", email);
}

void printEmails(const MailingList *list) {
    if (list->count == 0) {
        printf("No emails in the list.\n");
        return;
    }
    printf("Current Email List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->emails[i].email);
    }
}

void clearList(MailingList *list) {
    list->count = 0;
    printf("All emails have been cleared from the list.\n");
}

int emailExists(const MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i].email, email) == 0) {
            return 1; // Email exists
        }
    }
    return 0; // Email does not exist
}