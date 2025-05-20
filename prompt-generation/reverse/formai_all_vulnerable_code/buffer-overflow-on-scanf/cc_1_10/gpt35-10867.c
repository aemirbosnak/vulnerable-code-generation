//FormAI DATASET v1.0 Category: Mailing list manager ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_EMAILS];
    int count;
} MailingList;

void addContact(MailingList *mailingList, const char name[], const char email[]) {
    if (mailingList->count >= MAX_EMAILS) {
        printf("Mailing list is full!\n");
        return;
    }
    if (strlen(name) >= MAX_NAME_LENGTH || strlen(email) >= MAX_EMAIL_LENGTH) {
        printf("Please enter a name and email address with less than 50 characters.\n");
        return;
    }
    Contact newContact;
    strcpy(newContact.name, name);
    strcpy(newContact.email, email);
    mailingList->contacts[mailingList->count] = newContact;
    mailingList->count++;
}

void printList(MailingList mailingList) {
    printf("Mailing list (%d contacts):\n", mailingList.count);
    for (int i = 0; i < mailingList.count; i++) {
        printf("%s: %s\n", mailingList.contacts[i].name, mailingList.contacts[i].email);
    }
}

void menu() {
    printf("\nMailing List Manager\n");
    printf("1. Add contact\n");
    printf("2. Print all contacts\n");
    printf("3. Quit\n");
    printf("Choose an option: ");
}

int main() {
    MailingList mailingList;
    mailingList.count = 0;

    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int choice;

    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addContact(&mailingList, name, email);
                break;
            case 2:
                printList(mailingList);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}