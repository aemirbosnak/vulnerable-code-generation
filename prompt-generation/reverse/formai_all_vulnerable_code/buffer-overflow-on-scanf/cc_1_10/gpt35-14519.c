//FormAI DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the name and phone number
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

// Define the maximum number of contacts the phone book can store
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

// Define the phone book as an array of contacts
Contact phoneBook[MAX_CONTACTS];

// Define the number of contacts currently in the phone book
int numContacts = 0;

// Function to add contact to phone book
void addContact() {
    // Check if the phone book is already full
    if (numContacts >= MAX_CONTACTS) {
        printf("Sorry, the phone book is already full.\n");
        return;
    }

    // Get the name and phone number from the user
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the phone number: ");
    scanf("%s", phone);

    // Check if the contact is already in the phone book
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(name, phoneBook[i].name) == 0) {
            printf("%s is already in the phone book.\n", name);
            return;
        }
    }

    // Add the contact to the phone book
    strcpy(phoneBook[numContacts].name, name);
    strcpy(phoneBook[numContacts].phone, phone);
    numContacts++;
    printf("%s has been added to the phone book.\n", name);
}

// Function to search for a contact in the phone book
void searchContact() {
    // Get the name to search for from the user
    char name[MAX_NAME_LENGTH];
    printf("Enter the name to search for: ");
    scanf("%s", name);

    // Search for the contact in the phone book
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(name, phoneBook[i].name) == 0) {
            printf("%s's phone number is %s.\n", name, phoneBook[i].phone);
            return;
        }
    }

    // Contact not found
    printf("%s is not in the phone book.\n", name);
}

// Function to display all the contacts in the phone book
void displayContacts() {
    // Check if the phone book is empty
    if (numContacts == 0) {
        printf("The phone book is empty.\n");
        return;
    }

    // Display the contacts in the phone book
    printf("Contacts in the phone book:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%s: %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

int main() {
    // Display the program header
    printf("Welcome to the Unique Phone Book!\n\n");

    // Loop to get commands from the user
    while (1) {
        // Display the menu options
        printf("Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Execute the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                displayContacts();
                break;
            case 4:
                printf("Thank you for using the Unique Phone Book!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        // Display a separating line
        printf("---------------------------------------\n");
    }

    return 0;
}