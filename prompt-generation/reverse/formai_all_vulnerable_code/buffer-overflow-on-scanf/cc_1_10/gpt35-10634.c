//FormAI DATASET v1.0 Category: Mailing list manager ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

Contact emails[MAX_EMAILS];
int numOfEmails = 0;

void addEmail() {
    if (numOfEmails >= MAX_EMAILS) {
        printf("Mailing list is full!\n");
        return;
    }

    Contact newEmail;
    printf("Enter contact name: ");
    fgets(newEmail.name, sizeof(newEmail.name), stdin);

    printf("Enter contact email: ");
    fgets(newEmail.email, sizeof(newEmail.email), stdin);

    emails[numOfEmails++] = newEmail;

    printf("Email added to mailing list!\n");
}

void showEmails() {
    printf("Mailing List:\n");
    for (int i = 0; i < numOfEmails; i++) {
        printf("%d. %s - %s", i+1, emails[i].name, emails[i].email);
    }
}

void removeEmail() {
    int emailNum;
    printf("Enter the number of the email you want to remove: ");
    scanf("%d", &emailNum);

    if (emailNum < 1 || emailNum > numOfEmails) {
        printf("Invalid email number!\n");
        return;
    }

    for (int i = emailNum-1; i < numOfEmails-1; i++) {
        emails[i] = emails[i+1];
    }

    numOfEmails--;
    printf("Email removed from mailing list!\n");
}

int main() {
    int choice;

    do {
        printf("\nMailing List Manager:\n");
        printf("1. Add an email\n");
        printf("2. Show all emails\n");
        printf("3. Remove an email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                addEmail();
                break;
            case 2:
                showEmails();
                break;
            case 3:
                removeEmail();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}