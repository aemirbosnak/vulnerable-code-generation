//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define INITIAL_CONTACTS 2

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

typedef struct {
    Contact *contacts;
    int size;
    int capacity;
} AddressBook;

// Function to initialize the address book
AddressBook* init_address_book() {
    AddressBook *book = (AddressBook *)malloc(sizeof(AddressBook));
    if (!book) {
        perror("Failed to allocate memory for address book");
        exit(EXIT_FAILURE);
    }
    book->size = 0;
    book->capacity = INITIAL_CONTACTS;
    book->contacts = (Contact *)malloc(book->capacity * sizeof(Contact));
    if (!book->contacts) {
        free(book);
        perror("Failed to allocate memory for contacts");
        exit(EXIT_FAILURE);
    }
    return book;
}

// Function to resize the contacts array
void resize_address_book(AddressBook *book) {
    book->capacity *= 2;
    book->contacts = (Contact *)realloc(book->contacts, book->capacity * sizeof(Contact));
    if (!book->contacts) {
        perror("Failed to resize contacts array");
        exit(EXIT_FAILURE);
    }
}

// Function to add a contact
void add_contact(AddressBook *book) {
    if (book->size >= book->capacity) {
        resize_address_book(book);
    }

    printf("Enter name: ");
    scanf("%s", book->contacts[book->size].name);
    printf("Enter phone: ");
    scanf("%s", book->contacts[book->size].phone);
    
    book->size++;
}

// Function to display all contacts
void display_contacts(AddressBook *book) {
    if (book->size == 0) {
        printf("No contacts available.\n");
        return;
    }
    
    printf("Contact List:\n");
    for (int i = 0; i < book->size; i++) {
        printf("Name: %s, Phone: %s\n", book->contacts[i].name, book->contacts[i].phone);
    }
}

// Function to delete a contact
void delete_contact(AddressBook *book) {
    if (book->size == 0) {
        printf("No contacts available to delete.\n");
        return;
    }
    
    char name_to_delete[MAX_NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name_to_delete);

    int found = 0;
    for (int i = 0; i < book->size; i++) {
        if (strcmp(book->contacts[i].name, name_to_delete) == 0) {
            found = 1;
            // Shift all contacts after the deleted one
            for (int j = i; j < book->size - 1; j++) {
                book->contacts[j] = book->contacts[j + 1];
            }
            book->size--;
            printf("Contact '%s' deleted successfully.\n", name_to_delete);
            break;
        }
    }
    if (!found) {
        printf("Contact '%s' not found.\n", name_to_delete);
    }
}

// Function to clean up and free memory
void free_address_book(AddressBook *book) {
    free(book->contacts);
    free(book);
}

// Main function to handle user input
int main() {
    AddressBook *my_address_book = init_address_book();
    int choice;

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(my_address_book);
                break;
            case 2:
                display_contacts(my_address_book);
                break;
            case 3:
                delete_contact(my_address_book);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    free_address_book(my_address_book);
    return 0;
}