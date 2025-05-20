//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define FILENAME "contacts.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void add_contact() {
    Contact c;
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    printf("Enter name: ");
    fgets(c.name, MAX_NAME_LENGTH, stdin);
    c.name[strcspn(c.name, "\n")] = '\0'; // Remove newline character

    printf("Enter phone number: ");
    fgets(c.phone, MAX_PHONE_LENGTH, stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0'; // Remove newline character

    fwrite(&c, sizeof(Contact), 1, file);
    fclose(file);
    printf("Contact added successfully!\n");
}

void view_contacts() {
    Contact c;
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    printf("\nContacts:\n");
    while (fread(&c, sizeof(Contact), 1, file)) {
        printf("Name: %s, Phone: %s\n", c.name, c.phone);
    }
    fclose(file);
}

void delete_contact() {
    Contact c;
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        perror("Unable to create temporary file!");
        fclose(file);
        return;
    }

    char name_to_delete[MAX_NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    fgets(name_to_delete, MAX_NAME_LENGTH, stdin);
    name_to_delete[strcspn(name_to_delete, "\n")] = '\0';

    int found = 0;
    while (fread(&c, sizeof(Contact), 1, file)) {
        if (strcmp(c.name, name_to_delete) != 0) {
            fwrite(&c, sizeof(Contact), 1, temp_file);
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

void display_menu() {
    printf("\nContact Management System\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // to strip the newline from input buffer

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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}