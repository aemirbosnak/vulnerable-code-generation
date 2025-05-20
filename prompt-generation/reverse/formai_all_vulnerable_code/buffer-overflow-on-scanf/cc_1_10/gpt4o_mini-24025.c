//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

void addContact(const char *filename);
void displayContacts(const char *filename);
void searchContact(const char *filename);
void clearBuffer();

int main() {
    const char *filename = "contacts.dat";
    int choice;

    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addContact(filename);
                break;
            case 2:
                displayContacts(filename);
                break;
            case 3:
                searchContact(filename);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addContact(const char *filename) {
    FILE *file = fopen(filename, "ab");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, MAX_NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline

    printf("Enter phone: ");
    fgets(newContact.phone, MAX_PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Remove newline

    printf("Enter email: ");
    fgets(newContact.email, MAX_EMAIL_LENGTH, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = 0; // Remove newline

    fwrite(&newContact, sizeof(Contact), 1, file);
    fclose(file);
    printf("Contact added successfully!\n");
}

void displayContacts(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Contact contact;
    printf("\nList of Contacts:\n");
    printf("---------------------------------------------------\n");
    while (fread(&contact, sizeof(Contact), 1, file)) {
        printf("Name: %s\n", contact.name);
        printf("Phone: %s\n", contact.phone);
        printf("Email: %s\n", contact.email);
        printf("---------------------------------------------------\n");
    }
    fclose(file);
}

void searchContact(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter the name to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    Contact contact;
    int found = 0;

    while (fread(&contact, sizeof(Contact), 1, file)) {
        if (strcmp(contact.name, searchName) == 0) {
            printf("Contact Found:\n");
            printf("Name: %s\n", contact.name);
            printf("Phone: %s\n", contact.phone);
            printf("Email: %s\n", contact.email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }

    fclose(file);
}

void clearBuffer() {
    while (getchar() != '\n');  // Clear input buffer
}