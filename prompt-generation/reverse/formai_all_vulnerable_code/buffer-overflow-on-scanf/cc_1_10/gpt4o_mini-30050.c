//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[15];
} Contact;

typedef struct {
    Contact *contacts;
    size_t size;
    size_t capacity;
} AddressBook;

// Function to create an address book
AddressBook* create_address_book(size_t capacity) {
    AddressBook *book = (AddressBook *)malloc(sizeof(AddressBook));
    if (!book) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    book->contacts = (Contact *)malloc(capacity * sizeof(Contact));
    if (!book->contacts) {
        fprintf(stderr, "Memory allocation for contacts failed\n");
        free(book);
        exit(EXIT_FAILURE);
    }
    book->size = 0;
    book->capacity = capacity;
    return book;
}

// Function to add a contact to the address book
void add_contact(AddressBook *book, const char *name, const char *phone) {
    if (book->size >= book->capacity) {
        book->capacity *= 2;
        book->contacts = (Contact *)realloc(book->contacts, book->capacity * sizeof(Contact));
        if (!book->contacts) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    strncpy(book->contacts[book->size].name, name, 49);
    book->contacts[book->size].name[49] = '\0';  // Ensure null termination
    strncpy(book->contacts[book->size].phone, phone, 14);
    book->contacts[book->size].phone[14] = '\0'; // Ensure null termination
    book->size++;
}

// Function to display all contacts
void display_contacts(const AddressBook *book) {
    if (book->size == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("\n--- Address Book ---\n");
    for (size_t i = 0; i < book->size; i++) {
        printf("Contact %zu: %s, Phone: %s\n", i + 1, book->contacts[i].name, book->contacts[i].phone);
    }
}

// Function to free the memory used by the address book
void free_address_book(AddressBook *book) {
    free(book->contacts);
    free(book);
}

// Function to delete a contact by index
void delete_contact(AddressBook *book, size_t index) {
    if (index >= book->size) {
        printf("Index out of range\n");
        return;
    }
    for (size_t i = index; i < book->size - 1; i++) {
        book->contacts[i] = book->contacts[i + 1];
    }
    book->size--;
}

// Main function
int main() {
    size_t initial_capacity = 2;
    AddressBook *myBook = create_address_book(initial_capacity);
    
    while (1) {
        int choice;
        char name[50], phone[15];
        printf("\nMenu:\n1. Add Contact\n2. View Contacts\n3. Delete Contact\n4. Exit\nChoose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Phone: ");
                scanf("%s", phone);
                add_contact(myBook, name, phone);
                break;
            case 2:
                display_contacts(myBook);
                break;
            case 3:
                printf("Enter index of contact to delete (1 to %zu): ", myBook->size);
                size_t index;
                scanf("%zu", &index);
                delete_contact(myBook, index - 1); // Convert to 0-based index
                break;
            case 4:
                free_address_book(myBook);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}