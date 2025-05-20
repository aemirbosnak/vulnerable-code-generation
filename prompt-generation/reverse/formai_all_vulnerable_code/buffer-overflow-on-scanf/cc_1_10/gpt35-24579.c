//FormAI DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a structure to hold contact information
struct Contact {
    char name[50];
    char phone[11];
    char email[50];
};

// function to add a contact to the phone book
void addContact(struct Contact phoneBook[], int* size) {
    // prompt user to enter contact info
    printf("Enter the name of the contact: ");
    scanf("%s", phoneBook[*size].name);
    printf("Enter the phone number of the contact: ");
    scanf("%s", phoneBook[*size].phone);
    printf("Enter the email address of the contact: ");
    scanf("%s", phoneBook[*size].email);

    // increment the size of the phone book
    (*size)++;
}

// function to search for a contact in the phone book
void searchContact(struct Contact phoneBook[], int size) {
    // prompt user to enter the name of the contact to search for
    char searchName[50];
    printf("Enter the name of the contact to search for: ");
    scanf("%s", searchName);

    // search for the contact in the phone book
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            // if contact is found, print its information and return
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone number: %s\n", phoneBook[i].phone);
            printf("Email address: %s\n", phoneBook[i].email);
            return;
        }
    }

    // if contact is not found, print a message
    printf("Contact not found.\n");
}

int main() {
    // initialize the phone book array and size counter
    struct Contact phoneBook[100];
    int size = 0;

    // display the main menu options
    char choice;
    do {
        printf("\nWelcome to the Phone Book!\n");
        printf("Please choose an option:\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf(" %c", &choice);

        // call the appropriate function based on user choice
        switch (choice) {
            case '1':
                addContact(phoneBook, &size);
                break;
            case '2':
                searchContact(phoneBook, size);
                break;
            case '3':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != '3');

    return 0;
}