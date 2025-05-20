//FormAI DATASET v1.0 Category: Phone Book ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CONTACTS 100


struct Contact {
    char name[100];
    char phoneNo[15];
};

struct PhoneBook {
    struct Contact contacts[MAX_CONTACTS];
    int count;
};

// Function to add a new contact to the phone book
void addContact(struct PhoneBook* book) {
    printf("Enter Contact name: ");
    scanf(" %[^\n]s", &book->contacts[book->count].name);
    printf("Enter Contact phone number: ");
    scanf(" %s", &book->contacts[book->count].phoneNo);
    book->count++;
}

// Function to search for a contact in the phone book
void searchContact(struct PhoneBook* book, char* name) {
    int found = 0;
    for (int i=0; i<book->count; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", book->contacts[i].name, book->contacts[i].phoneNo);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
}

// Function to display all contacts in the phone book
void displayContacts(struct PhoneBook* book) {
    printf("Contacts:\n");
    for (int i=0; i<book->count; i++) {
        printf("Name: %s\nPhone Number: %s\n", book->contacts[i].name, book->contacts[i].phoneNo);
    }
}

int main() {
    struct PhoneBook book;
    book.count = 0;
    int choice = 0;

    while (1) {
        printf("Choose an option:\n");
        printf("1. Add a new contact\n2. Search for a contact\n3. Display all contacts\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (book.count == MAX_CONTACTS) {
                    printf("Phone book is full!\n");
                    break;
                } else {
                    addContact(&book);
                    printf("Contact added!\n");
                    break;
                }
            case 2:
                if (book.count == 0) {
                    printf("Phone book is empty!\n");
                    break;
                }
                char name[100];
                printf("Enter the name of the contact to search for: ");
                scanf(" %[^\n]s", name);
                searchContact(&book, name);
                break;
            case 3:
                if (book.count == 0) {
                    printf("Phone book is empty!\n");
                    break;
                }
                displayContacts(&book);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}