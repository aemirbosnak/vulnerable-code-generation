//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void addContact(const char *filename);
void displayContacts(const char *filename);
void searchContact(const char *filename);
void deleteContact(const char *filename);
void clearInputBuffer();

int main() {
    int choice;
    const char *filename = "contacts.dat";

    while (1) {
        printf("\n=== Contact Management System ===\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        clearInputBuffer();

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
                deleteContact(filename);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void addContact(const char *filename) {
    FILE *file = fopen(filename, "ab");
    if (!file) {
        perror("Could not open file");
        return;
    }

    Contact contact;
    printf("Enter name: ");
    fgets(contact.name, MAX_NAME_LENGTH, stdin);
    contact.name[strcspn(contact.name, "\n")] = 0; // Remove newline character
    printf("Enter phone number: ");
    fgets(contact.phone, MAX_PHONE_LENGTH, stdin);
    contact.phone[strcspn(contact.phone, "\n")] = 0; // Remove newline character

    fwrite(&contact, sizeof(Contact), 1, file);
    printf("Contact added successfully!\n");
    fclose(file);
}

void displayContacts(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return;
    }

    Contact contact;
    printf("\n=== Contact List ===\n");
    while (fread(&contact, sizeof(Contact), 1, file)) {
        printf("Name: %s, Phone: %s\n", contact.name, contact.phone);
    }
    fclose(file);
}

void searchContact(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline character

    Contact contact;
    int found = 0;
    while (fread(&contact, sizeof(Contact), 1, file)) {
        if (strcmp(contact.name, searchName) == 0) {
            printf("Found Contact - Name: %s, Phone: %s\n", contact.name, contact.phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
    fclose(file);
}

void deleteContact(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return;
    }

    Contact contacts[MAX_RECORDS];
    int count = 0;

    while (fread(&contacts[count], sizeof(Contact), 1, file) && count < MAX_RECORDS) {
        count++;
    }
    fclose(file);

    char deleteName[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(deleteName, MAX_NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = 0; // Remove newline character

    file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file");
        return;
    }

    int deleted = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, deleteName) == 0) {
            deleted = 1;
            printf("Deleted Contact - Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            continue;
        }
        fwrite(&contacts[i], sizeof(Contact), 1, file);
    }
    if (!deleted) {
        printf("Contact not found for deletion.\n");
    }
    fclose(file);
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}