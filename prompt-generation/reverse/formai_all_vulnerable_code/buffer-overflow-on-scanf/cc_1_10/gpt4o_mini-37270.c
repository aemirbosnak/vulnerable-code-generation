//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} ContactDatabase;

void initializeDatabase(ContactDatabase *db) {
    db->count = 0;
}

void addContact(ContactDatabase *db) {
    if (db->count >= MAX_CONTACTS) {
        printf("Database is full. Cannot add more contacts.\n");
        return;
    }

    Contact newContact;
    printf("Enter name: ");
    scanf(" %[^\n]", newContact.name);
    printf("Enter phone: ");
    scanf(" %[^\n]", newContact.phone);
    printf("Enter email: ");
    scanf(" %[^\n]", newContact.email);

    db->contacts[db->count] = newContact;
    db->count++;
    printf("Contact added successfully!\n");
}

void displayContacts(const ContactDatabase *db) {
    if (db->count == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\n--- Contacts List ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", db->contacts[i].name);
        printf("Phone: %s\n", db->contacts[i].phone);
        printf("Email: %s\n", db->contacts[i].email);
        printf("--------------------\n");
    }
}

Contact* searchContact(ContactDatabase *db, const char *name) {
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->contacts[i].name, name) == 0) {
            return &db->contacts[i];
        }
    }
    return NULL;
}

void deleteContact(ContactDatabase *db) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->contacts[i].name, name) == 0) {
            // Shift contacts down to remove the deleted contact
            for (int j = i; j < db->count - 1; j++) {
                db->contacts[j] = db->contacts[j + 1];
            }
            db->count--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void menu() {
    printf("\n--- Contact Database Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("------------------------------\n");
}

int main() {
    ContactDatabase db;
    initializeDatabase(&db);
    
    int choice;
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&db);
                break;
            case 2:
                displayContacts(&db);
                break;
            case 3: {
                char name[NAME_LENGTH];
                printf("Enter the name to search: ");
                scanf(" %[^\n]", name);
                
                Contact *contact = searchContact(&db, name);
                if (contact != NULL) {
                    printf("Contact found:\n");
                    printf("Name: %s\n", contact->name);
                    printf("Phone: %s\n", contact->phone);
                    printf("Email: %s\n", contact->email);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 4:
                deleteContact(&db);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}