//FormAI DATASET v1.0 Category: Phone Book ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for contact information
typedef struct contact {
    char name[50];
    char phone[20];
} Contact;

// function to add contact to phone book
void add_contact(Contact* phone_book, int* count) {
    printf("Enter name: ");
    scanf("%s", phone_book[*count].name);
    printf("Enter phone number: ");
    scanf("%s", phone_book[*count].phone);
    printf("*** Contact added successfully! ***\n");
    (*count)++;
}

// function to search for a contact
void search_contact(Contact* phone_book, int count) {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(name, phone_book[i].name) == 0) {
            printf("%s's phone number is %s\n", name, phone_book[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

// function to display all contacts
void display_contacts(Contact* phone_book, int count) {
    printf("PHONE BOOK\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-20s\n", phone_book[i].name, phone_book[i].phone);
    }
    printf("--------------------------------------------------\n");
}

// function to display menu and get user input
int get_option() {
    int option;
    printf("\nMENU\n");
    printf("1. Add contact\n");
    printf("2. Search for contact\n");
    printf("3. Display all contacts\n");
    printf("4. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);
    return option;
}

int main() {
    Contact* phone_book = (Contact*) malloc(sizeof(Contact) * 100);
    int count = 0;
    int option;
    printf("RETRO PHONE BOOK\n");
    printf("-----------------\n");
    do {
        option = get_option();
        switch (option) {
            case 1:
                add_contact(phone_book, &count);
                break;
            case 2:
                search_contact(phone_book, count);
                break;
            case 3:
                display_contacts(phone_book, count);
                break;
            case 4:
                printf("*** Terminating Program ***\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 4);
    free(phone_book);
    return 0;
}