//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define FILENAME "contacts.txt"

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

// Function prototypes
void addContact();
void viewContacts();
void deleteContact();
void clearBuffer();

int main() {
    int choice;

    do {
        printf("\n----- Contact Management System -----\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        
        scanf("%d", &choice);
        clearBuffer(); // Clear the newline character from the input buffer

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
                printf("Exiting the program. Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addContact() {
    Contact newContact;
    FILE *file = fopen(FILENAME, "a");

    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("Enter name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline
    printf("Enter phone number: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Remove newline

    fprintf(file, "%s,%s\n", newContact.name, newContact.phone);
    printf("Contact added successfully!\n");

    fclose(file);
}

void viewContacts() {
    FILE *file = fopen(FILENAME, "r");
    char line[NAME_LENGTH + PHONE_LENGTH + 2];

    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("\n----- Contact List -----\n");
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, ",");
        printf("Name: %s, Phone: %s", name, phone);
    }

    fclose(file);
}

void deleteContact() {
    char nameToDelete[NAME_LENGTH];
    Contact contacts[MAX_CONTACTS];
    int count = 0;

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    while (fgets(contacts[count].name, sizeof(contacts[count].name), file)) {
        char *phone = strtok(contacts[count].name, ",");
        strcpy(contacts[count].phone, phone != NULL ? phone : "");
        contacts[count].name[strcspn(contacts[count].name, "\n")] = 0; // Remove newline
        count++;
    }
    fclose(file);

    printf("Enter the name of the contact to delete: ");
    fgets(nameToDelete, NAME_LENGTH, stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = 0; // Remove newline

    // Create a new file to write the remaining contacts
    file = fopen(FILENAME, "w");
    if (file == NULL) {
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
        printf("Contact '%s' deleted successfully!\n", nameToDelete);
    } else {
        printf("Contact '%s' not found.\n", nameToDelete);
    }
}

void clearBuffer() {
    while (getchar() != '\n') {}
}