//FormAI DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Define struct to represent a contact
typedef struct contact_s {
    char name[30];
    char phone[15];
} contact;

// Define function to add a contact to the phone book
void add_contact(contact* phone_book[], int* num_contacts) {
    if (*num_contacts == MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }
    contact* new_contact = malloc(sizeof(contact)); // Allocate memory for new contact
    printf("Enter name: ");
    scanf("%s", new_contact->name);
    printf("Enter phone number: ");
    scanf("%s", new_contact->phone);
    phone_book[*num_contacts] = new_contact; // Add new contact to phone book
    (*num_contacts)++;
    printf("Contact added successfully!\n");
}

// Define function to search for a contact by name
void search_contact(contact* phone_book[], int num_contacts) {
    char search_name[30];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i]->name, search_name) == 0) { // Compare names
            printf("Name: %s\nPhone: %s\n", phone_book[i]->name, phone_book[i]->phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

// Define function to print all contacts in the phone book
void print_contacts(contact* phone_book[], int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\nPhone: %s\n\n", phone_book[i]->name, phone_book[i]->phone);
    }
}

// Define main function
int main() {
    contact* phone_book[MAX_CONTACTS]; 
    int num_contacts = 0;
    int choice;
    while (1) { // Loop until user chooses to exit
        printf("Phone Book Menu\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Print All Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(phone_book, &num_contacts);
                break;
            case 2:
                search_contact(phone_book, num_contacts);
                break;
            case 3:
                print_contacts(phone_book, num_contacts);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
    }
    return 0;
}