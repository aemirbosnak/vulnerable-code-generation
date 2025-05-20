//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define FILENAME "address_book.txt"

// Structure to hold contact information
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

// Function prototypes
void add_contact();
void delete_contact();
void view_contacts();
void search_contact();
void clear_buffer();

int main() {
    int choice;

    while (1) {
        printf("\nAddress Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. View Contacts\n");
        printf("4. Search Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                delete_contact();
                break;
            case 3:
                view_contacts();
                break;
            case 4:
                search_contact();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void add_contact() {
    Contact new_contact;
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Enter name: ");
    fgets(new_contact.name, NAME_LENGTH, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0; // Remove newline character

    printf("Enter phone number: ");
    fgets(new_contact.phone, PHONE_LENGTH, stdin);
    new_contact.phone[strcspn(new_contact.phone, "\n")] = 0; // Remove newline character

    fprintf(file, "%s,%s\n", new_contact.name, new_contact.phone);
    fclose(file);

    printf("Contact added successfully!\n");
}

void delete_contact() {
    char name[NAME_LENGTH];
    FILE *file = fopen(FILENAME, "r");
    FILE *temp_file = fopen("temp.txt", "w");
    Contact contact;
    int found = 0;

    if (file == NULL || temp_file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Enter name of the contact to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    while (fgets(contact.name, NAME_LENGTH, file) != NULL) {
        strtok(contact.name, ",");
        fgets(contact.phone, PHONE_LENGTH, file);

        if (strcmp(contact.name, name) != 0) {
            fprintf(temp_file, "%s,%s", contact.name, contact.phone);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp_file);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

void view_contacts() {
    FILE *file = fopen(FILENAME, "r");
    Contact contact;

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\nContacts:\n");
    while (fgets(contact.name, NAME_LENGTH, file) != NULL) {
        strtok(contact.name, ",");
        fgets(contact.phone, PHONE_LENGTH, file);
        printf("Name: %s, Phone: %s", contact.name, contact.phone);
    }

    fclose(file);
}

void search_contact() {
    char name[NAME_LENGTH];
    FILE *file = fopen(FILENAME, "r");
    Contact contact;
    int found = 0;

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Enter name of the contact to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    while (fgets(contact.name, NAME_LENGTH, file) != NULL) {
        strtok(contact.name, ",");
        fgets(contact.phone, PHONE_LENGTH, file);
        if (strcmp(contact.name, name) == 0) {
            printf("Contact found! Name: %s, Phone: %s", contact.name, contact.phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }

    fclose(file);
}

void clear_buffer() {
    while (getchar() != '\n'); // Clear input buffer
}