//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: creative
// A creative C phone book example program

#include <stdio.h>

// Structure to store contact details
struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

// Function to add a new contact
void addContact(struct Contact *contact) {
    printf("Enter name: ");
    scanf("%s", contact->name);
    printf("Enter phone: ");
    scanf("%s", contact->phone);
    printf("Enter email: ");
    scanf("%s", contact->email);
}

// Function to search for a contact
void searchContact(struct Contact *contacts, int n) {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < n; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found contact: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            return;
        }
    }
    printf("Contact not found\n");
}

// Function to print all contacts
void printContacts(struct Contact *contacts, int n) {
    printf("Contacts:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", contacts[i].name);
        printf("%s\n", contacts[i].phone);
        printf("%s\n", contacts[i].email);
    }
}

int main() {
    // Create an array of structs to store contact details
    struct Contact contacts[10];

    // Add some sample contacts
    addContact(&contacts[0]);
    addContact(&contacts[1]);
    addContact(&contacts[2]);

    // Search for a contact
    searchContact(contacts, 3);

    // Print all contacts
    printContacts(contacts, 3);

    return 0;
}