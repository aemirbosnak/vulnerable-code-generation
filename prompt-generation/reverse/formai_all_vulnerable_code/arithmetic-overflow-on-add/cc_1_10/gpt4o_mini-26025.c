//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 30
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_RECORDS];
    int count;
} ContactDatabase;

void initDatabase(ContactDatabase *db) {
    db->count = 0;
}

void addContact(ContactDatabase *db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more contacts.\n");
        return;
    }
    
    printf("Enter name: ");
    scanf(" %[^\n]", db->contacts[db->count].name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", db->contacts[db->count].phone);
    
    db->count++;
    printf("Contact added successfully!\n");
}

void viewContacts(const ContactDatabase *db) {
    if (db->count == 0) {
        printf("No contacts in the database.\n");
        return;
    }
    
    printf("\n--- Contacts List ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("Contact %d - Name: %s, Phone: %s\n", 
                i + 1, db->contacts[i].name, db->contacts[i].phone);
    }
    printf("---------------------\n");
}

void searchContact(const ContactDatabase *db) {
    char searchName[NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf(" %[^\n]", searchName);
    
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->contacts[i].name, searchName) == 0) {
            printf("Found Contact - Name: %s, Phone: %s\n", 
                    db->contacts[i].name, db->contacts[i].phone);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No contact found with the name: %s\n", searchName);
    }
}

void deleteContact(ContactDatabase *db) {
    char deleteName[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]", deleteName);
    
    int found = -1;
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->contacts[i].name, deleteName) == 0) {
            found = i;
            break;
        }
    }
    
    if (found >= 0) {
        for (int i = found; i < db->count - 1; i++) {
            db->contacts[i] = db->contacts[i + 1];
        }
        db->count--;
        printf("Contact deleted successfully!\n");
    } else {
        printf("No contact found with the name: %s\n", deleteName);
    }
}

void displayMenu() {
    printf("\n--- Contact Database Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("-----------------------------\n");
}

int main() {
    ContactDatabase db;
    initDatabase(&db);
    
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact(&db);
                break;
            case 2:
                viewContacts(&db);
                break;
            case 3:
                searchContact(&db);
                break;
            case 4:
                deleteContact(&db);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}