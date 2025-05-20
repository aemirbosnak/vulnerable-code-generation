//FormAI DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char address[100];
    char phone_number[20];
};

struct PhoneBook {
    int num_of_contacts;
    struct Contact contacts[MAX_CONTACTS];
};

void add_contact(struct PhoneBook *book) {
    if (book->num_of_contacts == MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    struct Contact new_contact;

    printf("Enter name:\n");
    scanf(" %[^\n]", new_contact.name);

    printf("Enter address:\n");
    scanf(" %[^\n]", new_contact.address);

    printf("Enter phone number:\n");
    scanf(" %[^\n]", new_contact.phone_number);

    book->contacts[book->num_of_contacts] = new_contact;
    book->num_of_contacts++;
}

void search_contact(struct PhoneBook book) {
    char search_term[50];
    printf("Enter name or phone number to search:\n");
    scanf(" %[^\n]", search_term);

    int found = 0;
    for (int i = 0; i < book.num_of_contacts; i++) {
        if (strstr(book.contacts[i].name, search_term) != NULL || strstr(book.contacts[i].phone_number, search_term) != NULL) {
            found = 1;
            printf("Name: %s\n", book.contacts[i].name);
            printf("Address: %s\n", book.contacts[i].address);
            printf("Phone number: %s\n", book.contacts[i].phone_number);
        }
    }

    if (!found) {
        printf("No contacts found.\n");
    }
}

void print_phone_book(struct PhoneBook book) {
    printf("===== Phone Book (%d contacts) =====\n", book.num_of_contacts);

    for (int i = 0; i < book.num_of_contacts; i++) {
        printf("Name: %s\n", book.contacts[i].name);
        printf("Address: %s\n", book.contacts[i].address);
        printf("Phone number: %s\n", book.contacts[i].phone_number);
        printf("\n");
    }
}

int main() {
    struct PhoneBook phone_book;
    phone_book.num_of_contacts = 0;

    int option = 0;
    while (option != 4) {
        printf("===== Phone Book =====\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Print phone book\n");
        printf("4. Exit\n");

        printf("Enter option:\n");
        scanf("%d", &option);
        printf("\n");

        switch(option) {
            case 1:
                add_contact(&phone_book);
                break;
            case 2:
                search_contact(phone_book);
                break;
            case 3:
                print_phone_book(phone_book);
                break;
            case 4:
                break;
            default:
                printf("Invalid option.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}