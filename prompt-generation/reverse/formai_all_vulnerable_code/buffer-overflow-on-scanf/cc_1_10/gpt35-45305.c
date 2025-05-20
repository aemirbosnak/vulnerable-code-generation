//FormAI DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for holding contact information
typedef struct contact {
    char name[20];
    char number[15];
    char email[30];
} Contact;

// Function prototypes
void addContact(Contact* phonebook, int* count);
void printContacts(Contact* phonebook, int count);
void searchContacts(Contact* phonebook, int count);

int main() {
    Contact phonebook[100]; // Maximum of 100 contacts
    int count = 0; // Keep track of number of contacts

    int choice;
    do {
        printf("C Phone Book\n");
        printf("==========\n");
        printf("1. Add Contact\n");
        printf("2. Print Contacts\n");
        printf("3. Search Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(phonebook, &count);
                break;
            case 2:
                printContacts(phonebook, count);
                break;
            case 3:
                searchContacts(phonebook, count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a new contact to the phone book
void addContact(Contact* phonebook, int* count) {
    Contact newContact;

    // Get input from user
    printf("Enter name: ");
    scanf("%s", newContact.name);
    printf("Enter phone number: ");
    scanf("%s", newContact.number);
    printf("Enter email address: ");
    scanf("%s", newContact.email);

    // Add new contact to end of phonebook array
    phonebook[*count] = newContact;
    (*count)++;

    printf("Contact added successfully!\n");
}

// Function to print all contacts in the phone book
void printContacts(Contact* phonebook, int count) {
    if (count == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n   %s\n   %s\n", i+1, phonebook[i].name, phonebook[i].number, phonebook[i].email);
    }
}

// Function to search for a contact in the phone book
void searchContacts(Contact* phonebook, int count) {
    if (count == 0) {
        printf("No contacts found.\n");
        return;
    }

    char searchName[20];
    int found = 0;

    // Get input from user
    printf("Enter name to search for: ");
    scanf("%s", searchName);

    // Check if name is in phonebook
    for (int i = 0; i < count; i++) {
        if (strcmp(searchName, phonebook[i].name) == 0) {
            printf("%s:\n   %s\n   %s\n", phonebook[i].name, phonebook[i].number, phonebook[i].email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No contacts found with name \"%s\".\n", searchName);
    }
}