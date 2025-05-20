//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the maximum size of the name and phone number
#define MAX_NAME_SIZE 50
#define MAX_PHONE_NUMBER_SIZE 15

// Creating a structure to store the contact information
typedef struct Contact {
    char name[MAX_NAME_SIZE];
    char phoneNumber[MAX_PHONE_NUMBER_SIZE];
} Contact;

// Creating an array of contacts
Contact contacts[100];

// Function to add a contact
void addContact(char *name, char *phoneNumber) {
    // Finding an empty slot in the contacts array
    int i;
    for (i = 0; i < 100; i++) {
        if (contacts[i].name[0] == '\0') {
            break;
        }
    }

    // Checking if all slots are full
    if (i == 100) {
        printf("Phone book is full.\n");
        return;
    }

    // Copying the name and phone number into the contacts array
    strcpy(contacts[i].name, name);
    strcpy(contacts[i].phoneNumber, phoneNumber);

    // Printing a success message
    printf("Contact added successfully.\n");
}

// Function to delete a contact
void deleteContact(char *name) {
    // Finding the contact in the contacts array
    int i;
    for (i = 0; i < 100; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            break;
        }
    }

    // Checking if the contact was found
    if (i == 100) {
        printf("Contact not found.\n");
        return;
    }

    // Deleting the contact from the contacts array
    contacts[i].name[0] = '\0';
    contacts[i].phoneNumber[0] = '\0';

    // Printing a success message
    printf("Contact deleted successfully.\n");
}

// Function to search for a contact
void searchContact(char *name) {
    // Finding the contact in the contacts array
    int i;
    for (i = 0; i < 100; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            break;
        }
    }

    // Checking if the contact was found
    if (i == 100) {
        printf("Contact not found.\n");
        return;
    }

    // Printing the contact information
    printf("Name: %s\n", contacts[i].name);
    printf("Phone Number: %s\n", contacts[i].phoneNumber);
}

// Function to print all contacts
void printAllContacts() {
    // Iterating over the contacts array
    int i;
    for (i = 0; i < 100; i++) {
        if (contacts[i].name[0] != '\0') {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone Number: %s\n", contacts[i].phoneNumber);
            printf("\n");
        }
    }
}

// Function to get user input
char *getInput(char *prompt) {
    char *input = malloc(100);
    printf("%s", prompt);
    scanf("%s", input);
    return input;
}

// Main function
int main() {
    // Printing a welcome message
    printf("Welcome to the Phone Book!\n");

    // Creating a loop to keep the program running
    while (1) {
        // Printing a menu of options
        printf("\nOptions:\n");
        printf("1. Add a contact\n");
        printf("2. Delete a contact\n");
        printf("3. Search for a contact\n");
        printf("4. Print all contacts\n");
        printf("5. Exit\n");

        // Getting the user's choice
        char *choice = getInput("Enter your choice: ");

        // Calling the appropriate function based on the user's choice
        switch (atoi(choice)) {
            case 1:
                addContact(getInput("Enter the name: "), getInput("Enter the phone number: "));
                break;
            case 2:
                deleteContact(getInput("Enter the name: "));
                break;
            case 3:
                searchContact(getInput("Enter the name: "));
                break;
            case 4:
                printAllContacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}