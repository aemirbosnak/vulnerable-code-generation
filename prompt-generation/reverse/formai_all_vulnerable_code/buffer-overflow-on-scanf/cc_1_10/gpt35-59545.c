//FormAI DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// define struct for a contact
struct contact {
    char name[50];
    char phone_number[20];
};

// declare global variables
struct contact phone_book[MAX_CONTACTS];
int num_contacts = 0;

// function to add a new contact
void add_contact() {
    // check if phone book is full
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full!");
        return;
    }
    // prompt user for name and number
    printf("Enter contact name: ");
    scanf("%s", phone_book[num_contacts].name);
    printf("Enter contact phone number: ");
    scanf("%s", phone_book[num_contacts].phone_number);
    // update number of contacts
    num_contacts++;
    printf("Contact added successfully!\n");
}

// function to display all contacts
void display_contacts() {
    // check if there are contacts to display
    if (num_contacts == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("Name\t\tPhone number\n");
    printf("=======================================\n");
    // loop through all contacts and print them out
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t\t%s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

// function to search for a contact by name
void search_contact(char name[]) {
    // check if there are contacts to search
    if (num_contacts == 0) {
        printf("No contacts to search.\n");
        return;
    }
    // loop through all contacts and compare name
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            // print out phone number if name matches
            printf("%s's phone number is %s.\n", name, phone_book[i].phone_number);
            return;
        }
    }
    // print message if name not found
    printf("%s not found in phone book.\n", name);
}

// function main
int main() {
    int choice;
    char name[50];
    // loop to display menu and get user's choice
    while (1) {
        printf("\nPhone Book Menu\n");
        printf("1. Add a new contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact by name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // execute corresponding function based on user's choice
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                printf("Enter name to search for: ");
                scanf("%s", name);
                search_contact(name);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}