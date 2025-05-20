//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store a contact
typedef struct Contact {
    char name[50];
    char phone[20];
} Contact;

// Function to compare two contacts
int compareContacts(const void *a, const void *b) {
    const Contact *contact1 = (const Contact *)a;
    const Contact *contact2 = (const Contact *)b;
    return strcmp(contact1->name, contact2->name);
}

// Function to search for a contact
Contact *searchContact(Contact *contacts, int numContacts, char *name) {
    int low = 0;
    int high = numContacts - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (strcmp(contacts[mid].name, name) == 0) {
            return &contacts[mid];
        } else if (strcmp(contacts[mid].name, name) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return NULL;
}

// Main function
int main() {
    // Initialize the phone book
    Contact contacts[] = {
        {"John Doe", "555-1212"},
        {"Jane Doe", "555-1213"},
        {"Bob Smith", "555-1214"},
        {"Alice Johnson", "555-1215"},
        {"Tom Jones", "555-1216"}
    };
    int numContacts = sizeof(contacts) / sizeof(contacts[0]);

    // Sort the contacts by name
    qsort(contacts, numContacts, sizeof(Contact), compareContacts);

    // Prompt the user for a name to search for
    char name[50];
    printf("Enter a name to search for: ");
    scanf("%s", name);

    // Search for the contact
    Contact *contact = searchContact(contacts, numContacts, name);

    // If the contact was found, print their information
    if (contact != NULL) {
        printf("%s: %s\n", contact->name, contact->phone);
    } else {
        printf("Contact not found\n");
    }

    return 0;
}