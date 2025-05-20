//FormAI DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold phone book information
typedef struct {
    char name[50];
    char phone_number[15];
    char address[100];
} Contact;

// Function prototypes
void add_contact(Contact *);
void search_contact(Contact *, char *);
void print_contacts(Contact *);

int main() {
    Contact phone_book[1000]; // Array to hold up to 1000 contacts
    int num_contacts = 0;
    char command;

    while (true) {
        printf("\nWelcome to the Phone Book!\n");
        printf("Enter 'a' to add a new contact.\n");
        printf("Enter 's' to search for a contact.\n");
        printf("Enter 'p' to print all contacts.\n");
        printf("Enter 'q' to quit.\n");

        scanf(" %c", &command);

        switch (command) {
            case 'a':
                add_contact(&phone_book[num_contacts]);
                num_contacts++;
                break;
            case 's':
                printf("Enter a name to search for: ");
                char name[50];
                scanf(" %[^\n]s", name);
                search_contact(phone_book, name);
                break;
            case 'p':
                print_contacts(phone_book);
                break;
            case 'q':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid command.\n");
        }
    }
}

// Function to add a new contact to the phone book
void add_contact(Contact *contact) {
    printf("Enter the contact's name: ");
    scanf(" %[^\n]s", contact->name);

    printf("Enter the contact's phone number: ");
    scanf(" %[^\n]s", contact->phone_number);

    printf("Enter the contact's address: ");
    scanf(" %[^\n]s", contact->address);

    printf("Contact added!\n");
}

// Function to search for a contact by name
void search_contact(Contact *phone_book, char *name) {
    for (int i = 0; i < 1000; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Contact found!\n");
            printf("Name: %s\n", phone_book[i].name);
            printf("Phone number: %s\n", phone_book[i].phone_number);
            printf("Address: %s\n", phone_book[i].address);
            return;
        }
    }
    printf("Contact not found.\n");
}

// Function to print all contacts in the phone book
void print_contacts(Contact *phone_book) {
    if (phone_book[0].name[0] == '\0') {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < 1000; i++) {
        if (phone_book[i].name[0] == '\0') {
            return;
        }
        printf("Name: %s\n", phone_book[i].name);
        printf("Phone number: %s\n", phone_book[i].phone_number);
        printf("Address: %s\n\n", phone_book[i].address);
    }
}