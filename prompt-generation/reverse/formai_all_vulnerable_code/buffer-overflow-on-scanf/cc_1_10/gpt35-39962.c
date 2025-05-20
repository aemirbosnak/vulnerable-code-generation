//FormAI DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 200

struct Email {
    char sender[30];
    char recipient[30];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
};

struct Email inbox[MAX_EMAILS];
int numOfEmails = 0;

void composeEmail() {
    struct Email newEmail;

    printf("Enter recipient email address: ");
    scanf("%s", newEmail.recipient);
    printf("Enter subject: ");
    scanf("%s", newEmail.subject);
    printf("Enter body: ");
    scanf("%s", newEmail.body);
    // assuming sender is current user
    strcpy(newEmail.sender, "current_user@mycompany.com");

    inbox[numOfEmails++] = newEmail;
    printf("Email sent!\n");
}

void printEmails() {
    if (numOfEmails == 0) {
        printf("Inbox is empty.\n");
        return;
    }

    printf("Inbox:\n");
    for (int i = 0; i < numOfEmails; i++) {
        printf("%d. From: %s\n", i+1, inbox[i].sender);
        printf("   Subject: %s\n", inbox[i].subject);
        printf("   Body: %s\n", inbox[i].body);
    }
}

void searchEmails() {
    char searchQuery[MAX_BODY_LENGTH];
    int searchMatches = 0;

    printf("Enter search term: ");
    scanf("%s", searchQuery);

    for (int i = 0; i < numOfEmails; i++) {
        if (strstr(inbox[i].subject, searchQuery) || strstr(inbox[i].body, searchQuery)) {
            printf("%d. From: %s\n", i+1, inbox[i].sender);
            printf("   Subject: %s\n", inbox[i].subject);
            printf("   Body: %s\n", inbox[i].body);
            searchMatches++;
        }
    }

    if (searchMatches == 0)
        printf("No matches found.\n");
    else
        printf("%d match(es) found.\n", searchMatches);
}

int main() {
    int choice;

    printf("Welcome to My Email Client!\n");

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Search Emails\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                composeEmail();
                break;
            case 2:
                printEmails();
                break;
            case 3:
                searchEmails();
                break;
            case 4:
                printf("Thank you for using My Email Client!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}