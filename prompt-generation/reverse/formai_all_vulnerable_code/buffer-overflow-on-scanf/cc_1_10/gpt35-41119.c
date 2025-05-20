//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 50
#define MAX_LIST_SIZE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_LIST_SIZE];
    int size;
} MailingList;

MailingList list1, list2;

void printMenu() {
    printf("Choose an option:\n");
    printf("1. Add contact to list\n");
    printf("2. Remove contact from list\n");
    printf("3. Print list\n");
    printf("4. Exit\n");
}

void addContact(MailingList* list) {
    if (list->size >= MAX_LIST_SIZE) {
        printf("List is full\n");
        return;
    }

    Contact newContact;

    printf("Enter contact name: ");
    scanf("%s", newContact.name);

    printf("Enter contact email: ");
    scanf("%s", newContact.email);

    list->contacts[list->size] = newContact;
    list->size++;

    printf("Contact added successfully\n");
}

void removeContact(MailingList* list) {
    char emailToRemove[MAX_EMAIL_LENGTH];
    bool foundContact = false;

    printf("Enter the email of the contact to remove: ");
    scanf("%s", emailToRemove);

    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->contacts[i].email, emailToRemove) == 0) {
            foundContact = true;

            for (int j = i; j < list->size - 1; j++) {
                list->contacts[j] = list->contacts[j+1];
            }

            list->size--;

            printf("Contact removed successfully\n");
            break;
        }
    }

    if (!foundContact) {
        printf("Contact not found\n");
    }
}

void printList(MailingList* list) {
    for (int i = 0; i < list->size; i++) {
        printf("%s, %s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    list1.size = 0;
    list2.size = 0;

    printf("Welcome to the Mailing List Manager!\n");

    int choice = 0;

    while (choice != 4) {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact(&list1);
                break;
            case 2:
                removeContact(&list1);
                break;
            case 3:
                printf("List 1:\n");
                printList(&list1);

                printf("List 2:\n");
                printList(&list2);

                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}