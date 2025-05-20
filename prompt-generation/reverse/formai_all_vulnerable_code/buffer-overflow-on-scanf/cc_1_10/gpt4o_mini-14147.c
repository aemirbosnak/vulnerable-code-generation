//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50
#define FILENAME "contacts.txt"

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Contact;

void addContact();
void viewContacts();
void deleteContact();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=== Contact Management System ===\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
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
                deleteContact();
                break;
            case 4:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}

void addContact() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Contact contact;
    printf("Enter name: ");
    fgets(contact.name, NAME_LENGTH, stdin);
    contact.name[strcspn(contact.name, "\n")] = 0;  // Remove newline

    printf("Enter phone: ");
    fgets(contact.phone, PHONE_LENGTH, stdin);
    contact.phone[strcspn(contact.phone, "\n")] = 0;  // Remove newline

    printf("Enter email: ");
    fgets(contact.email, EMAIL_LENGTH, stdin);
    contact.email[strcspn(contact.email, "\n")] = 0;  // Remove newline

    fwrite(&contact, sizeof(Contact), 1, file);
    fclose(file);
    printf("Contact added successfully!\n");
}

void viewContacts() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Contact contact;
    printf("\n=== Contact List ===\n");
    while (fread(&contact, sizeof(Contact), 1, file) == 1) {
        printf("Name: %s, Phone: %s, Email: %s\n", contact.name, contact.phone, contact.email);
    }
    fclose(file);
}

void deleteContact() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Contact contacts[MAX_CONTACTS];
    int count = 0;
    while (fread(&contacts[count], sizeof(Contact), 1, file) == 1) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("No contacts available to delete.\n");
        return;
    }

    printf("\n=== Contacts Available for Deletion ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, contacts[i].name);
    }

    int deleteIndex;
    printf("Select the contact number to delete (1-%d): ", count);
    scanf("%d", &deleteIndex);
    clearBuffer();

    if (deleteIndex < 1 || deleteIndex > count) {
        printf("Invalid selection!\n");
        return;
    }

    // Move the selected contact to the end and reduce count
    for (int i = deleteIndex - 1; i < count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    count--;

    // Re-write the file
    file = fopen(FILENAME, "w");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    
    fwrite(contacts, sizeof(Contact), count, file);
    fclose(file);

    printf("Contact deleted successfully!\n");
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}