//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define FILE_NAME "contacts.txt"

// Struct to represent a contact
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

// Function to add a contact
void addContact() {
    Contact newContact;
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Enter name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; // Remove newline character

    printf("Enter phone number: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0'; // Remove newline character

    fwrite(&newContact, sizeof(Contact), 1, file);
    fclose(file);
    printf("Contact added successfully!\n");
}

// Function to view all contacts
void viewContacts() {
    Contact contact;
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\n--- Contacts ---\n");
    while (fread(&contact, sizeof(Contact), 1, file)) {
        printf("Name: %s, Phone: %s\n", contact.name, contact.phone);
    }
    fclose(file);
}

// Function to delete a contact
void deleteContact() {
    Contact contact;
    FILE *file = fopen(FILE_NAME, "rb");
    FILE *tempFile = fopen("temp.txt", "wb");
    if (file == NULL || tempFile == NULL) {
        perror("Error opening file");
        return;
    }

    char nameToDelete[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    fgets(nameToDelete, NAME_LENGTH, stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = '\0'; // Remove newline character

    int found = 0;
    while (fread(&contact, sizeof(Contact), 1, file)) {
        if (strcmp(contact.name, nameToDelete) == 0) {
            found = 1;
            printf("Deleted contact: Name: %s, Phone: %s\n", contact.name, contact.phone);
        } else {
            fwrite(&contact, sizeof(Contact), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
        remove("temp.txt");
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Contact Manager ---\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

// Main function
int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // To consume the newline character after scanf

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
                printf("Exiting the Contact Manager. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}