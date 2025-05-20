//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15
#define FILENAME "contacts.txt"

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

void add_contact();
void view_contacts();
void delete_contact();
void clear_buffer();

int main() {
    int choice;

    while (1) {
        printf("\nContact Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_buffer();

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
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void add_contact() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    Contact contact;
    printf("Enter name: ");
    fgets(contact.name, NAME_LEN, stdin);
    contact.name[strcspn(contact.name, "\n")] = 0;  // Remove newline
    printf("Enter phone: ");
    fgets(contact.phone, PHONE_LEN, stdin);
    contact.phone[strcspn(contact.phone, "\n")] = 0;  // Remove newline

    fprintf(file, "%s %s\n", contact.name, contact.phone);
    fclose(file);
    printf("Contact added successfully!\n");
}

void view_contacts() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    Contact contact;
    printf("\nContacts:\n");
    while (fscanf(file, "%49s %14s", contact.name, contact.phone) == 2) {
        printf("Name: %s, Phone: %s\n", contact.name, contact.phone);
    }
    fclose(file);
}

void delete_contact() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        perror("Unable to create temporary file");
        fclose(file);
        return;
    }

    char name_to_delete[NAME_LEN];
    printf("Enter name of contact to delete: ");
    fgets(name_to_delete, NAME_LEN, stdin);
    name_to_delete[strcspn(name_to_delete, "\n")] = 0;  // Remove newline

    Contact contact;
    int found = 0;
    while (fscanf(file, "%49s %14s", contact.name, contact.phone) == 2) {
        if (strcmp(contact.name, name_to_delete) != 0) {
            fprintf(temp, "%s %s\n", contact.name, contact.phone);
        } else {
            found = 1;
        }
    }
    fclose(file);
    fclose(temp);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
        remove("temp.txt"); // Cleanup temp file if not found
    }
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}