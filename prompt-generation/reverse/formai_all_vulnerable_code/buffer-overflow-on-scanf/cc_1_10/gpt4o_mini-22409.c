//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_ENTRIES 100

// Structure to hold contact information
typedef struct Contact {
    char name[50];
    char phone[15];
    char email[50];
} Contact;

// Function prototypes
void displayMenu();
void addContact(FILE *file);
void viewContacts(FILE *file);
void searchContact(FILE *file);
void deleteContact(FILE *file);
void clearBuffer();

int main() {
    FILE *file;
    file = fopen("contacts.txt", "a+"); // Open for appending and reading
    if (file == NULL) {
        fprintf(stderr, "Could not open file for operations.\n");
        return 1;
    }

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear input buffer

        switch (choice) {
            case 1:
                addContact(file);
                break;
            case 2:
                viewContacts(file);
                break;
            case 3:
                searchContact(file);
                break;
            case 4:
                deleteContact(file);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    fclose(file);
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nContact Management System\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

// Function to add a contact
void addContact(FILE *file) {
    Contact newContact;
    
    printf("Enter name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    strtok(newContact.name, "\n"); // Remove newline character

    printf("Enter phone: ");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    strtok(newContact.phone, "\n");

    printf("Enter email: ");
    fgets(newContact.email, sizeof(newContact.email), stdin);
    strtok(newContact.email, "\n");

    fprintf(file, "%s;%s;%s\n", newContact.name, newContact.phone, newContact.email);
    printf("Contact added successfully!\n");
}

// Function to view all contacts
void viewContacts(FILE *file) {
    rewind(file); // Go to the beginning of the file

    char line[MAX_LINE_LENGTH];
    printf("\nContacts List:\n");
    printf("------------------------------------------------------\n");
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ";");
        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, ";");
        }
        printf("\n");
    }
    printf("------------------------------------------------------\n");
}

// Function to search for a contact
void searchContact(FILE *file) {
    rewind(file);
    char nameToSearch[50];
    int found = 0;

    printf("Enter the name to search: ");
    fgets(nameToSearch, sizeof(nameToSearch), stdin);
    strtok(nameToSearch, "\n"); // Remove newline character

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, nameToSearch) != NULL) {
            printf("Contact found: %s", line);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact
void deleteContact(FILE *file) {
    FILE *tempFile;
    tempFile = fopen("temp.txt", "w+");
    if (tempFile == NULL) {
        fprintf(stderr, "Could not open temporary file for writing.\n");
        return;
    }

    rewind(file);
    char nameToDelete[50];
    int found = 0;

    printf("Enter the name of the contact to delete: ");
    fgets(nameToDelete, sizeof(nameToDelete), stdin);
    strtok(nameToDelete, "\n"); // Remove newline character

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, nameToDelete) == NULL) {
            fputs(line, tempFile); // Write to temp file if not the contact to delete
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    remove("contacts.txt"); // Remove the original file
    rename("temp.txt", "contacts.txt"); // Rename temp file to original file

    if (found) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found for deletion.\n");
    }

    file = fopen("contacts.txt", "a+"); // Reopen file
}

// Function to clear the buffer
void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer until newline
}