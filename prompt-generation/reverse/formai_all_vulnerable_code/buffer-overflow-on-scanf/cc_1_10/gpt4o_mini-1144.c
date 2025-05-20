//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define FILE_NAME "contacts.txt"

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void add_contact() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    Contact contact;
    printf("Enter name: ");
    fgets(contact.name, NAME_LENGTH, stdin);
    contact.name[strcspn(contact.name, "\n")] = 0; // Remove newline character

    printf("Enter phone number: ");
    fgets(contact.phone, PHONE_LENGTH, stdin);
    contact.phone[strcspn(contact.phone, "\n")] = 0; // Remove newline character

    fprintf(file, "%s;%s\n", contact.name, contact.phone);
    
    fclose(file);
    printf("Contact saved successfully!\n");
}

void view_contacts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No contacts found.\n");
        return;
    }

    char line[100];
    printf("Contacts:\n");
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ";");
        char *phone = strtok(NULL, ";");
        if (phone != NULL) {
            printf("Name: %s, Phone: %s\n", name, phone);
        }
    }

    fclose(file);
}

void delete_contact() {
    FILE *file = fopen(FILE_NAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (!file || !tempFile) {
        printf("Error opening file.\n");
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char *contactName = strtok(line, ";");
        if (strcmp(contactName, name) != 0) {
            fputs(line, tempFile);
        } else {
            found = 1; // If found, do not write to tempFile
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}