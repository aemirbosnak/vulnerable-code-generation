//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: authentic
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
void displayMenu();
void addEmail(MailingList *list);
void removeEmail(MailingList *list);
void viewEmails(const MailingList *list);
int isEmailInList(const MailingList *list, const char *email);
void clearInputBuffer();

int main() {
    MailingList list;
    list.count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addEmail(&list);
                break;
            case 2:
                removeEmail(&list);
                break;
            case 3:
                viewEmails(&list);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Mailing List Manager ---\n");
    printf("1. Subscribe to mailing list\n");
    printf("2. Unsubscribe from mailing list\n");
    printf("3. View subscribed emails\n");
    printf("4. Exit\n");
}

void addEmail(MailingList *list) {
    if (list->count >= MAX_EMAILS) {
        printf("The mailing list is full. Cannot add more emails.\n");
        return;
    }

    char email[EMAIL_LENGTH];
    printf("Enter the email address to subscribe: ");
    fgets(email, EMAIL_LENGTH, stdin);
    email[strcspn(email, "\n")] = 0; // Remove newline character

    if (isEmailInList(list, email)) {
        printf("This email is already subscribed to the mailing list.\n");
    } else {
        strcpy(list->emails[list->count], email);
        list->count++;
        printf("Successfully subscribed: %s\n", email);
    }
}

void removeEmail(MailingList *list) {
    char email[EMAIL_LENGTH];
    printf("Enter the email address to unsubscribe: ");
    fgets(email, EMAIL_LENGTH, stdin);
    email[strcspn(email, "\n")] = 0; // Remove newline character

    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            printf("Successfully unsubscribed: %s\n", email);
            return;
        }
    }
    printf("This email is not found in the mailing list.\n");
}

void viewEmails(const MailingList *list) {
    if (list->count == 0) {
        printf("No emails subscribed to the mailing list.\n");
        return;
    }

    printf("Currently subscribed emails:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->emails[i]);
    }
}

int isEmailInList(const MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            return 1; // Email is found
        }
    }
    return 0; // Email not found
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}