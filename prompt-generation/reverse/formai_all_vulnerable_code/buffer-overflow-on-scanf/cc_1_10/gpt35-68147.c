//FormAI DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare struct for storing contacts in phone book
struct Contact {
    char firstName[20];
    char lastName[20];
    char phoneNumber[20];
};

// Declare function for adding contact to phone book
void addContact(struct Contact *phoneBook, int index) {
    printf("\nEnter first name: ");
    scanf("%s", phoneBook[index].firstName);
    printf("Enter last name: ");
    scanf("%s", phoneBook[index].lastName);
    printf("Enter phone number: ");
    scanf("%s", phoneBook[index].phoneNumber);

    printf("\nContact added!\n");
}

// Declare function for searching for contact in phone book
void searchContact(struct Contact *phoneBook, int size) {
    char searchName[20];
    int found = 0;

    printf("\nEnter name to search: ");
    scanf("%s", searchName);

    for(int i = 0; i < size; i++) {
        if(strcmp(searchName, phoneBook[i].firstName) == 0 || strcmp(searchName, phoneBook[i].lastName) == 0) {
            printf("\n%s %s's phone number is %s\n", phoneBook[i].firstName, phoneBook[i].lastName, phoneBook[i].phoneNumber);
            found = 1;
        }
    }

    if(!found) {
        printf("\nContact not found!\n");
    }
}

// Declare function for displaying all contacts in phone book
void displayContacts(struct Contact *phoneBook, int size) {
    printf("\nPhone Book Contacts:\n\n");

    for(int i = 0; i < size; i++) {
        printf("%s %s\nPhone Number: %s\n\n", phoneBook[i].firstName, phoneBook[i].lastName, phoneBook[i].phoneNumber);
    }
}

int main() {
    struct Contact *phoneBook;
    int size = 0, index = 0;
    char choice;

    printf("Welcome to the Surrealist Phone Book!\n");

    // Allocate memory for initial contact
    phoneBook = (struct Contact *) malloc(sizeof(struct Contact));

    if(!phoneBook) {
        printf("\nMemory allocation failed!\n");
        exit(1);
    }

    do {
        // Display menu options
        printf("\nMenu Options:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display all Contacts\n");
        printf("4. Exit\n\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        // Switch statement for menu options
        switch(choice) {
            case '1': // Add contact
                index++; // Increase index value for new contact
                size++; // Increase size of phone book
                phoneBook = (struct Contact *) realloc(phoneBook, (size * sizeof(struct Contact))); // Reallocate memory for new contact

                if(!phoneBook) {
                    printf("\nMemory reallocation failed!\n");
                    exit(1);
                }

                addContact(phoneBook, index - 1);
                break;

            case '2': // Search contact
                searchContact(phoneBook, size);
                break;

            case '3': // Display all contacts
                displayContacts(phoneBook, size);
                break;

            case '4': // Exit program
                printf("\nThank you for using the Surrealist Phone Book!\n");
                exit(0);

            default: // Invalid input
                printf("\nInvalid input. Try again.\n");
                break;
        }
    } while(1);

    // Free allocated memory
    free(phoneBook);

    return 0;
}