//FormAI DATASET v1.0 Category: Phone Book ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of entries in the phone book
#define MAX_ENTRIES 100

// Define the structure for a contact in the phone book
typedef struct {
    char name[20];
    char phone_number[12];
} Contact;

// Declare a global array to store the phone book entries
Contact phone_book[MAX_ENTRIES];

// Declare functions for adding a contact, deleting a contact, and displaying the phone book
void add_contact();
void delete_contact();
void display_phone_book();

// Declare a function to clear the input buffer
void clear_input_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // Declare variables to store user input
    char command;
    
    // Print the welcome message and display the available commands
    printf("Welcome to the Minimalist Phone Book!\n");
    printf("Available commands:\n");
    printf("a - Add a contact\n");
    printf("d - Delete a contact\n");
    printf("s - Display phone book\n");
    printf("q - Quit\n");
    
    // Loop indefinitely until the user enters the quit command
    while (1) {
        // Prompt the user for a command and read the first character of the input
        printf("\nEnter a command: ");
        scanf("%c", &command);
        clear_input_buffer();
        
        // Process the user's command
        switch (command) {
            case 'a':
                add_contact();
                break;
            case 'd':
                delete_contact();
                break;
            case 's':
                display_phone_book();
                break;
            case 'q':
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid command. Please try again.\n");
        }
    }
    
    return 0;
}

void add_contact() {
    // Declare variables to store the new contact's name and phone number
    char name[20], phone_number[12];
    
    // Prompt the user for the new contact's name and phone number
    printf("\nEnter the contact's name: ");
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove the trailing newline character
    
    printf("Enter the contact's phone number (format: 123-456-7890): ");
    fgets(phone_number, 12, stdin);
    phone_number[strcspn(phone_number, "\n")] = '\0'; // remove the trailing newline character
    
    // Check if the phone book is full
    if (sizeof(phone_book) / sizeof(Contact) == MAX_ENTRIES) {
        printf("\nThe phone book is full. Please delete a contact before adding another.\n");
        return;
    }
    
    // Add the new contact to the phone book
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (phone_book[i].name[0] == '\0') {
            strcpy(phone_book[i].name, name);
            strcpy(phone_book[i].phone_number, phone_number);
            printf("\nContact added!\n");
            return;
        }
    }
}

void delete_contact() {
    // Declare a variable to store the contact to be deleted and a flag to indicate if it was found
    char name[20];
    int i, found = 0;
    
    // Prompt the user for the name of the contact to be deleted
    printf("\nEnter the name of the contact to be deleted: ");
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove the trailing newline character
    
    // Search for the contact in the phone book and delete it if found
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            phone_book[i].name[0] = '\0';
            phone_book[i].phone_number[0] = '\0';
            printf("\nContact deleted!\n");
            found = 1;
            break;
        }
    }
    
    // Notify the user if the contact was not found
    if (!found) {
        printf("\nContact not found.\n");
    }
}

void display_phone_book() {
    // Declare a variable to store the number of contacts in the phone book
    int num_contacts = 0;
    
    // Count the number of contacts in the phone book
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (phone_book[i].name[0] != '\0') {
            num_contacts++;
        }
    }
    
    // Display the phone book header
    printf("\nPhone Book (%d contacts):\n", num_contacts);
    
    // Display each contact in the phone book
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (phone_book[i].name[0] != '\0') {
            printf("%s - %s\n", phone_book[i].name, phone_book[i].phone_number);
        }
    }
}