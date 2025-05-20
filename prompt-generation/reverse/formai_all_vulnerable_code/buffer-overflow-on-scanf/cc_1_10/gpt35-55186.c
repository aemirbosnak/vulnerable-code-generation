//FormAI DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100 // maximum number of contacts

// Contact struct definition
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

// Function prototypes
void displayMenu();
void addContact(Contact contacts[], int *numContacts);
void editContact(Contact contacts[], int numContacts);
void deleteContact(Contact contacts[], int *numContacts);
void searchContact(Contact contacts[], int numContacts);
void displayAllContacts(Contact contacts[], int numContacts);

int main() {
    Contact contacts[MAX_CONTACTS]; // array to hold contacts
    int numContacts = 0; // variable to keep track of number of contacts

    int choice; // variable to store user's menu choice
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                editContact(contacts, numContacts);
                break;
            case 3:
                deleteContact(contacts, &numContacts);
                break;
            case 4:
                searchContact(contacts, numContacts);
                break;
            case 5:
                displayAllContacts(contacts, numContacts);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("---------------------------------\n");
    printf("            PHONE BOOK           \n");
    printf("---------------------------------\n");
    printf("[1] Add Contact\n");
    printf("[2] Edit Contact\n");
    printf("[3] Delete Contact\n");
    printf("[4] Search Contact\n");
    printf("[5] Display All Contacts\n");
    printf("[6] Exit\n");
}

// Function to add a new contact
void addContact(Contact contacts[], int *numContacts) {
    char name[50];
    char phone[20];
    char email[50];

    if (*numContacts == MAX_CONTACTS) {
        printf("Sorry, you have reached the maximum number of contacts.");
    } else {
        printf("Enter contact details:\n");
        printf("Name: ");
        scanf("%s", name);
        printf("Phone: ");
        scanf("%s", phone);
        printf("Email: ");
        scanf("%s", email);

        Contact newContact;
        strcpy(newContact.name, name);
        strcpy(newContact.phone, phone);
        strcpy(newContact.email, email);

        contacts[*numContacts] = newContact;
        *numContacts = *numContacts + 1;

        printf("Contact has been added.\n");
    }
}

// Function to edit a contact
void editContact(Contact contacts[], int numContacts) {
    char name[50];
    char phone[20];
    char email[50];
    int found = 0;

    printf("Enter the name of the contact you want to edit: ");
    scanf("%s", name);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Enter new details:\n");
            printf("Name: ");
            scanf("%s", name);
            printf("Phone: ");
            scanf("%s", phone);
            printf("Email: ");
            scanf("%s", email);

            strcpy(contacts[i].name, name);
            strcpy(contacts[i].phone, phone);
            strcpy(contacts[i].email, email);

            printf("Contact has been updated.\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact
void deleteContact(Contact contacts[], int *numContacts) {
    char name[50];
    int found = 0;

    printf("Enter the name of the contact you want to delete: ");
    scanf("%s", name);

    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *numContacts - 1; j++) {
                contacts[j] = contacts[j+1];
            }
            *numContacts = *numContacts - 1;
            printf("Contact has been deleted.\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to search for a contact
void searchContact(Contact contacts[], int numContacts) {
    char name[50];
    int found = 0;

    printf("Enter the name of the contact you want to search: ");
    scanf("%s", name);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to display all contacts
void displayAllContacts(Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("No contacts found.\n");
    } else {
        printf("All contacts:\n");
        for (int i = 0; i < numContacts; i++) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            printf("------------\n");
        }
    }
}