//FormAI DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    struct Contact *next;
};

struct Contact *contactsList = NULL;

void addContact(struct Contact *newContact) {
    if (contactsList == NULL) {
        contactsList = newContact;
    } else {
        if (strcmp(newContact->name, contactsList->name) <= 0) {
            newContact->next = contactsList;
            contactsList = newContact;
        } else {
            struct Contact *previous = contactsList;
            struct Contact *current = contactsList->next;
            while (current != NULL && strcmp(newContact->name, current->name) > 0) {
                previous = current;
                current = current->next;
            }
            previous->next = newContact;
            newContact->next = current;
        }
    }
}

void printContacts(struct Contact *currentContact) {
    if (currentContact == NULL) {
        printf("Phone book is empty.\n");
    } else {
        printf("Name: %s | Phone: %s\n", currentContact->name, currentContact->phone);
        printContacts(currentContact->next);
    }
}

struct Contact *findContact(char *name, struct Contact *currentContact) {
    if (currentContact == NULL) {
        return NULL;
    } else {
        if (strcmp(name, currentContact->name) == 0) {
            return currentContact;
        } else {
            return findContact(name, currentContact->next);
        }
    }
}

void deleteContact(char *name) {
    if (contactsList == NULL) {
        printf("Phone book is empty.\n");
    } else {
        if (strcmp(name, contactsList->name) == 0) {
            contactsList = contactsList->next;
        } else {
            struct Contact *previous = contactsList;
            struct Contact *current = contactsList->next;
            while (current != NULL && strcmp(name, current->name) != 0) {
                previous = current;
                current = current->next;
            }
            if (current == NULL) {
                printf("Contact not found.\n");
            } else {
                previous->next = current->next;
            }
        }
    }
}

int main() {
    char choice;
    do {
        printf("\n1. Add contact\n");
        printf("2. Print contacts\n");
        printf("3. Find contact\n");
        printf("4. Delete contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1': {
                struct Contact *newContact = malloc(sizeof(struct Contact));
                printf("Enter contact name: ");
                scanf("%s", newContact->name);
                printf("Enter contact phone: ");
                scanf("%s", newContact->phone);
                newContact->next = NULL;
                addContact(newContact);
                printf("Contact added successfully.\n");
                break;
            }
            case '2': {
                printContacts(contactsList);
                break;
            }
            case '3': {
                char name[MAX_NAME_LENGTH];
                printf("Enter contact name: ");
                scanf("%s", name);
                struct Contact *foundContact = findContact(name, contactsList);
                if (foundContact == NULL) {
                    printf("Contact not found.\n");
                } else {
                    printf("Name: %s | Phone: %s\n", foundContact->name, foundContact->phone);
                }
                break;
            }
            case '4': {
                char name[MAX_NAME_LENGTH];
                printf("Enter contact name: ");
                scanf("%s", name);
                deleteContact(name);
                break;
            }
            case '5': {
                printf("Goodbye!\n");
                break;
            }
            default: {
                printf("Invalid choice, please try again.\n");
                break;
            }
        }
    } while (choice != '5');

    return 0;
}