//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
#define FILENAME "phonebook.txt"

typedef struct Contact {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} Contact;

void addContact();
void viewContacts();
void deleteContact();
void searchContact();
void clearBuffer();

int main() {
    int choice;
    while (1) {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
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
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting Phone Book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addContact() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, MAX_NAME_LEN, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; // Remove newline

    printf("Enter phone: ");
    fgets(newContact.phone, MAX_PHONE_LEN, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0'; // Remove newline

    fprintf(file, "%s,%s\n", newContact.name, newContact.phone);
    fclose(file);
    printf("Contact added successfully!\n");
}

void viewContacts() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    Contact contact;
    printf("\n--- Contacts ---\n");
    while (fgets(contact.name, MAX_NAME_LEN, file)) {
        // Read until end of file
        char *commaPosition = strchr(contact.name, ',');
        if (commaPosition) {
            *commaPosition = '\0'; // Replace the comma with NULL character
            strcpy(contact.phone, commaPosition + 1);
            contact.phone[strcspn(contact.phone, "\n")] = '\0'; // Remove newline
            printf("Name: %s, Phone: %s\n", contact.name, contact.phone);
        }
    }
    fclose(file);
}

void deleteContact() {
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (!file || !tempFile) {
        perror("Failed to open file");
        return;
    }
    char nameToDelete[MAX_NAME_LEN];
    printf("Enter the name of the contact to delete: ");
    fgets(nameToDelete, MAX_NAME_LEN, stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = '\0'; // Remove newline

    Contact contact;
    int found = 0;
    while (fgets(contact.name, MAX_NAME_LEN, file)) {
        char *commaPosition = strchr(contact.name, ',');
        if (commaPosition) {
            *commaPosition = '\0'; // Replace the comma with NULL character
            strcpy(contact.phone, commaPosition + 1);
            contact.phone[strcspn(contact.phone, "\n")] = '\0'; // Remove newline
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
        printf("Contact '%s' deleted successfully!\n", nameToDelete);
    } else {
        printf("Contact '%s' not found!\n", nameToDelete);
    }
}

void searchContact() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    char searchName[MAX_NAME_LEN];
    printf("Enter name to search: ");
    fgets(searchName, MAX_NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline

    Contact contact;
    int found = 0;
    while (fgets(contact.name, MAX_NAME_LEN, file)) {
        char *commaPosition = strchr(contact.name, ',');
        if (commaPosition) {
            *commaPosition = '\0'; // Replace comma with NULL character
            strcpy(contact.phone, commaPosition + 1);
            contact.phone[strcspn(contact.phone, "\n")] = '\0'; // Remove newline
            if (strcasecmp(contact.name, searchName) == 0) {
                printf("Found Contact - Name: %s, Phone: %s\n", contact.name, contact.phone);
                found = 1;
                break;
            }
        }
    }
    fclose(file);
    if (!found) {
        printf("Contact '%s' not found!\n", searchName);
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the buffer
}