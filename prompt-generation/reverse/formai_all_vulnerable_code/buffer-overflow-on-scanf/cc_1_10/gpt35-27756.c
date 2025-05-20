//FormAI DATASET v1.0 Category: Phone Book ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

// Structure to hold contact information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

// Function prototypes
void addContact(Contact book[], int *numContacts);
void displayContacts(Contact book[], int numContacts);
void searchContacts(Contact book[], int numContacts, char searchTerm[]);
void saveToFile(Contact book[], int numContacts);
void loadFromFile(Contact book[], int *numContacts);

int main() {
    Contact phonebook[100]; // Maximum of 100 contacts
    int numContacts = 0; // Number of contacts in the phone book
    int choice; // User's menu choice
    char searchTerm[MAX_NAME_LENGTH]; // User's search term

    // Load contacts from file
    loadFromFile(phonebook, &numContacts);

    // Menu loop
    do {
        printf("\nC Phone Book Menu\n");
        printf("------------------\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contacts\n");
        printf("4. Save Contacts\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(phonebook, &numContacts);
                break;
            case 2:
                displayContacts(phonebook, numContacts);
                break;
            case 3:
                printf("Enter search term: ");
                scanf("%s", searchTerm);
                searchContacts(phonebook, numContacts, searchTerm);
                break;
            case 4:
                saveToFile(phonebook, numContacts);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Add a new contact to the phone book
void addContact(Contact book[], int *numContacts) {
    // Check if phone book is full
    if (*numContacts == 100) {
        printf("Phone book is full.\n");
        return;
    }

    // Get contact information from user
    Contact newContact;
    printf("\nEnter contact name: ");
    scanf("%s", newContact.name);
    printf("Enter contact phone number: ");
    scanf("%s", newContact.phone);

    // Add contact to phone book
    book[*numContacts] = newContact;
    (*numContacts)++;
    printf("Contact added.\n");
}

// Display all contacts in the phone book
void displayContacts(Contact book[], int numContacts) {
    printf("\nContacts\n");
    printf("------------------\n");

    if (numContacts == 0) {
        printf("Phone book is empty.\n");
    } else {
        for (int i = 0; i < numContacts; i++) {
            printf("%s\t%s\n", book[i].name, book[i].phone);
        }
    }
}

// Search for a contact in the phone book
void searchContacts(Contact book[], int numContacts, char searchTerm[]) {
    int numMatches = 0; // Number of contacts that match the search term

    // Search for matches and display results
    printf("\nSearch Results for '%s'\n", searchTerm);
    printf("------------------\n");
    for (int i = 0; i < numContacts; i++) {
        if (strstr(book[i].name, searchTerm) != NULL) {
            printf("%s\t%s\n", book[i].name, book[i].phone);
            numMatches++;
        }
    }

    // Display message if no matches were found
    if (numMatches == 0) {
        printf("No matches found.\n");
    }
}

// Save phone book to file
void saveToFile(Contact book[], int numContacts) {
    FILE *fp;
    fp = fopen("phonebook.txt", "w");

    // Write each contact to file
    for (int i = 0; i < numContacts; i++) {
        fprintf(fp, "%s,%s\n", book[i].name, book[i].phone);
    }

    fclose(fp);
    printf("Phone book saved.\n");
}

// Load phone book from file
void loadFromFile(Contact book[], int *numContacts) {
    FILE *fp;
    char buffer[MAX_NAME_LENGTH + MAX_PHONE_LENGTH + 1];
    char *name;
    char *phone;

    fp = fopen("phonebook.txt", "r");

    if (fp == NULL) {
        printf("Could not open phone book file.\n");
        return;
    }

    // Read each line from file and parse contact information
    while (fgets(buffer, MAX_NAME_LENGTH + MAX_PHONE_LENGTH + 1, fp) != NULL) {
        // Remove newline character from end of line
        buffer[strcspn(buffer, "\n")] = 0;

        name = strtok(buffer, ",");
        phone = strtok(NULL, ",");
        strcpy(book[*numContacts].name, name);
        strcpy(book[*numContacts].phone, phone);
        (*numContacts)++;
    }

    fclose(fp);
    printf("Phone book loaded.\n");
}