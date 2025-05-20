//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_CONTACTS 100

struct Contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
};

void printMenu() {
    printf("\n\nWelcome to MyContacts!\n");
    printf("1. Add a new contact\n");
    printf("2. Display all contacts\n");
    printf("3. Search for a contact by name\n");
    printf("4. Delete a contact\n");
    printf("5. Exit\n");
    printf("Please enter your choice: ");
}

void addContact(struct Contact* contacts, int* numContacts) {
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH], phoneNumber[MAX_PHONE_NUMBER_LENGTH];

    if (*numContacts == MAX_CONTACTS) {
        printf("\nCannot add any more contacts as maximum limit reached!\n");
        return;
    }

    fflush(stdin);
    printf("\nEnter name: ");
    scanf("%[^\n]%*c", name);
    printf("Enter email: ");
    scanf("%[^\n]%*c", email);
    printf("Enter phone number: ");
    scanf("%[^\n]%*c", phoneNumber);

    strcpy(contacts[*numContacts].name, name);
    strcpy(contacts[*numContacts].email, email);
    strcpy(contacts[*numContacts].phoneNumber, phoneNumber);

    *numContacts += 1;

    printf("\nContact added successfully!\n");
}

void displayContacts(struct Contact* contacts, int numContacts) {
    if (numContacts == 0) {
        printf("\nNo contacts found!\n");
        return;
    }

    printf("\nContacts:\n");

    for (int i = 0; i < numContacts; i++) {
        printf(" %d. %s %s %s\n", i+1, contacts[i].name, contacts[i].email, contacts[i].phoneNumber);
    }
}

void searchContact(struct Contact* contacts, int numContacts) {
    if (numContacts == 0) {
        printf("\nNo contacts found!\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    int found = 0;

    fflush(stdin);
    printf("\nEnter name to search: ");
    scanf("%[^\n]%*c", name);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("\nContact found:\n");
            printf(" %s %s %s\n", contacts[i].name, contacts[i].email, contacts[i].phoneNumber);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nNo contact found with name '%s'!\n", name);
    }
}

void deleteContact(struct Contact* contacts, int* numContacts) {
    if (*numContacts == 0) {
        printf("\nNo contacts found!\n");
        return;
    }

    int index;

    printf("\nEnter index of contact to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > *numContacts) {
        printf("\nInvalid index entered!\n");
        return;
    }

    for (int i = index-1; i < *numContacts-1; i++) {
        strcpy(contacts[i].name, contacts[i+1].name);
        strcpy(contacts[i].email, contacts[i+1].email);
        strcpy(contacts[i].phoneNumber, contacts[i+1].phoneNumber);
    }

    *numContacts -= 1;

    printf("\nContact deleted successfully!\n");
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0, choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                searchContact(contacts, numContacts);
                break;
            case 4:
                deleteContact(contacts, &numContacts);
                break;
            case 5:
                printf("\nThank you for using MyContacts!\n");
                break;
            default:
                printf("\nInvalid choice entered! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}