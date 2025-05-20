//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define FILE_NAME "contacts.txt"

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

// Function declarations
void addContact();
void viewContacts();
void deleteContact();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        clearBuffer();

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
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}

void addContact() {
    Contact newContact;
    FILE *file;

    printf("Enter name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0;  // Remove newline character

    printf("Enter phone number: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0;  // Remove newline character

    file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Could not open file to add contact.\n");
        return;
    }
    fprintf(file, "%s,%s\n", newContact.name, newContact.phone);
    fclose(file);

    printf("Contact added successfully!\n");
}

void viewContacts() {
    FILE *file;
    char line[100];
    
    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Could not open file to view contacts.\n");
        return;
    }

    printf("\n--- List of Contacts ---\n");
    while (fgets(line, sizeof(line), file)) {
        char name[NAME_LENGTH];
        char phone[PHONE_LENGTH];
        sscanf(line, "%[^,],%[^,\n]", name, phone);
        printf("Name: %s, Phone: %s\n", name, phone);
    }
    fclose(file);
}

void deleteContact() {
    char nameToDelete[NAME_LENGTH];
    FILE *file, *tempFile;
    Contact contact;
    int found = 0;

    printf("Enter the name of the contact to delete: ");
    fgets(nameToDelete, NAME_LENGTH, stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = 0;  // Remove newline character

    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Could not open file to delete contact.\n");
        return;
    }

    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Could not open temporary file.\n");
        fclose(file);
        return;
    }

    while (fgets(contact.name, sizeof(contact.name), file)) {
        char phone[PHONE_LENGTH];
        sscanf(contact.name, "%[^,],%[^,\n]", contact.name, phone);
        if (strcmp(contact.name, nameToDelete) != 0) {
            fprintf(tempFile, "%s,%s\n", contact.name, phone);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found.\n");
    }
}

void clearBuffer() {
    while (getchar() != '\n');  // Clear the input buffer
}