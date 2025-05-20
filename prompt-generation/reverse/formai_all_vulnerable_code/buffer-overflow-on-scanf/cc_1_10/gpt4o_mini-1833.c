//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define FILE_NAME "phonebook.dat"

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void add_contact();
void view_contacts();
void search_contact();
void delete_contact();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n===== Phone Book Menu =====\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("===========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                printf("Exiting. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

void add_contact() {
    Contact contact;
    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    printf("Enter name: ");
    scanf(" %[^\n]", contact.name);
    printf("Enter phone: ");
    scanf(" %[^\n]", contact.phone);
    
    fwrite(&contact, sizeof(Contact), 1, file);
    fclose(file);
    printf("Contact added successfully!\n");
}

void view_contacts() {
    Contact contact;
    FILE *file = fopen(FILE_NAME, "rb");

    if (file == NULL) {
        printf("No contacts found!\n");
        return;
    }

    printf("\n=== Contacts List ===\n");
    while (fread(&contact, sizeof(Contact), 1, file)) {
        printf("Name: %s, Phone: %s\n", contact.name, contact.phone);
    }
    fclose(file);
}

void search_contact() {
    char name[NAME_LENGTH];
    Contact contact;
    int found = 0;
    FILE *file = fopen(FILE_NAME, "rb");

    if (file == NULL) {
        printf("No contacts found!\n");
        return;
    }
    
    printf("Enter the name to search: ");
    scanf(" %[^\n]", name);

    while (fread(&contact, sizeof(Contact), 1, file)) {
        if (strcmp(contact.name, name) == 0) {
            printf("Contact found: Name: %s, Phone: %s\n", contact.name, contact.phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }

    fclose(file);
}

void delete_contact() {
    char name[NAME_LENGTH];
    Contact contact;
    FILE *file = fopen(FILE_NAME, "rb");
    FILE *tempFile = fopen("temp.dat", "wb");

    if (file == NULL || tempFile == NULL) {
        printf("Error occurred!\n");
        return;
    }

    printf("Enter the name to delete: ");
    scanf(" %[^\n]", name);

    int deleted = 0;
    while (fread(&contact, sizeof(Contact), 1, file)) {
        if (strcmp(contact.name, name) != 0) {
            fwrite(&contact, sizeof(Contact), 1, tempFile);
        } else {
            deleted = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (deleted) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}