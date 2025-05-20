//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of records in the database
#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

// Structure to hold a contact information
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

// Function declarations
void addContact(Contact contacts[], int *count);
void listContacts(Contact contacts[], int count);
void searchContact(Contact contacts[], int count);
void deleteContact(Contact contacts[], int *count);
void displayMenu();

int main() {
    Contact contacts[MAX_RECORDS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                listContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                deleteContact(contacts, &count);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n--- Contact Database Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. List Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more contacts.\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", contacts[*count].name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", contacts[*count].phone);

    (*count)++;
    printf("Contact added successfully!\n");
}

void listContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts available. Add contacts first.\n");
        return;
    }
    
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Contact %d: Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void searchContact(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts available to search.\n");
        return;
    }
    
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);
    
    for (int i = 0; i < count; i++) {
        if (strcasecmp(contacts[i].name, searchName) == 0) {
            printf("Found: Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    
    printf("Contact not found!\n");
}

void deleteContact(Contact contacts[], int *count) {
    if (*count == 0) {
        printf("No contacts available to delete.\n");
        return;
    }
    
    char deleteName[NAME_LENGTH];
    printf("Enter name of the contact to delete: ");
    scanf(" %[^\n]", deleteName);

    for (int i = 0; i < *count; i++) {
        if (strcasecmp(contacts[i].name, deleteName) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }

    printf("Contact not found!\n");
}