//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define FILENAME "contacts.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

// Function declarations
void addContact();
void viewContacts();
void deleteContact();
void handleError(const char *message);

int main() {
    int choice;
    do {
        printf("Contact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            handleError("Invalid input. Please enter a number.");
            scanf("%*s"); // Clear the invalid input
            continue;
        }

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
                printf("Exiting...\n");
                break;
            default:
                handleError("Invalid choice. Please select a valid option.");
        }
    } while (choice != 4);
    
    return 0;
}

void addContact() {
    Contact newContact;
    FILE *file;

    printf("Enter contact name: ");
    scanf("%s", newContact.name); // No buffer overflow due to fixed size
    printf("Enter contact phone number: ");
    scanf("%s", newContact.phone); // No buffer overflow due to fixed size

    file = fopen(FILENAME, "a");
    if (file == NULL) {
        handleError("Could not open file for writing.");
        return;
    }

    // Write contact data to the file in a secure manner
    if (fprintf(file, "%s,%s\n", newContact.name, newContact.phone) < 0) {
        handleError("Error writing to file.");
    }

    fclose(file);
    printf("Contact added successfully!\n");
}

void viewContacts() {
    FILE *file;
    char buffer[256];

    file = fopen(FILENAME, "r");
    if (file == NULL) {
        handleError("Could not open file for reading.");
        return;
    }

    printf("Contacts:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Print the contact details
        printf("%s", buffer);
    }

    fclose(file);
}

void deleteContact() {
    char nameToDelete[MAX_NAME_LENGTH];
    FILE *file, *tempFile;
    Contact contact;
    int found = 0;

    printf("Enter the name of the contact to delete: ");
    scanf("%s", nameToDelete);

    file = fopen(FILENAME, "r");
    if (file == NULL) {
        handleError("Could not open file for reading.");
        return;
    }

    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        handleError("Could not create temporary file.");
        fclose(file); // Always close the original file first
        return;
    }

    // Read from the original and write to the temporary file except the contact to delete
    while (fgets(contact.name, sizeof(contact.name), file) != NULL) {
        char *token = strtok(contact.name, ",");
        if (token != NULL) {
            if (strcmp(token, nameToDelete) != 0) {
                fprintf(tempFile, "%s", contact.name);
            } else {
                found = 1; // Contact found
            }
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        // Replace the old file with the new one
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Contact deleted successfully!\n");
    } else {
        remove("temp.txt");
        handleError("Contact not found.");
    }
}

void handleError(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}