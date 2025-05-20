//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_LENGTH 100

void addEmail(char emails[MAX_EMAILS][MAX_LENGTH], int *count) {
    if (*count >= MAX_EMAILS) {
        printf("The mailing list is full!\n");
        return;
    }
    printf("Enter email to add: ");
    scanf("%s", emails[*count]);
    (*count)++;
    printf("Email added successfully!\n");
}

void removeEmail(char emails[MAX_EMAILS][MAX_LENGTH], int *count) {
    char emailToRemove[MAX_LENGTH];
    printf("Enter email to remove: ");
    scanf("%s", emailToRemove);

    for (int i = 0; i < *count; i++) {
        if (strcmp(emails[i], emailToRemove) == 0) {
            // Shift the emails to remove the element
            for (int j = i; j < *count - 1; j++) {
                strcpy(emails[j], emails[j + 1]);
            }
            (*count)--;
            printf("Email removed successfully!\n");
            return;
        }
    }
    printf("Email not found in the list!\n");
}

void displayEmails(char emails[MAX_EMAILS][MAX_LENGTH], int count) {
    if (count == 0) {
        printf("The mailing list is empty.\n");
        return;
    }
    printf("Current Mailing List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, emails[i]);
    }
}

void searchEmail(char emails[MAX_EMAILS][MAX_LENGTH], int count) {
    char emailToSearch[MAX_LENGTH];
    printf("Enter email to search: ");
    scanf("%s", emailToSearch);

    for (int i = 0; i < count; i++) {
        if (strcmp(emails[i], emailToSearch) == 0) {
            printf("Email %s found at position %d.\n", emailToSearch, i + 1);
            return;
        }
    }
    printf("Email not found in the list!\n");
}

int main() {
    char emails[MAX_EMAILS][MAX_LENGTH];
    int count = 0;
    int choice;

    do {
        printf("\n--- Mailing List Manager ---\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Emails\n");
        printf("4. Search Email\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmail(emails, &count);
                break;
            case 2:
                removeEmail(emails, &count);
                break;
            case 3:
                displayEmails(emails, count);
                break;
            case 4:
                searchEmail(emails, count);
                break;
            case 5:
                printf("Exiting... Have a great day!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}