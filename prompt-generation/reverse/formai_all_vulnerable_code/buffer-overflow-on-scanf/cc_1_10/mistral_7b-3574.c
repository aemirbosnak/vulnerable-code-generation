//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    char phoneNumber[20];
} Contact;

void addContact(Contact contacts[], int *count);
void searchContact(Contact contacts[], int count);
void displayContacts(Contact contacts[], int count);

int main() {
    Contact myContacts[MAX_SIZE];
    int numContacts = 0;

    while (1) {
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(myContacts, &numContacts);
                break;
            case 2:
                searchContact(myContacts, numContacts);
                break;
            case 3:
                displayContacts(myContacts, numContacts);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_SIZE) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }

    printf("Enter contact name: ");
    scanf("%s", contacts[*count].name);

    printf("Enter contact phone number: ");
    scanf("%s", contacts[*count].phoneNumber);

    (*count)++;
}

void searchContact(Contact contacts[], int count) {
    char searchName[50];

    printf("Enter contact name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(searchName, contacts[i].name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone Number: %s\n", contacts[i].phoneNumber);
            return;
        }
    }

    printf("Contact not found.\n");
}

void displayContacts(Contact contacts[], int count) {
    printf("Name\tPhone Number\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t%s\n", contacts[i].name, contacts[i].phoneNumber);
    }
}