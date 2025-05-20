//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char emails[MAX_EMAILS][MAX_EMAIL_LENGTH];
    int count;
} MailingList;

void initializeList(MailingList *list) {
    list->count = 0;
}

void addEmail(MailingList *list, const char *email) {
    if (list->count < MAX_EMAILS) {
        strcpy(list->emails[list->count], email);
        list->count++;
        printf("Email '%s' added to the mailing list.\n", email);
    } else {
        printf("Error: Mailing list is full. Cannot add more emails.\n");
    }
}

void removeEmail(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            // Shift emails to the left
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            printf("Email '%s' removed from the mailing list.\n", email);
            return;
        }
    }
    printf("Error: Email '%s' not found in the mailing list.\n", email);
}

void viewEmails(const MailingList *list) {
    printf("Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->emails[i]);
    }
}

void menu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Email\n");
    printf("2. Remove Email\n");
    printf("3. View Emails\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MailingList list;
    initializeList(&list);
    
    int option;
    char email[MAX_EMAIL_LENGTH];

    while (1) {
        menu();
        scanf("%d", &option);
        getchar(); // Consume newline left in the buffer

        switch (option) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                addEmail(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                removeEmail(&list, email);
                break;
            case 3:
                viewEmails(&list);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}