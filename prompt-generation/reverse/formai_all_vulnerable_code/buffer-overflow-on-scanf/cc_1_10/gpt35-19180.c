//FormAI DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_ADDRESS_LENGTH 50
#define MAX_PHONE_LENGTH 15

// Define the structure for the contact information
typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

int main() {
    // Declare an array of 100 contacts
    Contact contacts[100];

    // Initialize the number of contacts to 0
    int numContacts = 0;

    // Declare a variable to store user input
    char userInput;

    // Loop until the user chooses to quit
    while (1) {
        // Print the main menu options
        printf("\nWelcome to the Contact Database!\n");
        printf("================================\n");
        printf("1. Add a new contact\n");
        printf("2. View all contacts\n");
        printf("3. Search for a contact by name\n");
        printf("4. Quit\n");

        // Get user input
        printf("\nEnter your choice: ");
        scanf(" %c", &userInput);

        // Handle user input
        switch (userInput) {
            case '1':
                // Add a new contact
                printf("\nEnter the name: ");
                scanf("%s", contacts[numContacts].name);
                printf("Enter the address: ");
                scanf("%s", contacts[numContacts].address);
                printf("Enter the phone number: ");
                scanf("%s", contacts[numContacts].phone);
                numContacts++;
                break;

            case '2':
                // View all contacts
                printf("\nContacts:\n");
                printf("=========\n");
                for (int i = 0; i < numContacts; i++) {
                    printf("Name: %s\n", contacts[i].name);
                    printf("Address: %s\n", contacts[i].address);
                    printf("Phone: %s\n", contacts[i].phone);
                    printf("\n");
                }
                break;

            case '3':
                // Search for a contact by name
                printf("\nEnter the name to search for: ");
                char searchName[MAX_NAME_LENGTH];
                scanf("%s", searchName);
                printf("\nSearch Results:\n");
                printf("================\n");
                for (int i = 0; i < numContacts; i++) {
                    if (strcmp(searchName, contacts[i].name) == 0) {
                        printf("Name: %s\n", contacts[i].name);
                        printf("Address: %s\n", contacts[i].address);
                        printf("Phone: %s\n", contacts[i].phone);
                        printf("\n");
                    }
                }
                break;

            case '4':
                // Quit the program
                printf("\nGoodbye!\n");
                return 0;

            default:
                // Handle invalid input
                printf("\nInvalid input. Please try again.\n");
        }
    }
}