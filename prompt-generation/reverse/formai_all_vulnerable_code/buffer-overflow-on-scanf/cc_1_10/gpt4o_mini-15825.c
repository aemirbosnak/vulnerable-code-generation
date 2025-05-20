//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact database[MAX_RECORDS];
int record_count = 0;

void add_contact() {
    if (record_count >= MAX_RECORDS) {
        printf("Database full! Unable to add new contact.\n");
        return;
    }
    Contact new_contact;
    new_contact.id = record_count + 1;

    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter phone number: ");
    scanf("%s", new_contact.phone);
    
    database[record_count] = new_contact;
    record_count++;

    printf("Contact added successfully!\n");
}

void display_contacts() {
    if (record_count == 0) {
        printf("No contacts in the database!\n");
        return;
    }
    printf("\nContact Database:\n");
    printf("ID\tName\t\tPhone\n");
    printf("-----------------------------\n");
    for (int i = 0; i < record_count; i++) {
        printf("%d\t%s\t%s\n", database[i].id, database[i].name, database[i].phone);
    }
}

void search_contact() {
    char search_name[NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < record_count; i++) {
        if (strcmp(database[i].name, search_name) == 0) {
            printf("Found contact - ID: %d, Name: %s, Phone: %s\n", database[i].id, database[i].name, database[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No contact found with the name %s.\n", search_name);
    }
}

void delete_contact() {
    int id;
    printf("Enter the ID of the contact to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > record_count) {
        printf("Invalid ID! Please try again.\n");
        return;
    }

    for (int i = id - 1; i < record_count - 1; i++) {
        database[i] = database[i + 1];
    }
    record_count--;
    printf("Contact with ID %d deleted successfully!\n", id);
}

void save_contacts() {
    FILE *file = fopen("contacts.dat", "wb");
    if (!file) {
        printf("Error opening file for saving!\n");
        return;
    }
    fwrite(database, sizeof(Contact), record_count, file);
    fclose(file);
    printf("Contacts saved to contacts.dat successfully!\n");
}

void load_contacts() {
    FILE *file = fopen("contacts.dat", "rb");
    if (!file) {
        printf("No saved contact file found, starting fresh!\n");
        return;
    }
    record_count = fread(database, sizeof(Contact), MAX_RECORDS, file);
    fclose(file);
    printf("Contacts loaded successfully! Total records: %d\n", record_count);
}

int main() {
    load_contacts();
    
    int choice;

    while (1) {
        printf("\n--- Contact Database Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save Contacts\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                save_contacts();
                break;
            case 6:
                save_contacts(); // Save before exiting
                printf("Goodbye! Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}