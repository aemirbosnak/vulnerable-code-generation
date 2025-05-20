//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 100

typedef struct {
    char emails[MAX_EMAILS][EMAIL_LENGTH];
    int count;
} MailingList;

void initializeMailingList(MailingList *list) {
    list->count = 0;
}

void addEmail(MailingList *list, const char *email) {
    if (list->count < MAX_EMAILS) {
        strncpy(list->emails[list->count], email, EMAIL_LENGTH);
        list->emails[list->count][EMAIL_LENGTH - 1] = '\0'; // Ensure null termination
        list->count++;
        printf("Peacefully added: %s\n", email);
    } else {
        printf("The mailing list is full. You cannot add more emails.\n");
    }
}

void removeEmail(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            printf("Gently removing: %s\n", email);
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            return;
        }
    }
    printf("The email %s was not found in the peaceful list.\n", email);
}

void displayEmails(const MailingList *list) {
    printf("\n--- Current Mailing List ---\n");
    for (int i = 0; i < list->count; i++) {
        printf(" %d: %s\n", i + 1, list->emails[i]);
    }
    printf("---------------------------\n");
}

int main() {
    MailingList list;
    initializeMailingList(&list);
    char email[EMAIL_LENGTH];
    int choice;

    while (1) {
        printf("\nWelcome to the Peaceful Mailing List Manager\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Emails\n");
        printf("4. Exit\n");
        printf("Please enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                addEmail(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeEmail(&list, email);
                break;
            case 3:
                displayEmails(&list);
                break;
            case 4:
                printf("Exiting peacefully. Have a wonderful day!\n");
                exit(0);
            default:
                printf("Please enter a valid choice (1-4).\n");
        }
    }

    return 0;
}