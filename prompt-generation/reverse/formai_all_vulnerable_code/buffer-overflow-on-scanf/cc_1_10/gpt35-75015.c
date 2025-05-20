//FormAI DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_CONTACTS 100

struct contact {
    char name[50];
    char phone_number[15];
    char email[50];
};

struct address_book {
    struct contact contacts[MAX_NUM_CONTACTS];
    int num_contacts;
};

void add_contact(struct address_book* book) {
    struct contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter phone number: ");
    scanf("%s", new_contact.phone_number);
    printf("Enter email: ");
    scanf("%s", new_contact.email);
    book->contacts[book->num_contacts] = new_contact;
    book->num_contacts++;
    printf("Contact added!\n");
}

void search_contact(struct address_book* book) {
    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < book->num_contacts; i++) {
        if (strcmp(book->contacts[i].name, search_name) == 0) {
            printf("Name: %s\nPhone Number: %s\nEmail: %s\n", book->contacts[i].name, book->contacts[i].phone_number, book->contacts[i].email);
            return;
        }
    }
    printf("No contact found with name %s\n", search_name);
}

void print_contacts(struct address_book* book) {
    if (book->num_contacts == 0) {
        printf("No contacts in address book\n");
    } else {
        printf("Contacts:\n");
        for (int i = 0; i < book->num_contacts; i++) {
            printf("%s %s %s\n", book->contacts[i].name, book->contacts[i].phone_number, book->contacts[i].email);
        }
    }
}

int main() {
    struct address_book book;
    book.num_contacts = 0;
    while (1) {
        printf("Welcome to your phone book!\n");
        printf("1. Add contact\n");
        printf("2. Search for contact\n");
        printf("3. Print all contacts\n");
        printf("4. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_contact(&book); break;
            case 2: search_contact(&book); break;
            case 3: print_contacts(&book); break;
            case 4: printf("Goodbye!"); return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}