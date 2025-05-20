//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_CONTACTS 100
#define FILE_NAME "contacts.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

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
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n---- Contact Management System ----\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Exit\n");
    printf("-----------------------------------\n");
}

void addContact() {
    Contact newContact;
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]%*c", newContact.name);  // Read string with spaces
    printf("Enter phone number: ");
    scanf(" %[^\n]%*c", newContact.phone);

    fprintf(file, "%s,%s\n", newContact.name, newContact.phone);
    fclose(file);
    
    printf("Contact added successfully!\n");
}

void viewContacts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No contacts found.\n");
        return;
    }

    Contact contact;
    printf("\n---- List of Contacts ----\n");
    while (fscanf(file, "%[^,],%[^\n]\n", contact.name, contact.phone) != EOF) {
        printf("Name: %s, Phone: %s\n", contact.name, contact.phone);
    }
    fclose(file);
}

void deleteContact() {
    char nameToDelete[MAX_NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]%*c", nameToDelete);
    
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No contacts found.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        fclose(file);
        printf("Could not open temporary file for writing.\n");
        return;
    }

    Contact contact;
    int found = 0;
    while (fscanf(file, "%[^,],%[^\n]\n", contact.name, contact.phone) != EOF) {
        if (strcmp(contact.name, nameToDelete) != 0) {
            fprintf(tempFile, "%s,%s\n", contact.name, contact.phone);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    
    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("Contact deleted successfully!\n");
    } else {
        remove("temp.txt");
        printf("Contact with name '%s' not found.\n", nameToDelete);
    }
}