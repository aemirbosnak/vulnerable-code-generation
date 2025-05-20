//FormAI DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100 // maximum number of contacts in the phone book
#define MAX_NAME_LENGTH 30 // maximum length of a contact's name
#define MAX_NUMBER_LENGTH 15 // maximum length of a contact's phone number

// function prototypes
void add_contact();
void delete_contact();
void search_contact();
void display_contacts();

// struct definition for a single contact
typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

// global variable to store the contacts in the phone book
Contact phone_book[MAX_CONTACTS];

int num_contacts = 0; // number of contacts currently in the phone book

int main() {
    int choice = 0; // user's choice from the menu
    while (1) { // infinite loop until user chooses to quit
        
        // display menu
        printf("Phone Book Menu:\n");
        printf("1. Add a contact\n");
        printf("2. Delete a contact\n");
        printf("3. Search for a contact\n");
        printf("4. Display all contacts\n");
        printf("5. Quit\n");
        printf("Enter your choice (1-5): ");
        
        // read user's choice
        scanf("%d", &choice);
        getchar(); // consume newline character left in stdin
        
        // perform action based on user's choice
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                delete_contact();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                display_contacts();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
        
    }
}

void add_contact() {
    Contact new_contact; // create a new Contact struct to hold the new contact info
    
    // read the name from the user
    printf("Enter the contact's name: ");
    fgets(new_contact.name, MAX_NAME_LENGTH, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = '\0'; // remove trailing newline from name
    
    // read the phone number from the user
    printf("Enter the contact's phone number: ");
    fgets(new_contact.number, MAX_NUMBER_LENGTH, stdin);
    new_contact.number[strcspn(new_contact.number, "\n")] = '\0'; // remove trailing newline from number
    
    // check if we've reached the maximum number of contacts in the phone book
    if (num_contacts == MAX_CONTACTS) {
        printf("The phone book is full. Cannot add new contact.\n");
        return;
    }
    
    // add the new contact to the phone book array and increment the number of contacts
    phone_book[num_contacts] = new_contact;
    num_contacts++;
    
    printf("Contact added successfully.\n");
}

void delete_contact() {
    char name[MAX_NAME_LENGTH]; // create a buffer to hold the name of the contact to delete
    int found = 0; // flag to indicate if we found the contact
    
    // read the name of the contact to delete from the user
    printf("Enter the name of the contact to delete: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove trailing newline from name
    
    // loop through the contacts in the phone book and delete the matching contact, shifting all subsequent contacts down one index in the array
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) { // found a matching contact
            found = 1;
            for (int j = i; j < num_contacts - 1; j++) { // shift subsequent contacts down one index in the array
                phone_book[j] = phone_book[j+1];
            }
            num_contacts--; // decrement the number of contacts in the phone book
            printf("Contact deleted successfully.\n");
            break; // exit the loop since we found and deleted the contact
        }
    }
    
    // if we didn't find the contact, display an error message
    if (!found) {
        printf("Could not find contact with that name.\n");
    }
}

void search_contact() {
    char name[MAX_NAME_LENGTH]; // create a buffer to hold the name of the contact to search for
    int found = 0; // flag to indicate if we found the contact
    
    // read the name of the contact to search for from the user
    printf("Enter the name of the contact to search for: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove trailing newline from name
    
    // loop through the contacts in the phone book and display any matching contacts
    for (int i = 0; i < num_contacts; i++) {
        if (strstr(phone_book[i].name, name) != NULL) { // found a contact that contains the search string in its name
            found = 1;
            printf("%s\t%s\n", phone_book[i].name, phone_book[i].number);
        }
    }
    
    // if we didn't find any matching contacts, display an error message
    if (!found) {
        printf("Could not find any contacts with that name.\n");
    }
}

void display_contacts() {
    if (num_contacts == 0) { // phone book is empty
        printf("The phone book is empty.\n");
    } else { // phone book has at least one contact
        printf("Name\tPhone Number\n");
        for (int i = 0; i < num_contacts; i++) {
            printf("%s\t%s\n", phone_book[i].name, phone_book[i].number);
        }
    }
}