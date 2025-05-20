//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 100
#define PHONE_LEN 15
#define FILE_NAME "contacts.txt"

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

void add_contact();
void view_contacts();
void delete_contact();
void clear_buffer();

void clear_buffer() {
    // Clearing input buffer
    while (getchar() != '\n');
}

void add_contact() {
    Contact contact;
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Unable to open file for writing");
        return;
    }

    printf("Enter contact name: ");
    fgets(contact.name, NAME_LEN, stdin);
    contact.name[strcspn(contact.name, "\n")] = 0; // Remove newline
    printf("Enter contact phone: ");
    fgets(contact.phone, PHONE_LEN, stdin);
    contact.phone[strcspn(contact.phone, "\n")] = 0; // Remove newline

    fwrite(&contact, sizeof(Contact), 1, file);
    fclose(file);
    printf("Contact added successfully!\n");
}

void view_contacts() {
    Contact contact;
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    printf("\nContacts List:\n");
    printf("==================================\n");
    while (fread(&contact, sizeof(Contact), 1, file)) {
        printf("Name: %s, Phone: %s\n", contact.name, contact.phone);
    }
    fclose(file);
    printf("==================================\n");
}

void delete_contact() {
    char name_to_delete[NAME_LEN];
    Contact contact;
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp_file = fopen("temp.txt", "w");
    if (file == NULL || temp_file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("Enter the name of the contact to delete: ");
    fgets(name_to_delete, NAME_LEN, stdin);
    name_to_delete[strcspn(name_to_delete, "\n")] = 0; // Remove newline

    int found = 0;
    while (fread(&contact, sizeof(Contact), 1, file)) {
        if (strcmp(contact.name, name_to_delete) != 0) {
            fwrite(&contact, sizeof(Contact), 1, temp_file);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp_file);
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
        printf("Select an option: ");
        scanf("%d", &choice);
        clear_buffer(); // Clear input buffer

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
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}