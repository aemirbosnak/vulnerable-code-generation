//FormAI DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <string.h>

// Struct to hold contact information
struct Contact {
    char name[50];
    char phone_number[20];
};

// Function to add new contact to phone book
void addNewContact(struct Contact phone_book[], int *num_contacts) {
    printf("Enter name of new contact: ");
    scanf("%s", phone_book[*num_contacts].name);
    printf("Enter phone number of new contact: ");
    scanf("%s", phone_book[*num_contacts].phone_number);
    *num_contacts += 1;
    printf("New contact added successfully!\n");
}

// Function to display all contacts in phone book
void displayContacts(struct Contact phone_book[], int num_contacts) {
    if (num_contacts == 0) {
        printf("No contacts in phone book.\n");
    } else {
        printf("%-20s%-20s\n", "Name", "Phone Number");
        printf("------------------------------------\n");
        for (int i = 0; i < num_contacts; i++) {
            printf("%-20s%-20s\n", phone_book[i].name, phone_book[i].phone_number);
        }
    }
}

int main(void) {

    // Welcome message and instructions on how to use program
    printf("Welcome to your personal C Phone Book!\n");
    printf("Use the following commands to navigate:\n");
    printf("'a' - Add new contact\n");
    printf("'d' - Display all contacts\n");
    printf("'q' - Quit program\n");

    // Initialize phone book with 100 contacts
    int num_contacts = 0;
    struct Contact phone_book[100];

    // Loop to continually ask for user input until they quit the program
    char input;
    do {
        printf("Enter command: ");
        scanf(" %c", &input);

        switch (input) {
            case 'a':
                addNewContact(phone_book, &num_contacts);
                break;
            case 'd':
                displayContacts(phone_book, num_contacts);
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid command.\n");
        }
    } while (input != 'q');

    return 0;
}