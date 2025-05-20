//FormAI DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 100

/* Struct to represent a contact */
typedef struct {
    char name[25];
    long int phoneNum;
} Contact;

/* Function to add a new contact */
void addContact(Contact book[], int *size)
{
    if (*size == MAX_CONTACTS) { // Check if phone book is full
        printf("Phone book is full, delete some contacts before adding new ones.\n");
        return;
    }

    Contact newContact;

    printf("Enter name: ");
    scanf("%s", newContact.name);

    printf("Enter phone number: ");
    scanf("%ld", &newContact.phoneNum);

    book[*size] = newContact;
    (*size)++;

    printf("Contact added successfully!\n");
}

/* Function to remove an existing contact */
void removeContact(Contact book[], int *size)
{
    if (*size == 0) { // Check if phone book is empty
        printf("Phone book is empty, add some contacts before deleting.\n");
        return;
    }

    char nameToRemove[25];

    printf("Enter name of contact to remove: ");
    scanf("%s", nameToRemove);

    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp(nameToRemove, book[i].name) == 0) { // Contact found
            printf("Are you sure you want to delete %s from phone book? (y/n): ", nameToRemove);

            char confirmation;
            scanf(" %c", &confirmation);
            if (confirmation == 'y') {
                book[i] = book[*size-1]; // Replace contact with the last one in the book
                (*size)--;
                printf("Contact removed successfully!\n");
            } else {
                printf("Contact not removed.\n");
            }

            return;
        }
    }

    printf("Contact not found in phone book.\n");
}

/* Function to search for a contact */
void searchContact(Contact book[], int size)
{
    if (size == 0) { // Check if phone book is empty
        printf("Phone book is empty, add some contacts before searching.\n");
        return;
    }

    char nameToSearch[25];

    printf("Enter name of contact to search: ");
    scanf("%s", nameToSearch);

    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(nameToSearch, book[i].name) == 0) { // Contact found
            printf("%s's phone number is %ld.\n", book[i].name, book[i].phoneNum);
            return;
        }
    }

    printf("Contact not found in phone book.\n");
}

/* Function to display all contacts in the phone book */
void displayContacts(Contact book[], int size)
{
    if (size == 0) { // Check if phone book is empty
        printf("Phone book is empty, add some contacts before displaying.\n");
        return;
    }

    printf("Phone book contacts:\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("%s\t%ld\n", book[i].name, book[i].phoneNum);
    }
}

/* Main function */
int main()
{
    Contact phoneBook[MAX_CONTACTS];
    int numContacts = 0;
    int menuChoice;

    do {
        printf("\nPhone book options:\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Search contacts\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);

        switch(menuChoice) {
            case 1:
                addContact(phoneBook, &numContacts);
                break;
            case 2:
                removeContact(phoneBook, &numContacts);
                break;
            case 3:
                searchContact(phoneBook, numContacts);
                break;
            case 4:
                displayContacts(phoneBook, numContacts);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (menuChoice != 5);

    return 0;
}