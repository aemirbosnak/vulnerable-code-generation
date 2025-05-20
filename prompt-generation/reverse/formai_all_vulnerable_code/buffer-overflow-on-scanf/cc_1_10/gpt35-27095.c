//FormAI DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the contact information
struct contact {
    char name[30];
    char phone_number[15];
    char email[50];
};

// Create an array of contact structs to store the contacts
struct contact phone_book[100];

// Track the number of contacts in the phone book
int num_contacts = 0;

// Function to add a contact to the phone book
void add_contact() {
    printf("\nEnter contact name: ");
    scanf("%s", phone_book[num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", phone_book[num_contacts].phone_number);
    printf("Enter email: ");
    scanf("%s", phone_book[num_contacts].email);
    printf("\nContact added!\n");
    num_contacts++;
}

// Function to display all contacts in the phone book
void display_contacts() {
    printf("\nList of contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t%s\t%s\n", phone_book[i].name, phone_book[i].phone_number, phone_book[i].email);
    }
}

// Function to search for a contact by name
void search_contact() {
    char search_name[30];
    int found = 0;
    printf("\nEnter name to search for: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(search_name, phone_book[i].name) == 0) {
            printf("%s\t%s\t%s\n", phone_book[i].name, phone_book[i].phone_number, phone_book[i].email);
            found = 1;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Main function
int main() {
    int choice;
    do {
        printf("\nPhone Book Menu\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);
    return 0;
}