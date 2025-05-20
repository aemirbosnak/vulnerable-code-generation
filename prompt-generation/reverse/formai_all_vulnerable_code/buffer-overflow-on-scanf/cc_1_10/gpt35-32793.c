//FormAI DATASET v1.0 Category: Mailing list manager ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 50
#define MAX_CONTACTS 100

typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct ContactList {
    Contact contacts[MAX_CONTACTS];
    int size;
} ContactList;

void printMenu() {
    printf("\n");
    printf("1. Add a contact\n");
    printf("2. Remove a contact\n");
    printf("3. View all contacts\n");
    printf("4. Exit\n");
}

void addContact(ContactList *list) {
    printf("Enter the name: ");
    char nameInput[MAX_NAME_LENGTH];
    scanf("%s", nameInput);
    strcpy(list->contacts[list->size].name, nameInput);

    printf("Enter the email: ");
    char emailInput[MAX_EMAIL_LENGTH];
    scanf("%s", emailInput);
    strcpy(list->contacts[list->size].email, emailInput);

    list->size++;

    printf("Contact added successfully!\n");
}

void removeContact(ContactList *list) {
    printf("Enter the name of the contact to remove: ");
    char nameInput[MAX_NAME_LENGTH];
    scanf("%s", nameInput);

    int contactIndex = -1;
    for (int i = 0; i < list->size; i++) {
        if (strcmp(nameInput, list->contacts[i].name) == 0) {
            contactIndex = i;
            break;
        }
    }

    if (contactIndex == -1) {
        printf("Contact not found!\n");
    } else {
        list->size--;
        for (int i = contactIndex; i < list->size; i++) {
            list->contacts[i] = list->contacts[i+1];
        }
        printf("Contact removed successfully!\n");
    }
}

void viewContacts(ContactList *list) {
    printf("Name\t\tEmail\n");
    for (int i = 0; i < list->size; i++) {
        printf("%s\t\t%s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    ContactList list;
    list.size = 0;

    while (1) {
        printMenu();
        printf("Enter an option: ");
        int option;
        scanf("%d", &option);

        switch(option) {
            case 1:
                addContact(&list);
                break;
            case 2:
                removeContact(&list);
                break;
            case 3:
                viewContacts(&list);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option chosen!\n");
                break;
        }
    }

    return 0;
}