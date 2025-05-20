//FormAI DATASET v1.0 Category: Phone Book ; Style: relaxed
#include <stdio.h>
#include <string.h>

// Struct declaration for contact information
typedef struct {
    char name[50];
    char phoneNum[15];
    char email[50];
} Contact;

// Function declarations
void addContact(Contact[], int*);
void viewContacts(Contact[], int);
void searchContacts(Contact[], int);
void deleteContact(Contact[], int*);

int main() {
    Contact phoneBook[100]; // Maximum of 100 contacts in phone book
    int numContacts = 0;    // Counter for number of contacts

    // User menu loop
    int choice;
    do {
        printf("Welcome to Your Personal Phone Book\n");
        printf("Please choose an option:\n");
        printf("1. Add a contact\n");
        printf("2. View all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");
        printf("Enter choice (1-5): ");
        scanf("%d", &choice);
        getchar();  // Clear input buffer

        switch (choice) {
            case 1:
                addContact(phoneBook, &numContacts);
                break;

            case 2:
                viewContacts(phoneBook, numContacts);
                break;

            case 3:
                searchContacts(phoneBook, numContacts);
                break;

            case 4:
                deleteContact(phoneBook, &numContacts);
                break;

            case 5:
                printf("Goodbye!");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a contact
void addContact(Contact phoneBook[], int *numContacts) {
    if (*numContacts >= 100) {
        printf("Phone book is full. Cannot add a contact.\n");
        return;
    }

    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, 50, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline character
    printf("Enter phone number: ");
    fgets(newContact.phoneNum, 15, stdin);
    newContact.phoneNum[strcspn(newContact.phoneNum, "\n")] = 0; // Remove newline character
    printf("Enter email: ");
    fgets(newContact.email, 50, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = 0; // Remove newline character

    phoneBook[*numContacts] = newContact;
    (*numContacts)++;
    printf("Contact added successfully!\n");
}

// Function to view all contacts
void viewContacts(Contact phoneBook[], int numContacts) {
    if (numContacts == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("All Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%d. Name: %s, Phone Number: %s, Email: %s\n", i+1,
                phoneBook[i].name, phoneBook[i].phoneNum, phoneBook[i].email);
    }
}

// Function to search for a contact
void searchContacts(Contact phoneBook[], int numContacts) {
    if (numContacts == 0) {
        printf("No contacts found.\n");
        return;
    }

    char searchTerm[50];
    printf("Enter the name or phone number to search for: ");
    fgets(searchTerm, 50, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline character

    printf("Search Results:\n");
    for (int i = 0; i < numContacts; i++) {
        if (strstr(phoneBook[i].name, searchTerm) != NULL || strstr(phoneBook[i].phoneNum, searchTerm) != NULL) {
            printf("%d. Name: %s, Phone Number: %s, Email: %s\n", i+1,
                    phoneBook[i].name, phoneBook[i].phoneNum, phoneBook[i].email);
        }
    }
}

// Function to delete a contact
void deleteContact(Contact phoneBook[], int *numContacts) {
    if (*numContacts == 0) {
        printf("No contacts found.\n");
        return;
    }

    int choice;
    printf("Enter the number of the contact to delete: ");
    scanf("%d", &choice);
    getchar();  // Clear input buffer

    if (choice < 1 || choice > *numContacts) {
        printf("Invalid contact number. Please try again.\n");
        return;
    }

    printf("Are you sure you want to delete contact %d? (y/n): ", choice);
    char confirm;
    scanf("%c", &confirm);
    getchar();  // Clear input buffer

    if (confirm == 'y') {
        for (int i = choice-1; i < *numContacts-1; i++) {
            phoneBook[i] = phoneBook[i+1];
        }
        (*numContacts)--;
        printf("Contact deleted successfully!\n");
    }
}