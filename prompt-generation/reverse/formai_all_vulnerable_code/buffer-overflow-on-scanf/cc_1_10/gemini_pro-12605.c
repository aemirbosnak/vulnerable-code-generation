//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
typedef struct Contact {
    char name[50];
    char number[20];
} Contact;

// Function to add a contact to the phone book
void addContact(Contact *phoneBook, int *count) {
    printf("Enter the name of the contact: ");
    scanf(" %[^\n]", phoneBook[*count].name);
    printf("Enter the phone number of the contact: ");
    scanf(" %s", phoneBook[*count].number);
    (*count)++;
}

// Function to search for a contact in the phone book
void searchContact(Contact *phoneBook, int count) {
    char name[50];
    printf("Enter the name of the contact you want to search: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone number: %s\n", phoneBook[i].number);
            return;
        }
    }
    printf("Contact not found.\n");
}

// Function to print the phone book
void printPhoneBook(Contact *phoneBook, int count) {
    printf("Phone book:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", phoneBook[i].name, phoneBook[i].number);
    }
}

int main() {
    // Create a phone book with a maximum capacity of 100 contacts
    Contact phoneBook[100];

    // Initialize the count of contacts to 0
    int count = 0;

    // Add contacts to the phone book
    while (1) {
        int choice;
        printf("Enter your choice:\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Print the phone book\n");
        printf("4. Exit\n");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                addContact(phoneBook, &count);
                break;
            case 2:
                searchContact(phoneBook, count);
                break;
            case 3:
                printPhoneBook(phoneBook, count);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}