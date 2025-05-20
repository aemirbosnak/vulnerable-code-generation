//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void addContact(FILE *file);
void listContacts(FILE *file);
void searchContact(FILE *file);
void deleteContact(FILE *file);
void displayMenu();
void clearBuffer();

int main() {
    FILE *file = fopen("contacts.dat", "a+b");
    if (!file) {
        fprintf(stderr, "Could not open file.\n");
        return 1;
    }

    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addContact(file);
                break;
            case 2:
                listContacts(file);
                break;
            case 3:
                searchContact(file);
                break;
            case 4:
                deleteContact(file);
                break;
            case 5:
                fclose(file);
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addContact(FILE *file) {
    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, MAX_NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline character

    printf("Enter address: ");
    fgets(newContact.address, MAX_ADDRESS_LENGTH, stdin);
    newContact.address[strcspn(newContact.address, "\n")] = 0;

    printf("Enter phone number: ");
    fgets(newContact.phone, MAX_PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0;

    fseek(file, 0, SEEK_END);
    fwrite(&newContact, sizeof(Contact), 1, file);
    printf("Contact added successfully!\n");
}

void listContacts(FILE *file) {
    Contact contact;
    rewind(file);
    printf("\n--- List of Contacts ---\n");
    while (fread(&contact, sizeof(Contact), 1, file)) {
        printf("Name: %s\n", contact.name);
        printf("Address: %s\n", contact.address);
        printf("Phone: %s\n", contact.phone);
        printf("----------------------\n");
    }
}

void searchContact(FILE *file) {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter the name to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline character
    
    Contact contact;
    rewind(file);
    int found = 0;
    while (fread(&contact, sizeof(Contact), 1, file)) {
        if (strcmp(contact.name, searchName) == 0) {
            printf("\n--- Contact Found ---\n");
            printf("Name: %s\n", contact.name);
            printf("Address: %s\n", contact.address);
            printf("Phone: %s\n", contact.phone);
            printf("----------------------\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No contact found with name '%s'.\n", searchName);
    }
}

void deleteContact(FILE *file) {
    char deleteName[MAX_NAME_LENGTH];
    printf("Enter the name to delete: ");
    fgets(deleteName, MAX_NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = 0; // Remove newline character

    FILE *tempFile = fopen("temp.dat", "w+b");
    if (!tempFile) {
        fprintf(stderr, "Could not open temporary file.\n");
        return;
    }

    Contact contact;
    rewind(file);
    int deleted = 0;
    while (fread(&contact, sizeof(Contact), 1, file)) {
        if (strcmp(contact.name, deleteName) != 0) {
            fwrite(&contact, sizeof(Contact), 1, tempFile);
        } else {
            deleted = 1;
            printf("Contact '%s' deleted successfully!\n", deleteName);
        }
    }
    
    fclose(file);
    fclose(tempFile);

    remove("contacts.dat"); // Remove original file
    rename("temp.dat", "contacts.dat"); // Rename temp file to original

    file = fopen("contacts.dat", "a+b"); // Re-open the now-updated file
    if (!file) {
        fprintf(stderr, "Could not open file.\n");
        exit(EXIT_FAILURE);
    }

    if (!deleted) {
        printf("No contact found with name '%s'.\n", deleteName);
    }
}

void displayMenu() {
    printf("\n--- Contact Management System ---\n");
    printf("1. Add Contact\n");
    printf("2. List Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}