//FormAI DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold contact information 
typedef struct contact {
    char name[30];
    char phone[15];
    char address[50];
} Contact;

// Function to add a contact
void addContact(Contact *contacts, int *count) {
    Contact newContact;
    printf("\nEnter name: ");
    scanf("%s", newContact.name);
    printf("Enter phone number: ");
    scanf("%s", newContact.phone);
    printf("Enter address: ");
    scanf("%s", newContact.address);
    contacts[*count] = newContact;
    *count += 1;
    printf("\nContact added successfully!\n");
}

// Function to search for a contact by name or phone number
void searchContact(Contact *contacts, int count) {
    char searchQuery[30];
    int found = 0;
    printf("\nEnter name or phone number to search for: ");
    scanf("%s", searchQuery);
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchQuery) == 0 || strcmp(contacts[i].phone, searchQuery) == 0) {
            printf("\nContact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Address: %s\n", contacts[i].address);
            found = 1;
        }
    }
    if (!found) {
        printf("\nContact not found.\n");
    }
}

// Function to display all contacts
void displayContacts(Contact *contacts, int count) {
    printf("\nContacts:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s - %s\n", i+1, contacts[i].name, contacts[i].phone, contacts[i].address);
    }
}

int main() {
    Contact *contacts = malloc(100 * sizeof(Contact));
    int count = 0;
    int choice;
    while(1) {
        printf("\n1. Add Contact\n2. Search Contact\n3. Display Contacts\n4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                searchContact(contacts, count);
                break;
            case 3:
                displayContacts(contacts, count);
                break;
            case 4:
                printf("\nGoodbye!\n");
                free(contacts);
                return 0;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
}