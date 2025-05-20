//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

struct Contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

void addContact(struct Contact *contacts[], int numContacts) {
    printf("Enter name: ");
    scanf("%s", contacts[numContacts]->name);

    printf("Enter number: ");
    scanf("%s", contacts[numContacts]->number);

    numContacts++;
}

void displayContacts(struct Contact *contacts[], int numContacts) {
    printf("\nPhonebook:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%d. %s\t%s\n", i+1, contacts[i]->name, contacts[i]->number);
    }
}

void searchContact(struct Contact *contacts[], int numContacts) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i]->name, name) == 0) {
            printf("%s\t%s\n", contacts[i]->name, contacts[i]->number);
        }
    }
}

int main() {
    struct Contact *contacts[MAX_CONTACTS];
    int numContacts = 0;

    printf("Welcome to the Post-Apocalyptic Phonebook!\n");

    while (numContacts < MAX_CONTACTS) {
        int choice;
        printf("\n1. Add contact\n2. Display phonebook\n3. Search contact\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, numContacts);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                searchContact(contacts, numContacts);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}