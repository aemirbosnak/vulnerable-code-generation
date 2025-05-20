//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: careful
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
void searchContact();

int main() {
    int choice;

    while (1) {
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
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addContact() {
    Contact newContact;
    FILE *file = fopen(FILE_NAME, "a"); // Open for appending

    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("Enter contact name: ");
    scanf(" %[^\n]", newContact.name);
    printf("Enter contact phone number: ");
    scanf(" %[^\n]", newContact.phone);

    fwrite(&newContact, sizeof(Contact), 1, file);
    printf("Contact added successfully!\n");

    fclose(file);
}

void viewContacts() {
    Contact contact;
    FILE *file = fopen(FILE_NAME, "r"); // Open for reading

    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("\n--- List of Contacts ---\n");
    while (fread(&contact, sizeof(Contact), 1, file)) {
        printf("Name: %s, Phone: %s\n", contact.name, contact.phone);
    }

    fclose(file);
}

void searchContact() {
    Contact contact;
    char searchName[MAX_NAME_LENGTH];
    int found = 0;

    FILE *file = fopen(FILE_NAME, "r"); // Open for reading

    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("Enter the name of the contact to search: ");
    scanf(" %[^\n]", searchName);

    while (fread(&contact, sizeof(Contact), 1, file)) {
        if (strcmp(contact.name, searchName) == 0) {
            printf("Contact found! Name: %s, Phone: %s\n", contact.name, contact.phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact %s not found!\n", searchName);
    }

    fclose(file);
}