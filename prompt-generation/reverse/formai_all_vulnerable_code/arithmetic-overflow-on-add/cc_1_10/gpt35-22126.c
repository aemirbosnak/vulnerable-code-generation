//FormAI DATASET v1.0 Category: Mailing list manager ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_ENTRIES 1000

struct Contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

struct MailingList {
    char name[MAX_NAME_LENGTH];
    struct Contact contacts[MAX_ENTRIES];
    int numContacts;
};

void addContact(struct MailingList *list) {
    if (list->numContacts == MAX_ENTRIES) {
        printf("Mailing list is full!\n");
        return;
    }

    struct Contact newContact;

    printf("Enter contact name: ");
    scanf("%s", newContact.name);

    printf("Enter contact email: ");
    scanf("%s", newContact.email);

    printf("Enter contact phone number: ");
    scanf("%s", newContact.phone);

    list->contacts[list->numContacts++] = newContact;

    printf("Contact added successfully!\n");
}

void printContact(struct Contact *contact) {
    printf("Name: %s\n", contact->name);
    printf("Email: %s\n", contact->email);
    printf("Phone: %s\n", contact->phone);
}

void printList(struct MailingList *list) {
    printf("Mailing List: %s\n", list->name);

    for (int i = 0; i < list->numContacts; i++) {
        printf("Contact %d:\n", i + 1);
        printContact(&list->contacts[i]);
    }
}

int main(int argc, char const *argv[]) {
    struct MailingList list;
    list.numContacts = 0;

    printf("Enter the name of your mailing list: ");
    scanf("%s", list.name);

    int choice;
    do {
        printf("\n1. Add a contact\n");
        printf("2. Print the mailing list\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&list);
                break;
            case 2:
                printList(&list);
                break;
            case 3:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}