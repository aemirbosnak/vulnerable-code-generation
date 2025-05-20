//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define INITIAL_CAPACITY 2

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

typedef struct {
    Contact *contacts;
    int size;
    int capacity;
} AddressBook;

void initAddressBook(AddressBook *book) {
    book->contacts = (Contact *)malloc(INITIAL_CAPACITY * sizeof(Contact));
    if (book->contacts == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    book->size = 0;
    book->capacity = INITIAL_CAPACITY;
}

void resizeAddressBook(AddressBook *book) {
    book->capacity *= 2;
    book->contacts = (Contact *)realloc(book->contacts, book->capacity * sizeof(Contact));
    if (book->contacts == NULL) {
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

void addContact(AddressBook *book, const char *name, const char *phone) {
    if (book->size >= book->capacity) {
        resizeAddressBook(book);
    }
    strncpy(book->contacts[book->size].name, name, NAME_LENGTH);
    strncpy(book->contacts[book->size].phone, phone, PHONE_LENGTH);
    book->size++;
}

void displayContacts(const AddressBook *book) {
    printf("Address Book:\n");
    for (int i = 0; i < book->size; i++) {
        printf("%d. %s - %s\n", i + 1, book->contacts[i].name, book->contacts[i].phone);
    }
}

void deleteContact(AddressBook *book, int index) {
    if (index < 0 || index >= book->size) {
        fprintf(stderr, "Invalid index!\n");
        return;
    }
    for (int i = index; i < book->size - 1; i++) {
        book->contacts[i] = book->contacts[i + 1];
    }
    book->size--;
}

void freeAddressBook(AddressBook *book) {
    free(book->contacts);
    book->contacts = NULL;
}

int main() {
    AddressBook myBook;
    initAddressBook(&myBook);

    while (1) {
        printf("\n1. Add Contact\n2. Display Contacts\n3. Delete Contact\n4. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline

        if (choice == 1) {
            char name[NAME_LENGTH];
            char phone[PHONE_LENGTH];

            printf("Enter name: ");
            fgets(name, NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = '\0'; // Remove newline

            printf("Enter phone: ");
            fgets(phone, PHONE_LENGTH, stdin);
            phone[strcspn(phone, "\n")] = '\0'; // Remove newline

            addContact(&myBook, name, phone);
            printf("Contact added!\n");

        } else if (choice == 2) {
            displayContacts(&myBook);

        } else if (choice == 3) {
            int index;
            printf("Enter contact index to delete: ");
            scanf("%d", &index);
            deleteContact(&myBook, index - 1); // Adjust for 0-based index
            printf("Contact deleted!\n");

        } else if (choice == 4) {
            break;

        } else {
            printf("Invalid option, try again.\n");
        }
    }

    freeAddressBook(&myBook);
    return 0;
}