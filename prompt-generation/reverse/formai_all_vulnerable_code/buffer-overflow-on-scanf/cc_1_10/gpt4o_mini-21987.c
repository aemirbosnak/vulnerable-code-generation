//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50
#define FILENAME "contacts.dat"

// Structure to store contact information
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Contact;

// Function declarations
void addContact();
void viewContacts();
void searchContact();
void saveContacts(Contact contacts[], int count);
int loadContacts(Contact contacts[]);

// Main function
int main() {
    int choice;
    do {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}

// Function to add a new contact
void addContact() {
    Contact newContact;
    FILE *file = fopen(FILENAME, "ab");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    
    printf("Enter name: ");
    getchar(); // consume leftover newline
    fgets(newContact.name, NAME_LENGTH, stdin);
    strtok(newContact.name, "\n"); // remove newline character

    printf("Enter phone: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    strtok(newContact.phone, "\n");

    printf("Enter email: ");
    fgets(newContact.email, EMAIL_LENGTH, stdin);
    strtok(newContact.email, "\n");

    fwrite(&newContact, sizeof(Contact), 1, file);
    fclose(file);
    printf("Contact added successfully!\n");
}

// Function to view all contacts
void viewContacts() {
    Contact contacts[MAX_CONTACTS];
    int count = loadContacts(contacts);
    if (count == 0) {
        printf("No contacts found.\n");
        return;
    }
    
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Phone: %s, Email: %s\n", 
               i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

// Function to search for a contact by name
void searchContact() {
    Contact contacts[MAX_CONTACTS];
    int count = loadContacts(contacts);
    char searchName[NAME_LENGTH];
    
    if (count == 0) {
        printf("No contacts available to search.\n");
        return;
    }

    printf("Enter name to search: ");
    getchar(); // consume leftover newline
    fgets(searchName, NAME_LENGTH, stdin);
    strtok(searchName, "\n");

    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < count; i++) {
        if (strstr(contacts[i].name, searchName) != NULL) {
            printf("Name: %s, Phone: %s, Email: %s\n", 
                   contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
        }
    }
    if (!found) {
        printf("No contact found with the name \"%s\".\n", searchName);
    }
}

// Function to load contacts from the file
int loadContacts(Contact contacts[]) {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        return 0; // return 0 if file doesn't exist
    }
    
    int count = 0;
    while (fread(&contacts[count], sizeof(Contact), 1, file) == 1) {
        count++;
    }
    fclose(file);
    return count;
}