//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: curious
/*
 * Curious C Phone Book Program
 *
 * This program will allow the user to store and manage a phone book.
 * It will allow the user to add, delete, and search for contacts in the phone book.
 */

#include <stdio.h>
#include <string.h>

// Structure to store contact information
struct contact {
    char name[50];
    char phone[20];
};

// Function to add a contact to the phone book
void addContact(struct contact* contacts, int numContacts) {
    int i;
    printf("Enter the name of the contact: ");
    scanf("%s", contacts[numContacts].name);
    printf("Enter the phone number of the contact: ");
    scanf("%s", contacts[numContacts].phone);
    numContacts++;
}

// Function to delete a contact from the phone book
void deleteContact(struct contact* contacts, int numContacts) {
    int i;
    printf("Enter the name of the contact to delete: ");
    scanf("%s", contacts[numContacts].name);
    for (i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, contacts[numContacts].name) == 0) {
            contacts[i].name[0] = '\0';
            contacts[i].phone[0] = '\0';
        }
    }
    numContacts--;
}

// Function to search for a contact in the phone book
void searchContact(struct contact* contacts, int numContacts) {
    int i;
    printf("Enter the name of the contact to search for: ");
    scanf("%s", contacts[numContacts].name);
    for (i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, contacts[numContacts].name) == 0) {
            printf("Contact found! Phone number: %s\n", contacts[i].phone);
            break;
        }
    }
}

int main() {
    struct contact contacts[100];
    int numContacts = 0;
    int choice;
    while (1) {
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact(contacts, numContacts);
                break;
            case 2:
                deleteContact(contacts, numContacts);
                break;
            case 3:
                searchContact(contacts, numContacts);
                break;
            case 4:
                return 0;
        }
    }
    return 0;
}