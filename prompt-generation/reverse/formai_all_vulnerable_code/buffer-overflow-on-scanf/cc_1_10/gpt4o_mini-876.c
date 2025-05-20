//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: invasive
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

void add_contact();
void view_contacts();
void delete_contact();
void clear_line_buffer();

int main() {
    int choice;

    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        clear_line_buffer();  // Clear the buffer after integer input
        
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
                exit(0);
            default:
                printf("Invalid option! Try again.\n");
        }
    }

    return 0;
}

void add_contact() {
    Contact new_contact;
    FILE *file = fopen(FILE_NAME, "a");
    
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    printf("Enter name: ");
    fgets(new_contact.name, NAME_LENGTH, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(new_contact.phone, PHONE_LENGTH, stdin);
    new_contact.phone[strcspn(new_contact.phone, "\n")] = 0; // Remove newline

    fprintf(file, "%s\n%s\n", new_contact.name, new_contact.phone);
    fclose(file);
    printf("Contact added successfully!\n");
}

void view_contacts() {
    Contact contact;
    FILE *file = fopen(FILE_NAME, "r");

    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    printf("\nContacts:\n");
    while (fgets(contact.name, NAME_LENGTH, file)) {
        fgets(contact.phone, PHONE_LENGTH, file);
        contact.name[strcspn(contact.name, "\n")] = 0; // Remove newline
        contact.phone[strcspn(contact.phone, "\n")] = 0; // Remove newline
        printf("Name: %s, Phone: %s\n", contact.name, contact.phone);
    }
    
    fclose(file);
}

void delete_contact() {
    char name[NAME_LENGTH];
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp_file = fopen("temp.txt", "w");
    Contact contact;
    int found = 0;

    if (file == NULL || temp_file == NULL) {
        perror("Failed to open file");
        return;
    }

    printf("Enter name of contact to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    while (fgets(contact.name, NAME_LENGTH, file)) {
        fgets(contact.phone, PHONE_LENGTH, file);
        contact.name[strcspn(contact.name, "\n")] = 0; // Remove newline
        contact.phone[strcspn(contact.phone, "\n")] = 0; // Remove newline

        if (strcmp(contact.name, name) != 0) {
            fprintf(temp_file, "%s\n%s\n", contact.name, contact.phone);
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
        printf("Contact not found!\n");
    }
}

void clear_line_buffer() {
    while (getchar() != '\n');
}