//FormAI DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of contacts
#define MAX_CONTACTS 1000

// Define structure for contacts
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

// Define the phone book array and current number of contacts
Contact phone_book[MAX_CONTACTS];
int num_contacts = 0;

// Function to add a new contact to the phone book
void add_contact() {
    // Check if we have room for another contact
    if (num_contacts >= MAX_CONTACTS) {
        printf("The phone book is full!\n");
        return;
    }
    
    // Get user input for the new contact
    Contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter phone number: ");
    scanf("%s", new_contact.phone);
    printf("Enter email: ");
    scanf("%s", new_contact.email);
    
    // Add the new contact to the phone book
    phone_book[num_contacts] = new_contact;
    num_contacts++;
}

// Function to list all contacts in the phone book
void list_contacts() {
    // Print header
    printf("Phone Book:\n");
    printf("------------\n");
    
    // Loop through all contacts and print their info
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", phone_book[i].name);
        printf("Phone: %s\n", phone_book[i].phone);
        printf("Email: %s\n", phone_book[i].email);
        printf("\n");
    }
}

// Function to search for a contact by name
void search_contact() {
    // Get user input for the name to search for
    char search_name[50];
    printf("Enter name to search for: ");
    scanf("%s", search_name);
    
    // Loop through all contacts and search for the name
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, search_name) == 0) {
            printf("Name: %s\n", phone_book[i].name);
            printf("Phone: %s\n", phone_book[i].phone);
            printf("Email: %s\n", phone_book[i].email);
            return;
        }
    }
    
    // If we haven't found the contact, print an error message
    printf("Contact not found!\n");
}

int main() {
    // Loop to prompt the user for commands
    while (1) {
        printf("Enter a command (add, list, search, exit): ");
        char command[10];
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {
            add_contact();
        }
        else if (strcmp(command, "list") == 0) {
            list_contacts();
        }
        else if (strcmp(command, "search") == 0) {
            search_contact();
        }
        else if (strcmp(command, "exit") == 0) {
            return 0;
        }
        else {
            printf("Invalid command! Please try again.\n");
        }
    }
}