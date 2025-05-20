//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_CONTACTS 100
#define FILE_NAME "contacts.txt"

// Structure to hold contact details
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

// Function declarations
void addContact();
void viewContacts();
void deleteContact();
void displayMenu();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Contact Management System ---\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Exit\n");
}

void addContact() {
    Contact newContact;
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Could not open file for writing");
        return;
    }

    printf("Enter name: ");
    fgets(newContact.name, MAX_NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0';  // Remove newline character

    printf("Enter phone number: ");
    fgets(newContact.phone, MAX_PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';  // Remove newline character

    fwrite(&newContact, sizeof(Contact), 1, file);
    fclose(file);
    printf("Contact added successfully!\n");
}

void viewContacts() {
    Contact contact;
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Could not open file for reading");
        return;
    }

    printf("\n--- Contacts ---\n");
    printf("%-30s%-15s\n", "Name", "Phone Number");
    printf("------------------------------------------\n");
    while (fread(&contact, sizeof(Contact), 1, file)) {
        printf("%-30s%-15s\n", contact.name, contact.phone);
    }
    fclose(file);
}

void deleteContact() {
    Contact contacts[MAX_CONTACTS];
    Contact contactToDelete;
    int count = 0, found = 0;
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Could not open file for reading");
        return;
    }

    while (fread(&contacts[count], sizeof(Contact), 1, file)) {
        count++;
    }
    fclose(file);
    
    if (count == 0) {
        printf("No contacts available to delete.\n");
        return;
    }

    printf("Enter name of contact to delete: ");
    fgets(contactToDelete.name, MAX_NAME_LENGTH, stdin);
    contactToDelete.name[strcspn(contactToDelete.name, "\n")] = '\0';  // Remove newline character

    // Create a new file to write remaining contacts
    file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Could not open file for writing");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, contactToDelete.name) == 0) {
            found = 1;  // Mark that the contact has been found
            continue;
        }
        fwrite(&contacts[i], sizeof(Contact), 1, file);
    }
    fclose(file);

    if (found) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found.\n");
    }
}