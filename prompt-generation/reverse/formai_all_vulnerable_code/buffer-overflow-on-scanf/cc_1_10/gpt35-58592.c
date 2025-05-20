//FormAI DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Contact { // Your typical contact struct
    char name[20];
    char number[15];
    char email[30];
    char address[50];
} Contact;

Contact phoneBook[1000]; // An array of Contacts that can hold at most 1000 contact instances
int numOfContacts = 0; // Counter to keep track of number of contacts in our phone book

// Function to add a contact to the phone book
void addContact() {
    printf("Who would you like to add to the phone book? ");
    scanf("%s", phoneBook[numOfContacts].name);

    printf("What is their phone number? ");
    scanf("%s", phoneBook[numOfContacts].number);

    printf("What is their email address? ");
    scanf("%s", phoneBook[numOfContacts].email);

    printf("What is their home address? ");
    scanf("%s", phoneBook[numOfContacts].address);

    numOfContacts++; // Increment number of contacts in our phone book
    printf("Contact added!\n\n");
}

// Function to search for a contact in the phone book
void searchContact() {
    char name[20];
    printf("Who are you looking for? ");
    scanf("%s", name);

    int resultFound = 0; // Boolean flag to check if contact was found
    for (int i=0; i<numOfContacts; i++) {
        // Compare name entered by user with names in our phone book
        if (strcmp(name, phoneBook[i].name) == 0) {
            // If names match, print contact information
            printf("Name: %s\nPhone Number: %s\nEmail: %s\nAddress: %s\n\n", phoneBook[i].name, phoneBook[i].number, phoneBook[i].email, phoneBook[i].address);
            resultFound = 1; // Set flag to true, indicating contact was found
            break; // Exit loop, we found our contact
        }
    }

    // If flag is false, print error message
    if (resultFound == 0) {
        printf("Sorry, could not find any contacts by that name. Maybe they changed their name to Batman?\n\n");
    }
}

// Function to print all contacts in the phone book
void printContacts() {
    if (numOfContacts == 0) { // Check if there are any contacts in our phone book
        printf("Phone book is currently empty. Why not add some quirky contacts like 'Darth Vader' or 'Gandalf'?\n\n");
        return;
    }

    printf("Here are all the contacts in your phone book...\n");
    for (int i=0; i<numOfContacts; i++) {
        printf("Name: %s\nPhone Number: %s\nEmail: %s\nAddress: %s\n\n", phoneBook[i].name, phoneBook[i].number, phoneBook[i].email, phoneBook[i].address);
    }
}

int main() {
    printf("Welcome to the Funny Phone Book Program! Where we take our contacts very seriously (except for the clowns).\n\n");

    int option = 0;
    while (option != 4) {
        printf("What would you like to do?\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Print all contacts\n");
        printf("4. Exit\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                printContacts();
                break;
            case 4:
                printf("Thanks for using the Funny Phone Book Program. Have a good day! (P.S. Don't forget to call your mom today)\n");
                break;
            default:
                printf("Option not recognized. Please enter a valid option.\n");
                break;
        }
    }
    return 0;
}