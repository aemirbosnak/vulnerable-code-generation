//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} ContactManager;

// Function to initialize the contact manager
void initContactManager(ContactManager *manager) {
    manager->count = 0;
}

// Function to add a contact
int addContact(ContactManager *manager, const char *name, const char *phone) {
    if (manager->count >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return -1;
    }
    
    strncpy(manager->contacts[manager->count].name, name, NAME_LENGTH - 1);
    manager->contacts[manager->count].name[NAME_LENGTH - 1] = '\0'; // ensuring null termination
    
    strncpy(manager->contacts[manager->count].phone, phone, PHONE_LENGTH - 1);
    manager->contacts[manager->count].phone[PHONE_LENGTH - 1] = '\0'; // ensuring null termination

    manager->count++;
    return 0;
}

// Function to search for a contact
void searchContact(const ContactManager *manager, const char *name) {
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->contacts[i].name, name) == 0) {
            printf("Contact found: %s - %s\n", manager->contacts[i].name, manager->contacts[i].phone);
            return;
        }
    }
    printf("Contact %s not found!\n", name);
}

// Function to delete a contact
int deleteContact(ContactManager *manager, const char *name) {
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->contacts[i].name, name) == 0) {
            // Shift contacts to remove the deleted contact
            for (int j = i; j < manager->count - 1; j++) {
                manager->contacts[j] = manager->contacts[j + 1];
            }
            manager->count--;
            printf("Contact %s deleted successfully.\n", name);
            return 0;
        }
    }
    printf("Contact %s not found to delete!\n", name);
    return -1;
}

// Function to list all contacts
void listContacts(const ContactManager *manager) {
    if (manager->count == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < manager->count; i++) {
        printf("%d: %s - %s\n", i + 1, manager->contacts[i].name, manager->contacts[i].phone);
    }
}

// Function to display menu and get user choice
int displayMenu() {
    int choice;
    printf("\nContact Manager\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Delete Contact\n");
    printf("4. List All Contacts\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Main function
int main() {
    ContactManager manager;
    initContactManager(&manager);
    
    while (1) {
        int choice = displayMenu();
        
        switch (choice) {
            case 1: {
                char name[NAME_LENGTH], phone[PHONE_LENGTH];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                addContact(&manager, name, phone);
                break;
            }
            case 2: {
                char name[NAME_LENGTH];
                printf("Enter name to search: ");
                scanf("%s", name);
                searchContact(&manager, name);
                break;
            }
            case 3: {
                char name[NAME_LENGTH];
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteContact(&manager, name);
                break;
            }
            case 4:
                listContacts(&manager);
                break;
            case 5:
                printf("Exiting.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}