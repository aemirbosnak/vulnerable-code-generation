//FormAI DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Structures
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
} Contact;

// Function declarations
void add_contact(Contact *contacts, int *num_contacts);
void delete_contact(Contact *contacts, int *num_contacts);
void search_contact(Contact *contacts, int num_contacts);
void display_contacts(Contact *contacts, int num_contacts);

// Main function
int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;
    int choice;
    
    while (1) {
        printf("\nPhone Book\n");
        printf("-----------\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                delete_contact(contacts, &num_contacts);
                break;
            case 3:
                search_contact(contacts, num_contacts);
                break;
            case 4:
                display_contacts(contacts, num_contacts);
                break;
            case 5:
                printf("\nExiting Phone Book. Goodbye!\n\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}

// Function to add contact
void add_contact(Contact *contacts, int *num_contacts) {
    Contact new_contact;
    printf("\nEnter contact name: ");
    scanf("%s", new_contact.name);
    printf("Enter contact email: ");
    scanf("%s", new_contact.email);
    printf("Enter contact phone number: ");
    scanf("%s", new_contact.phone);
    contacts[*num_contacts] = new_contact;
    (*num_contacts)++;
    printf("\nContact added successfully.\n");
}

// Function to delete contact
void delete_contact(Contact *contacts, int *num_contacts) {
    char name[50];
    int i, j;
    printf("\nEnter contact name to delete: ");
    scanf("%s", name);
    for (i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (j = i; j < *num_contacts - 1; j++) {
                contacts[j] = contacts[j+1];
            }
            (*num_contacts)--;
            printf("\nContact deleted successfully.\n");
            return;
        }
    }
    printf("\nContact not found.\n");
}

// Function to search contact
void search_contact(Contact *contacts, int num_contacts) {
    char name[50];
    int i;
    printf("\nEnter contact name to search: ");
    scanf("%s", name);
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("\nName: %s\n", contacts[i].name);
            printf("Email: %s\n", contacts[i].email);
            printf("Phone: %s\n", contacts[i].phone);
            return;
        }
    }
    printf("\nContact not found.\n");
}

// Function to display all contacts
void display_contacts(Contact *contacts, int num_contacts) {
    int i;
    printf("\nContacts\n--------\n");
    for (i = 0; i < num_contacts; i++) {
        printf("%d. %s\n", i+1, contacts[i].name);
    }
    if (num_contacts == 0) {
        printf("No contacts found.\n");
    }
}