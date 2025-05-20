//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_SIZE 50
#define PHONE_SIZE 15

typedef struct {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
} Contact;

Contact *contacts[MAX_CONTACTS];
int contact_count = 0;

// Function to safely allocate memory for a new contact
Contact* create_contact(const char* name, const char* phone) {
    if (contact_count >= MAX_CONTACTS) {
        fprintf(stderr, "Error: Maximum contact limit reached.\n");
        return NULL;
    }
    
    Contact *new_contact = malloc(sizeof(Contact));
    if (new_contact == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }

    strncpy(new_contact->name, name, NAME_SIZE);
    new_contact->name[NAME_SIZE - 1] = '\0';
    strncpy(new_contact->phone, phone, PHONE_SIZE);
    new_contact->phone[PHONE_SIZE - 1] = '\0';

    return new_contact;
}

// Function to add a contact
void add_contact(const char* name, const char* phone) {
    Contact *contact = create_contact(name, phone);
    if (contact != NULL) {
        contacts[contact_count++] = contact;
        printf("Contact added: %s, %s\n", contact->name, contact->phone);
    }
}

// Function to display all contacts
void display_contacts() {
    printf("\n--- Contacts List ---\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%d: %s - %s\n", i + 1, contacts[i]->name, contacts[i]->phone);
    }
    printf("---------------------\n");
}

// Function to free all allocated memory for contacts
void free_contacts() {
    for (int i = 0; i < contact_count; i++) {
        free(contacts[i]);
    }
    contact_count = 0;
    printf("All contacts freed.\n");
}

// Main Function
int main() {
    int choice;
    char name[NAME_SIZE], phone[PHONE_SIZE];

    do {
        printf("\n1. Add Contact\n2. Display Contacts\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf(" %[^\n]%*c", name);  // Read string with spaces
                printf("Enter phone number: ");
                scanf(" %[^\n]%*c", phone); // Read string with spaces
                add_contact(name, phone);
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                free_contacts();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}