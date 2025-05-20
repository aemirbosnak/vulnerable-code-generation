//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_FILE_LENGTH 256
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[15];
    char email[MAX_NAME_LENGTH];
} Contact;

void displayMenu();
void addContact();
void listContacts();
void saveContactsToFile();
void loadContactsFromFile();
int getContactIndex(const char *name);

// Global contacts array and count
Contact contacts[MAX_CONTACTS];
int contactCount = 0;

int main() {
    loadContactsFromFile();
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline from buffer

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                listContacts();
                break;
            case 3:
                saveContactsToFile();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n=== Contact Management System ===\n");
    printf("1. Add Contact\n");
    printf("2. List Contacts\n");
    printf("3. Save Contacts to File\n");
    printf("0. Exit\n");
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }

    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, MAX_NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; // Remove newline

    printf("Enter phone number: ");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0'; // Remove newline

    printf("Enter email: ");
    fgets(newContact.email, MAX_NAME_LENGTH, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0'; // Remove newline

    contacts[contactCount++] = newContact;
    printf("Contact added successfully!\n");
}

void listContacts() {
    if (contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\n=== List of Contacts ===\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s, Phone: %s, Email: %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

void saveContactsToFile() {
    FILE *file = fopen("contacts.txt", "w");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    for (int i = 0; i < contactCount; i++) {
        fprintf(file, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    fclose(file);
    printf("Contacts saved to contacts.txt successfully!\n");
}

void loadContactsFromFile() {
    FILE *file = fopen("contacts.txt", "r");
    if (!file) {
        printf("No existing contact file found, starting fresh.\n");
        return;
    }

    while (!feof(file) && contactCount < MAX_CONTACTS) {
        Contact contact;
        char line[256];
        
        if (fgets(line, sizeof(line), file) != NULL) {
            char *token = strtok(line, ",");
            if (token) strcpy(contact.name, token);
            token = strtok(NULL, ",");
            if (token) strcpy(contact.phone, token);
            token = strtok(NULL, ",");
            if (token) strcpy(contact.email, token);
            contacts[contactCount++] = contact;
        }
    }

    fclose(file);
    printf("Contacts loaded from file successfully!\n");
}