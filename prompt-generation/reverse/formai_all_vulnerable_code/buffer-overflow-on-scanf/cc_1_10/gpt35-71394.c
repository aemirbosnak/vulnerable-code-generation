//FormAI DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100

// Structure to hold contact information
struct ContactInfo {
    char name[50];
    char phone_number[15];
    char email[50];
};

// Global variables
struct ContactInfo phone_book[MAX_ENTRIES];
int num_entries = 0;

// Function to add a new contact to the phone book
void add_contact() {
    if(num_entries >= MAX_ENTRIES) {
        printf("Sorry, the phone book is full.\n");
        return;
    }
    
    struct ContactInfo new_contact;
    
    printf("Enter contact name: ");
    fgets(new_contact.name, 50, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0;
    
    printf("Enter phone number: ");
    fgets(new_contact.phone_number, 15, stdin);
    new_contact.phone_number[strcspn(new_contact.phone_number, "\n")] = 0;
    
    printf("Enter email: ");
    fgets(new_contact.email, 50, stdin);
    new_contact.email[strcspn(new_contact.email, "\n")] = 0;
    
    phone_book[num_entries] = new_contact;
    num_entries++;
    printf("Contact added successfully!\n");
}

// Function to display all contacts in the phone book
void display_contacts() {
    if(num_entries == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    
    for(int i=0; i<num_entries; i++) {
        printf("%s, %s, %s\n", phone_book[i].name, phone_book[i].phone_number, phone_book[i].email);
    }
}

int main() {
    int choice;
    
    // Display welcome message
    printf("Welcome to Phone Book!\n");
    
    // Display menu options
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Exit\n");
    
    // Loop until user chooses to exit
    while(1) {
        // Prompt user for choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                printf("Thank you for using Phone Book.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}