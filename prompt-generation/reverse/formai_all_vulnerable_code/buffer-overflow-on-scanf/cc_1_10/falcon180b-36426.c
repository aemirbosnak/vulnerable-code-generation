//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a contact
typedef struct {
    char name[50];
    char phone[15];
} Contact;

// Function to add a contact to the phone book
void addContact(Contact* phoneBook, int size, int* numContacts, char* name, char* phone) {
    // Check if the phone book is full
    if (*numContacts >= size) {
        printf("Phone book is full.\n");
        return;
    }

    // Add the contact to the phone book
    strcpy(phoneBook[*numContacts].name, name);
    strcpy(phoneBook[*numContacts].phone, phone);
    (*numContacts)++;
}

// Function to search for a contact in the phone book
int searchContact(Contact* phoneBook, int size, int numContacts, char* name) {
    // Search for the contact in the phone book
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            // Contact found
            return i;
        }
    }

    // Contact not found
    return -1;
}

// Function to display the phone book
void displayPhoneBook(Contact* phoneBook, int size, int numContacts) {
    // Display the contacts in the phone book
    printf("Phone Book:\n");
    printf("=================\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%s - %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

// Main function
int main() {
    // Initialize variables
    Contact phoneBook[100];
    int numContacts = 0;

    // Get user input
    char name[50];
    char phone[15];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    // Add the contact to the phone book
    addContact(phoneBook, 100, &numContacts, name, phone);

    // Display the phone book
    displayPhoneBook(phoneBook, 100, numContacts);

    return 0;
}