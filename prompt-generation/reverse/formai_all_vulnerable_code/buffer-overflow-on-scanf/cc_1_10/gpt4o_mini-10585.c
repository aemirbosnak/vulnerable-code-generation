//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define FILE_NAME "contacts.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

// Function to add contact
void add_contact() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("Unable to open file for appending.\n");
        return;
    }

    Contact contact;
    printf("Enter contact name: ");
    fgets(contact.name, MAX_NAME_LENGTH, stdin);
    contact.name[strcspn(contact.name, "\n")] = 0; // Remove newline character

    printf("Enter contact phone: ");
    fgets(contact.phone, MAX_PHONE_LENGTH, stdin);
    contact.phone[strcspn(contact.phone, "\n")] = 0; // Remove newline character

    fprintf(file, "%s,%s\n", contact.name, contact.phone);
    fclose(file);
    printf("Contact added successfully!\n");
}

// Function to display all contacts
void view_contacts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No contacts found.\n");
        return;
    }

    char line[100];
    printf("\n--- Contact List ---\n");
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, "\n");
        printf("Name: %s, Phone: %s\n", name, phone);
    }
    fclose(file);
}

// Function to delete a contact by name
void delete_contact() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No contacts found to delete.\n");
        return;
    }

    char name_to_delete[MAX_NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    fgets(name_to_delete, MAX_NAME_LENGTH, stdin);
    name_to_delete[strcspn(name_to_delete, "\n")] = 0;

    FILE *temp_file = fopen("temp.txt", "w");
    if (!temp_file) {
        printf("Unable to create temporary file.\n");
        fclose(file);
        return;
    }

    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        if (strcmp(name, name_to_delete) != 0) {
            fprintf(temp_file, "%s", line);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp_file);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("Contact deleted successfully!\n");
    } else {
        printf("No contact found with the name: %s\n", name_to_delete);
        remove("temp.txt");
    }
}

// Function to display menu
void display_menu() {
    printf("\n--- Contact Management System ---\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character left by scanf

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
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}