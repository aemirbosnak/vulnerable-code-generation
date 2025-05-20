//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15
#define FILENAME "contacts.txt"

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

void addContact();
void viewContacts();
void deleteContact();
void clearInputBuffer();

int main() {
    int choice;
    
    while (1) {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear newline character from input buffer

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
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addContact() {
    Contact newContact;
    FILE *file;

    printf("Enter Name: ");
    fgets(newContact.name, NAME_LEN, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline character

    printf("Enter Phone: ");
    fgets(newContact.phone, PHONE_LEN, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Remove newline character

    file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Unable to open file for writing");
        return;
    }

    fprintf(file, "%s,%s\n", newContact.name, newContact.phone);
    fclose(file);
    
    printf("Contact added successfully!\n");
}

void viewContacts() {
    Contact contact;
    FILE *file;
    
    file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    printf("\n--- List of Contacts ---\n");
    while (fgets(contact.name, NAME_LEN, file)) {
        if (fgets(contact.phone, PHONE_LEN, file) != NULL) {
            contact.name[strcspn(contact.name, "\n")] = 0; // Remove newline character
            contact.phone[strcspn(contact.phone, "\n")] = 0; // Remove newline character
            printf("Name: %s, Phone: %s\n", contact.name, contact.phone);
        }
    }
    
    fclose(file);
}

void deleteContact() {
    Contact contact;
    FILE *file, *tempFile;
    char nameToDelete[NAME_LEN];
    int found = 0;

    printf("Enter the name of the contact to delete: ");
    fgets(nameToDelete, NAME_LEN, stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = 0; // Remove newline character

    file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Unable to open temporary file");
        fclose(file);
        return;
    }

    while (fgets(contact.name, NAME_LEN, file)) {
        if (fgets(contact.phone, PHONE_LEN, file) != NULL) {
            contact.name[strcspn(contact.name, "\n")] = 0; // Remove newline character
            contact.phone[strcspn(contact.phone, "\n")] = 0; // Remove newline character
            
            if (strcmp(contact.name, nameToDelete) != 0) {
                fprintf(tempFile, "%s,%s\n", contact.name, contact.phone);
            } else {
                found = 1;
            }
        }
    }

    fclose(file);
    fclose(tempFile);
    
    remove(FILENAME);
    rename("temp.txt", FILENAME);
    
    if (found) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found.\n");
    }
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}