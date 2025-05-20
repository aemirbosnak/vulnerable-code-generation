//FormAI DATASET v1.0 Category: Phone Book ; Style: relaxed
//This is a simple phone book program written in C
//It allows users to add, search, and modify contacts in their phone book

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char number[15];
} Contact;

void addContact(Contact *contacts, int *nContacts);
void searchContact(Contact *contacts, int nContacts);
void modifyContact(Contact *contacts, int nContacts);

int main() {
    Contact *contacts = (Contact*)malloc(sizeof(Contact));
    int nContacts = 0;

    int choice;
    do {
        printf("Phone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Modify Contact\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact(contacts, &nContacts);
                break;
            case 2:
                searchContact(contacts, nContacts);
                break;
            case 3:
                modifyContact(contacts, nContacts);
                break;
            case 4:
                printf("Exiting Phone Book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    free(contacts);
    return 0;
}

void addContact(Contact *contacts, int *nContacts) {
    printf("Add Contact:\n");
    printf("Name: ");
    scanf("%s", contacts[*nContacts].name);
    printf("Number: ");
    scanf("%s", contacts[*nContacts].number);
    *nContacts = *nContacts + 1;
    printf("Contact added.\n");
}

void searchContact(Contact *contacts, int nContacts) {
    printf("Search Contact:\n");
    printf("Name: ");
    char name[50];
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < nContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Number: %s\n", contacts[i].number);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void modifyContact(Contact *contacts, int nContacts) {
    printf("Modify Contact:\n");
    printf("Name: ");
    char name[50];
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < nContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Enter new number: ");
            scanf("%s", contacts[i].number);
            printf("Contact modified.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}