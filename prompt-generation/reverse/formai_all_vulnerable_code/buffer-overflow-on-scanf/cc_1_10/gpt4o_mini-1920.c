//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "contacts.txt"
#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

// Function prototypes
void addContact();
void viewContacts();
void deleteContact();
void clearBuffer(); // Function to clear the input buffer

int main() {
    int choice;

    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear buffer to handle new line from the scanf

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
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addContact() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Contact contact;
    printf("Enter Name: ");
    fgets(contact.name, MAX_NAME_LENGTH, stdin);
    contact.name[strcspn(contact.name, "\n")] = 0; // Remove newline character

    printf("Enter Phone: ");
    fgets(contact.phone, MAX_PHONE_LENGTH, stdin);
    contact.phone[strcspn(contact.phone, "\n")] = 0; // Remove newline character

    fprintf(file, "%s,%s\n", contact.name, contact.phone);
    fclose(file);
    printf("Contact added successfully!\n");
}

void viewContacts() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char buffer[256];
    printf("\nContacts:\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        char *name = strtok(buffer, ",");
        char *phone = strtok(NULL, ",");
        printf("Name: %s, Phone: %s", name, phone);
    }
    fclose(file);
}

void deleteContact() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char buffer[256];
    Contact contacts[100];
    int count = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        char *name = strtok(buffer, ",");
        char *phone = strtok(NULL, ",");
        strncpy(contacts[count].name, name, MAX_NAME_LENGTH);
        strncpy(contacts[count].phone, phone, MAX_PHONE_LENGTH);
        count++;
    }
    fclose(file);

    printf("Enter the name of the contact to delete: ");
    char nameToDelete[MAX_NAME_LENGTH];
    fgets(nameToDelete, MAX_NAME_LENGTH, stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = 0; // Remove newline character

    // Write remaining contacts to a new file
    file = fopen(FILENAME, "w");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    int deleted = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, nameToDelete) != 0) {
            fprintf(file, "%s,%s\n", contacts[i].name, contacts[i].phone);
        } else {
            deleted = 1;
        }
    }
    fclose(file);

    if (deleted) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found.\n");
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clears the input buffer
}