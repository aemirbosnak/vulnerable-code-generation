//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_ENTRIES 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_ENTRIES];
    int count;
} AddressBook;

void initialize(AddressBook *book) {
    book->count = 0;
}

int add_contact(AddressBook *book, const char *name, const char *phone) {
    if (book->count >= MAX_ENTRIES) {
        return -1; // Address Book is full
    }
    
    strncpy(book->contacts[book->count].name, name, MAX_NAME_LENGTH - 1);
    book->contacts[book->count].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination

    strncpy(book->contacts[book->count].phone, phone, MAX_PHONE_LENGTH - 1);
    book->contacts[book->count].phone[MAX_PHONE_LENGTH - 1] = '\0'; // Ensure null-termination
    
    book->count++;
    return 0; // Success
}

int delete_contact(AddressBook *book, const char *name) {
    for (int i = 0; i < book->count; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            // Shift the remaining contacts up to fill the gap
            for (int j = i; j < book->count - 1; j++) {
                book->contacts[j] = book->contacts[j + 1];
            }
            book->count--;
            return 0; // Contact deleted
        }
    }
    return -1; // Contact not found
}

void list_contacts(const AddressBook *book) {
    printf("Address Book Contacts:\n");
    for (int i = 0; i < book->count; i++) {
        printf("%s: %s\n", book->contacts[i].name, book->contacts[i].phone);
    }
}

int main() {
    AddressBook book;
    initialize(&book);
    
    int choice;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. List Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            // Handle invalid input
            printf("Invalid input. Please enter a number between 1-4.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf(" %[^\n]%*c", name); // Read string with spaces
                printf("Enter phone number: ");
                scanf(" %[^\n]%*c", phone);
                
                if (add_contact(&book, name, phone) < 0) {
                    printf("Error: Address Book is full!\n");
                } else {
                    printf("Contact added successfully!\n");
                }
                break;
                
            case 2:
                printf("Enter name of contact to delete: ");
                scanf(" %[^\n]%*c", name);
                
                if (delete_contact(&book, name) < 0) {
                    printf("Error: Contact not found!\n");
                } else {
                    printf("Contact deleted successfully!\n");
                }
                break;
                
            case 3:
                list_contacts(&book);
                break;
                
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice. Please enter a number between 1-4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}