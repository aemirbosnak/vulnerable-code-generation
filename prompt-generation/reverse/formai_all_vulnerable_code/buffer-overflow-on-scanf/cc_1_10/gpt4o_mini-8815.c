//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_LENGTH 100

typedef struct {
    char emails[MAX_EMAILS][MAX_LENGTH];
    int count;
} MailingList;

// Function prototypes
void addEmail(MailingList *list, const char *email);
void removeEmail(MailingList *list, const char *email);
void displayEmails(const MailingList *list);
int emailExists(const MailingList *list, const char *email);
void clearList(MailingList *list);
void showMenu();

int main() {
    MailingList list;
    list.count = 0;
    int choice;
    char email[MAX_LENGTH];

    while (1) {
        showMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // to consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, MAX_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                addEmail(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, MAX_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0;
                removeEmail(&list, email);
                break;
            case 3:
                displayEmails(&list);
                break;
            case 4:
                clearList(&list);
                printf("Mailing list cleared.\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void showMenu() {
    printf("\n--- Mailing List Manager ---\n");
    printf("1. Add Email\n");
    printf("2. Remove Email\n");
    printf("3. Display Emails\n");
    printf("4. Clear List\n");
    printf("5. Exit\n");
}

void addEmail(MailingList *list, const char *email) {
    if (list->count >= MAX_EMAILS) {
        printf("Mailing list is full. Cannot add more emails.\n");
        return;
    }
    if (emailExists(list, email)) {
        printf("Email already exists in the list.\n");
        return;
    }
    strcpy(list->emails[list->count], email);
    list->count++;
    printf("Email '%s' added successfully!\n", email);
}

void removeEmail(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            // Shift the remaining emails
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            printf("Email '%s' removed successfully!\n", email);
            return;
        }
    }
    printf("Email '%s' not found in the list.\n", email);
}

void displayEmails(const MailingList *list) {
    if (list->count == 0) {
        printf("The mailing list is currently empty.\n");
        return;
    }
    printf("Current Emails in Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->emails[i]);
    }
}

int emailExists(const MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            return 1; // Email exists
        }
    }
    return 0; // Email does not exist
}

void clearList(MailingList *list) {
    list->count = 0; // Reset the count
}