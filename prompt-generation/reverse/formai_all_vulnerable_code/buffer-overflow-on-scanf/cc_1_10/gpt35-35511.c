//FormAI DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining a structure to hold contact information
struct Contact {
    char name[50];
    char phone_number[20];
};

// function prototypes
void add_contact(struct Contact*, int*);
void search_contact(struct Contact*, int);
void display_menu();

int main() {
    int choice, num_contacts = 0;
    struct Contact contacts[1000]; // maximum 1000 contacts
    do {
        display_menu(); // display menu to the user
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                search_contact(contacts, num_contacts);
                break;
            case 3:
                printf("\nExiting the program...");
                break;
            default:
                printf("\nInvalid choice! Please choose again.\n");
        }
    } while (choice != 3);
    return 0;
}

// function to add a contact to the phone book
void add_contact(struct Contact *contacts, int *num_contacts) {
    printf("\nEnter name: ");
    scanf("%s", (contacts + *num_contacts)->name);
    printf("Enter phone number: ");
    scanf("%s", (contacts + *num_contacts)->phone_number);
    (*num_contacts)++;
    printf("\nContact added successfully!\n");
}

// function to search for a contact in the phone book
void search_contact(struct Contact *contacts, int num_contacts) {
    char name[50], *phone_number = NULL;
    printf("\nEnter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, (contacts + i)->name) == 0) {
            phone_number = (contacts + i)->phone_number; // assign the phone number to a variable
            break; // exit the loop if a match is found
        }
    }
    if (phone_number != NULL) { // if phone number is found
        printf("\nName: %s\nPhone Number: %s\n", name, phone_number);
    } else { // if phone number is not found
        printf("\nContact not found!\n");
    }
}

// function to display the menu options
void display_menu() {
    printf("\n\nPhone Book Program\n---------------------\n\n");
    printf("1. Add a new contact\n");
    printf("2. Search for a contact\n");
    printf("3. Exit\n");
}