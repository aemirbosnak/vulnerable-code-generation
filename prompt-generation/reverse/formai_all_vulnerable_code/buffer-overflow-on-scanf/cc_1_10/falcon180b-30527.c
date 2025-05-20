//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for each contact
typedef struct {
    char name[50];
    char phone[15];
} Contact;

// Function to add a new contact
void addContact(Contact* contacts, int numContacts, char* name, char* phone) {
    if (numContacts == 0) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(contacts[numContacts].name, name);
    strcpy(contacts[numContacts].phone, phone);
    numContacts++;
}

// Function to search for a contact
int searchContact(Contact* contacts, int numContacts, char* name) {
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            return 1;
        }
    }

    printf("Contact not found.\n");
    return 0;
}

// Function to display all contacts
void displayContacts(Contact* contacts, int numContacts) {
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
    }
}

int main() {
    Contact contacts[100];
    int numContacts = 0;

    // Initialize phone book with some contacts
    addContact(contacts, numContacts, "John Doe", "123-456-7890");
    addContact(contacts, numContacts, "Jane Smith", "987-654-3210");

    // Search for a contact
    char nameToSearch[50];
    printf("Enter name to search: ");
    scanf("%s", nameToSearch);
    searchContact(contacts, numContacts, nameToSearch);

    // Display all contacts
    printf("\nAll contacts:\n");
    displayContacts(contacts, numContacts);

    return 0;
}