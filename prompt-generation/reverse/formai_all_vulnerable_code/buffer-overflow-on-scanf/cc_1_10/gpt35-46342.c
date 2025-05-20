//FormAI DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 20
#define NUMBER_LENGTH 10
#define MAX_CONTACTS 100

typedef struct Contact {
    char name[NAME_LENGTH];
    char number[NUMBER_LENGTH];
} Contact;

typedef struct ContactList {
    Contact contacts[MAX_CONTACTS];
    int numContacts;
} ContactList;

void addContact(ContactList *list, char *name, char *number) {
    if (list->numContacts == MAX_CONTACTS) {
        printf("Error: Contact list is full\n");
        return;
    }

    Contact c;
    strncpy(c.name, name, NAME_LENGTH);
    strncpy(c.number, number, NUMBER_LENGTH);
    list->contacts[list->numContacts] = c;
    list->numContacts++;
}

void printContacts(ContactList *list) {
    printf("Contacts:\n");
    for (int i = 0; i < list->numContacts; i++) {
        printf("%s: %s\n", list->contacts[i].name, list->contacts[i].number);
    }
}

void searchContacts(ContactList *list, char *name) {
    printf("Search Results for '%s':\n", name);
    int found = 0;
    for (int i = 0; i < list->numContacts; i++) {
        if (strncmp(list->contacts[i].name, name, NAME_LENGTH) == 0) {
            printf("%s: %s\n", list->contacts[i].name, list->contacts[i].number);
            found = 1;
        }
    }
    if (!found) {
        printf("No results found.\n");
    }
}

int main(void) {
    ContactList list;
    list.numContacts = 0;

    while (1) {
        printf("Enter the number of the action you want to perform:\n"
               "1. Add contact\n"
               "2. Print contacts\n"
               "3. Search contacts\n"
               "4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[NAME_LENGTH];
                char number[NUMBER_LENGTH];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                addContact(&list, name, number);
                break;
            }
            case 2: {
                printContacts(&list);
                break;
            }
            case 3: {
                char name[NAME_LENGTH];
                printf("Enter name to search: ");
                scanf("%s", name);
                searchContacts(&list, name);
                break;
            }
            case 4: {
                printf("Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Try again.\n");
            }
        }
    }

    return 0;
}