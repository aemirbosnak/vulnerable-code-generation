//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 256

typedef struct {
    char emails[MAX_EMAILS][MAX_EMAIL_LENGTH];
    int count;
} MailingList;

// Function prototypes
void addEmail(MailingList *list, const char *email);
void viewEmails(const MailingList *list);
void deleteEmail(MailingList *list, const char *email);
void printMenu();
int isValidEmail(const char *email);

int main() {
    MailingList list;
    list.count = 0;
    int choice;
    char email[MAX_EMAIL_LENGTH];

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to absorb newline from input buffer

        switch (choice) {
            case 1: // Add Email
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                if (isValidEmail(email)) {
                    addEmail(&list, email);
                } else {
                    printf("Invalid email format.\n");
                }
                break;

            case 2: // View Emails
                viewEmails(&list);
                break;

            case 3: // Delete Email
                printf("Enter email to delete: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                deleteEmail(&list, email);
                break;

            case 4: // Exit
                printf("Exiting program. Bye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addEmail(MailingList *list, const char *email) {
    if (list->count < MAX_EMAILS) {
        strcpy(list->emails[list->count], email);
        list->count++;
        printf("Email added: %s\n", email);
    } else {
        printf("Mailing list is full. Cannot add more emails.\n");
    }
}

void viewEmails(const MailingList *list) {
    printf("----- Mailing List -----\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->emails[i]);
    }
    if (list->count == 0) {
        printf("No emails in the list.\n");
    }
}

void deleteEmail(MailingList *list, const char *email) {
    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            found = 1;
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            printf("Email deleted: %s\n", email);
            break;
        }
    }
    if (!found) {
        printf("Email not found in the list.\n");
    }
}

void printMenu() {
    printf("\n---------- Menu ----------\n");
    printf("1. Add Email\n");
    printf("2. View Emails\n");
    printf("3. Delete Email\n");
    printf("4. Exit\n");
}

int isValidEmail(const char *email) {
    // Basic validation for email format
    const char *at = strchr(email, '@');
    const char *dot = strrchr(email, '.');

    if (at != NULL && dot != NULL && at < dot && at != email && dot != at + 1) {
        return 1; // valid email
    }
    return 0; // invalid email
}