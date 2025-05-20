//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[20];
};

struct ContactBook {
    int numContacts;
    struct Contact contacts[100];
};

void addContact(struct ContactBook *book, char *name, char *phone) {
    if (book->numContacts >= 100) {
        printf("Phone book is full! Can't add anymore contacts.\n");
        return;
    }

    strcpy(book->contacts[book->numContacts].name, name);
    strcpy(book->contacts[book->numContacts].phone, phone);
    book->numContacts++;

    printf("Contact added: %s (%s)\n", name, phone);
}

void searchContact(struct ContactBook *book, char *name) {
    for (int i = 0; i < book->numContacts; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            printf("Found contact: %s (%s)\n", name, book->contacts[i].phone);
            return;
        }
    }

    printf("Contact not found: %s\n", name);
}

void deleteContact(struct ContactBook *book, char *name) {
    for (int i = 0; i < book->numContacts; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            for (int j = i; j < book->numContacts - 1; j++) {
                book->contacts[j] = book->contacts[j + 1];
            }
            book->numContacts--;

            printf("Contact deleted: %s\n", name);
            return;
        }
    }

    printf("Contact not found: %s\n", name);
}

void listContacts(struct ContactBook *book) {
    if (book->numContacts == 0) {
        printf("Phone book is empty! No contacts to list.\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < book->numContacts; i++) {
        printf("%s (%s)\n", book->contacts[i].name, book->contacts[i].phone);
    }
}

int main() {
    struct ContactBook book;
    book.numContacts = 0;

    while (1) {
        printf("\nWelcome to the Phone Book! What would you like to do?\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete a contact\n");
        printf("4. List all contacts\n");
        printf("5. Exit\n");
        printf("\nYour choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the contact's name: ");
                char name[50];
                scanf("%s", name);

                printf("Enter the contact's phone number: ");
                char phone[20];
                scanf("%s", phone);

                addContact(&book, name, phone);
                break;

            case 2:
                printf("Enter the contact's name: ");
                char searchName[50];
                scanf("%s", searchName);

                searchContact(&book, searchName);
                break;

            case 3:
                printf("Enter the contact's name: ");
                char deleteName[50];
                scanf("%s", deleteName);

                deleteContact(&book, deleteName);
                break;

            case 4:
                listContacts(&book);
                break;

            case 5:
                printf("Thank you for using the Phone Book! Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please choose a valid option.\n");
                break;
        }
    }

    return 0;
}