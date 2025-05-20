//FormAI DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

struct PhoneBook {
    struct Contact contacts[MAX_CONTACTS];
    int size;
};

int addContact(struct PhoneBook *book, char* name, char* phone, char* email) {
    if (book->size < MAX_CONTACTS) {
        strcpy(book->contacts[book->size].name, name);
        strcpy(book->contacts[book->size].phone, phone);
        strcpy(book->contacts[book->size].email, email);

        book->size++;

        return 1;
    }

    return 0;
}

void printContacts(struct PhoneBook *book) {
    printf("Contacts:\n");
    for (int i = 0; i < book->size; i++) {
        printf("%s %s %s\n", book->contacts[i].name, book->contacts[i].phone, book->contacts[i].email);
    }
}

int main() {
    struct PhoneBook book = {0};

    printf("Welcome to the C Phone Book!\n");

    while (1) {
        printf("What would you like to do? (1=add contact, 2=print contacts, 3=exit)\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char name[50], phone[20], email[50];
            printf("Enter name, phone, and email (separated by spaces):\n");
            scanf("%s %s %s", name, phone, email);
            if (addContact(&book, name, phone, email)) {
                printf("Contact added successfully.\n");
            } else {
                printf("Phone book is full, cannot add contact.\n");
            }
        } else if (choice == 2) {
            printContacts(&book);
        } else if (choice == 3) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}