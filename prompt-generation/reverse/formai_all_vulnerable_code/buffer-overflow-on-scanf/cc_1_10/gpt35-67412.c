//FormAI DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone_number[15];
} Contact;

// Function declarations
void add_contact(Contact contacts[], int *num_contacts);
void find_contact(Contact contacts[], int num_contacts);
void print_contacts(Contact contacts[], int num_contacts);

int main() {
    Contact contacts[MAX_CONTACTS] = {0};
    int num_contacts = 0;
    char choice;

    // Main menu loop
    do {
        printf("\nC Phone Book\n");
        printf("------------\n");
        printf("1. Add contact\n");
        printf("2. Find contact\n");
        printf("3. Print all contacts\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_contact(contacts, &num_contacts);
                break;
            case '2':
                find_contact(contacts, num_contacts);
                break;
            case '3':
                print_contacts(contacts, num_contacts);
                break;
            case '4':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != '4');

    return 0;
}

// Adds a contact to the phone book
void add_contact(Contact contacts[], int *num_contacts) {
    if (*num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }

    Contact new_contact;

    printf("Enter name: ");
    scanf(" %[^\n]", new_contact.name);
    printf("Enter phone number (format: XXX-XXXXXXX): ");
    scanf(" %s", new_contact.phone_number);

    contacts[*num_contacts] = new_contact;
    (*num_contacts)++;

    printf("Contact added.\n");
}

// Finds a contact in the phone book
void find_contact(Contact contacts[], int num_contacts) {
    char search_name[50];
    int found = 0;

    printf("Enter name to search: ");
    scanf(" %[^\n]", search_name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(search_name, contacts[i].name) == 0) {
            printf("%s : %s\n", contacts[i].name, contacts[i].phone_number);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Prints all contacts in the phone book
void print_contacts(Contact contacts[], int num_contacts) {
    if (num_contacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    for (int i = 0; i < num_contacts; i++) {
        printf("%s : %s\n", contacts[i].name, contacts[i].phone_number);
    }
}