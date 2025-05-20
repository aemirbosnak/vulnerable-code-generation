//FormAI DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50

typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

void printMenu() {
    printf("\nOptions:\n");
    printf("1. Add contact\n");
    printf("2. View all contacts\n");
    printf("3. Search contact by name\n");
    printf("4. Edit contact by name\n");
    printf("5. Delete contact by name\n");
    printf("6. Exit\n");
}

void clearInputBuffer() {
    int c = getchar();
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

void addContact(Contact* contacts, int* numContacts) {
    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, MAX_NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0;
    printf("Enter phone number: ");
    fgets(newContact.phone, MAX_PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0;
    printf("Enter email address: ");
    fgets(newContact.email, MAX_EMAIL_LENGTH, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = 0;
    contacts[*numContacts] = newContact;
    (*numContacts)++;
    printf("%s added to contacts.\n", newContact.name);
}

void viewAllContacts(Contact* contacts, int numContacts) {
    if (numContacts == 0) {
        printf("No contacts found.\n");
        return;
    }
    printf("\n%-30s %-15s %-50s\n", "Name", "Phone", "Email");
    for (int i = 0; i < numContacts; i++) {
        printf("%-30s %-15s %-50s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

void searchContact(Contact* contacts, int numContacts) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of contact to search for: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;
    Contact* contact = NULL;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            contact = &contacts[i];
            break;
        }
    }
    if (contact == NULL) {
        printf("Contact not found.\n");
        return;
    }
    printf("\n%-30s %-15s %-50s\n", "Name", "Phone", "Email");
    printf("%-30s %-15s %-50s\n", contact->name, contact->phone, contact->email);
}

void editContact(Contact* contacts, int numContacts) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of contact to edit: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;
    Contact* contact = NULL;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            contact = &contacts[i];
            break;
        }
    }
    if (contact == NULL) {
        printf("Contact not found.\n");
        return;
    }
    printf("Enter new phone number (leave empty to skip): ");
    fgets(contact->phone, MAX_PHONE_LENGTH, stdin);
    contact->phone[strcspn(contact->phone, "\n")] = 0;
    printf("Enter new email address (leave empty to skip): ");
    fgets(contact->email, MAX_EMAIL_LENGTH, stdin);
    contact->email[strcspn(contact->email, "\n")] = 0;
    printf("Contact updated.\n");
}

void deleteContact(Contact* contacts, int* numContacts) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of contact to delete: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;
    int indexToDelete = -1;
    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            indexToDelete = i;
            break;
        }
    }
    if (indexToDelete == -1) {
        printf("Contact not found.\n");
        return;
    }
    Contact contactToDelete = contacts[indexToDelete];
    for (int i = indexToDelete; i < *numContacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    (*numContacts)--;
    printf("%s deleted from contacts.\n", contactToDelete.name);
}

int main() {
    Contact contacts[100];
    int numContacts = 0;
    int running = 1;
    while (running) {
        printMenu();
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                viewAllContacts(contacts, numContacts);
                break;
            case 3:
                searchContact(contacts, numContacts);
                break;
            case 4:
                editContact(contacts, numContacts);
                break;
            case 5:
                deleteContact(contacts, &numContacts);
                break;
            case 6:
                running = 0;
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}