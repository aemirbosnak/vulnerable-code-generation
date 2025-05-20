//FormAI DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A structure to hold each contact in the phone book
struct contact {
    char name[30];
    char phone[15];
    char email[50];
};

// A function to add a new contact to the phone book
void add_contact(struct contact book[], int* num_contacts) {
    // Check if there is space in the phone book
    if (*num_contacts >= 100) {
        printf("Sorry, the phone book is full.\n");
        return;
    }
    
    // Get the information for the new contact
    struct contact new_contact;
    printf("Enter the name of the new contact: ");
    fgets(new_contact.name, 30, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0; // Remove the newline character
    printf("Enter the phone number of the new contact: ");
    fgets(new_contact.phone, 15, stdin);
    new_contact.phone[strcspn(new_contact.phone, "\n")] = 0; // Remove the newline character
    printf("Enter the email address of the new contact: ");
    fgets(new_contact.email, 50, stdin);
    new_contact.email[strcspn(new_contact.email, "\n")] = 0; // Remove the newline character
    
    // Add the new contact to the phone book
    book[*num_contacts] = new_contact;
    (*num_contacts)++;
    printf("New contact added!\n");
}

// A function to search for a contact by name
void search_contact(struct contact book[], int num_contacts) {
    char search_name[30];
    printf("Enter the name of the contact you are searching for: ");
    fgets(search_name, 30, stdin);
    search_name[strcspn(search_name, "\n")] = 0; // Remove the newline character
    
    // Loop through the phone book to search for the contact
    int found_contact = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(book[i].name, search_name) == 0) {
            printf("Name: %s\nPhone Number: %s\nEmail: %s\n", book[i].name, book[i].phone, book[i].email);
            found_contact = 1;
            break;
        }
    }
    
    if (!found_contact) {
        printf("Sorry, contact not found.\n");
    }
}

// A function to display all contacts in the phone book
void display_contacts(struct contact book[], int num_contacts) {
    if (num_contacts == 0) {
        printf("The phone book is empty.\n");
        return;
    }
    
    printf("%-30s | %-15s | %-50s\n", "Name", "Phone Number", "Email");
    for (int i = 0; i < num_contacts; i++) {
        printf("%-30s | %-15s | %-50s\n", book[i].name, book[i].phone, book[i].email);
    }
}

int main() {
    struct contact phone_book[100]; // Maximum of 100 contacts
    int num_contacts = 0; // Current number of contacts
    
    // Loop through the menu until the user chooses to exit
    int choice = 0;
    while (choice != 4) {
        printf("Choose an option:\n");
        printf("1. Add a new contact\n");
        printf("2. Search for a contact by name\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        getchar(); // Remove the newline character from the input
        
        switch (choice) {
            case 1:
                add_contact(phone_book, &num_contacts);
                break;
            case 2:
                search_contact(phone_book, num_contacts);
                break;
            case 3:
                display_contacts(phone_book, num_contacts);
                break;
            case 4:
                printf("Exiting Phone Book...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    
    return 0;
}