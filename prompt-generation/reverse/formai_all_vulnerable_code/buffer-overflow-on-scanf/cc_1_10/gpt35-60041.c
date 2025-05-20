//FormAI DATASET v1.0 Category: Phone Book ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#define MAX_CONTACTS 100

// Define the structure of a contact
struct contact {
    char name[50];
    char phone_number[20];
};

// Declare an array of contacts
struct contact contacts[MAX_CONTACTS];

// Declare a variable to keep track of the number of contacts in the phone book
int num_contacts = 0;

// Function to add a new contact to the phone book
void add_contact() {
    // Check if the phone book is full
    if (num_contacts == MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    // Get the name and phone number from the user
    char name[50], phone[20];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", phone);

    // Copy the name and phone number into the next available contact struct in the phone book
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].phone_number, phone);

    // Increment the number of contacts in the phone book
    num_contacts++;

    printf("Contact added successfully!\n");
}

// Function to print the entire phone book
void print_phone_book() {
    printf("Phone book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t%s\n", contacts[i].name, contacts[i].phone_number);
    }
}

// Main function to run the program
int main() {
    int choice;

    // Loop until the user chooses to exit the program
    while (1) {
        // Print the menu
        printf("Menu:\n1. Add a contact\n2. Print phone book\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                print_phone_book();
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}