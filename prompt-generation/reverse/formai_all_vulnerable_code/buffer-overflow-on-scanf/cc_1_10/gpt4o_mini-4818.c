//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: rigorous
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

Contact contacts[MAX_CONTACTS];
int contact_count = 0;

// Function declarations
void add_contact();
void display_contacts();
void search_contact();

int main() {
    int choice;

    do {
        printf("\n--- Contact Manager ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from input buffer

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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void add_contact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list is full! Cannot add more contacts.\n");
        return;
    }
    
    printf("Enter name: ");
    fgets(contacts[contact_count].name, NAME_LENGTH, stdin);
    contacts[contact_count].name[strcspn(contacts[contact_count].name, "\n")] = '\0'; // Remove newline

    printf("Enter phone number: ");
    fgets(contacts[contact_count].phone, PHONE_LENGTH, stdin);
    contacts[contact_count].phone[strcspn(contacts[contact_count].phone, "\n")] = '\0'; // Remove newline

    contact_count++;
    printf("Contact added successfully!\n");
}

void display_contacts() {
    if (contact_count == 0) {
        printf("No contacts to display.\n");
        return;
    }
    
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < contact_count; i++) {
        printf("Contact %d: Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void search_contact() {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < contact_count; i++) {
        if (strcasecmp(contacts[i].name, name) == 0) { // Case-insensitive comparison
            printf("Found Contact: Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}