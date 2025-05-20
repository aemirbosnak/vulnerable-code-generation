//FormAI DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100 // This program can store a maximum of 100 contacts

struct Contact {
    char name[50];
    char phone_number[15];
};

void addContact(struct Contact *contacts, int *numContacts);
void displayContacts(struct Contact *contacts, int numContacts);
void searchContacts(struct Contact *contacts, int numContacts);

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int userInput;

    printf("Welcome to My Phone Book App!\n");

    do {
        printf("\nMenu Options:\n");
        printf("1. Add a Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &userInput);

        switch (userInput) {
            case 1:
                addContact(contacts, &numContacts);
                break;

            case 2:
                displayContacts(contacts, numContacts);
                break;

            case 3:
                searchContacts(contacts, numContacts);
                break;

            case 4:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid Input! Please try again.\n");
                break;
        }
    } while (userInput != 4);

    return 0;
}

void addContact(struct Contact *contacts, int *numContacts) {
    if (*numContacts == MAX_CONTACTS) {
        printf("\nSorry, you have reached the maximum number of contacts.\n");
        return;
    }

    printf("\nEnter name: ");
    scanf("%s", contacts[*numContacts].name);

    printf("Enter phone number: ");
    scanf("%s", contacts[*numContacts].phone_number);

    (*numContacts)++;
    printf("\nContact added successfully!\n");
}

void displayContacts(struct Contact *contacts, int numContacts) {
    printf("\nList of contacts:\n");

    if (numContacts == 0) {
        printf("No contacts found!\n");
        return;
    }

    for (int i = 0; i < numContacts; i++) {
        printf("%d. %s - %s\n", i+1, contacts[i].name, contacts[i].phone_number);
    }
}

void searchContacts(struct Contact *contacts, int numContacts) {
    char query[50];
    int found = 0;

    printf("\nEnter name or phone number: ");
    scanf("%s", query);

    for (int i = 0; i < numContacts; i++) {
        if (strstr(contacts[i].name, query) || strstr(contacts[i].phone_number, query)) {
            printf("%d. %s - %s\n", i+1, contacts[i].name, contacts[i].phone_number);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching contacts found!\n");
    }
}