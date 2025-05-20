//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store a contact
typedef struct contact {
    char name[50];
    char number[20];
} contact;

// Function to add a contact to the phone book
void add_contact(contact *phone_book, int *num_contacts) {
    printf("Enter the name of the contact: ");
    scanf("%s", phone_book[*num_contacts].name);

    printf("Enter the number of the contact: ");
    scanf("%s", phone_book[*num_contacts].number);

    (*num_contacts)++;
}

// Function to search for a contact in the phone book
void search_contact(contact *phone_book, int num_contacts) {
    char name[50];

    printf("Enter the name of the contact you want to search for: ");
    scanf("%s", name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Contact found!\n");
            printf("Name: %s\n", phone_book[i].name);
            printf("Number: %s\n", phone_book[i].number);
            return;
        }
    }

    printf("Contact not found!\n");
}

// Function to print the phone book
void print_phone_book(contact *phone_book, int num_contacts) {
    printf("Here is the phone book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
    }
}

// main function
int main() {
    // Declare the phone book
    contact phone_book[100];

    // Initialize the number of contacts to 0
    int num_contacts = 0;

    // Add some contacts to the phone book
    add_contact(phone_book, &num_contacts);
    add_contact(phone_book, &num_contacts);
    add_contact(phone_book, &num_contacts);

    // Search for a contact in the phone book
    search_contact(phone_book, num_contacts);

    // Print the phone book
    print_phone_book(phone_book, num_contacts);

    return 0;
}