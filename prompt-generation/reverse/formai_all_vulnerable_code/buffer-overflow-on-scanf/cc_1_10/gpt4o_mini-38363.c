//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void add_contact(const char *filename);
void view_contacts(const char *filename);
void delete_contact(const char *filename);
void clear_input_buffer();

int main() {
    int choice;
    const char *filename = "contacts.txt";

    do {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer(); // Clear buffer to handle the newline character

        switch (choice) {
            case 1:
                add_contact(filename);
                break;
            case 2:
                view_contacts(filename);
                break;
            case 3:
                delete_contact(filename);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void add_contact(const char *filename) {
    Contact new_contact;
    FILE *file = fopen(filename, "a");

    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    printf("Enter name: ");
    fgets(new_contact.name, MAX_NAME_LENGTH, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(new_contact.phone, MAX_PHONE_LENGTH, stdin);
    new_contact.phone[strcspn(new_contact.phone, "\n")] = 0; // Remove newline

    // Write contact to file
    fprintf(file, "%s\n%s\n", new_contact.name, new_contact.phone);
    fclose(file);
    printf("Contact added successfully!\n");
}

void view_contacts(const char *filename) {
    FILE *file = fopen(filename, "r");
    Contact contact;

    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    printf("\n--- Contacts ---\n");
    while (fgets(contact.name, MAX_NAME_LENGTH, file)) {
        // Read the phone number associated with the name
        fgets(contact.phone, MAX_PHONE_LENGTH, file);
        printf("Name: %sPhone: %s", contact.name, contact.phone);
    }
    fclose(file);
}

void delete_contact(const char *filename) {
    FILE *file = fopen(filename, "r");
    FILE *temp_file = fopen("temp.txt", "w");
    Contact contact;
    char name_to_delete[MAX_NAME_LENGTH];

    if (file == NULL || temp_file == NULL) {
        perror("Could not open file");
        return;
    }

    printf("Enter the name of the contact to delete: ");
    fgets(name_to_delete, MAX_NAME_LENGTH, stdin);
    name_to_delete[strcspn(name_to_delete, "\n")] = 0; // Remove newline

    int found = 0;
    while (fgets(contact.name, MAX_NAME_LENGTH, file)) {
        fgets(contact.phone, MAX_PHONE_LENGTH, file);
        if (strcmp(contact.name, name_to_delete) != 0) {
            fprintf(temp_file, "%s%s", contact.name, contact.phone);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp_file);

    // Replace the old file with the new one if a contact was found and deleted
    if (found) {
        remove(filename);
        rename("temp.txt", filename);
        printf("Contact deleted successfully!\n");
    } else {
        remove("temp.txt");
        printf("Contact not found.\n");
    }
}

void clear_input_buffer() {
    while (getchar() != '\n'); // Clear the input buffer
}