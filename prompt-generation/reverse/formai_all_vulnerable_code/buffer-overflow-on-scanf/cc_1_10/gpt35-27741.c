//FormAI DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Struct to store individual contacts
typedef struct {
    char name[30];
    char phone[15];
} Contact;

// Array to store all contacts
Contact phonebook[MAX_CONTACTS];

// Current number of contacts in phonebook
int num_contacts = 0;

// Function to add a contact to the phonebook
void add_contact() {
    // Make sure there is space in the phonebook
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phonebook is already full.\n");
        return;
    }

    // Get contact information from user
    printf("Enter name: ");
    scanf("%s", phonebook[num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", phonebook[num_contacts].phone);

    // Increment number of contacts
    num_contacts++;

    printf("Contact added.\n\n");
}

// Function to remove a contact from the phonebook
void remove_contact() {
    // Make sure there are contacts in the phonebook
    if (num_contacts == 0) {
        printf("Phonebook is empty.\n");
        return;
    }

    // Get contact name from user
    char name[30];
    printf("Enter name of contact to remove: ");
    scanf("%s", name);

    // Find contact in phonebook and remove it
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            int j;
            for (j = i; j < num_contacts - 1; j++) {
                phonebook[j] = phonebook[j+1];
            }
            num_contacts--;
            printf("Contact removed.\n\n");
            return;
        }
    }

    // Contact not found
    printf("Contact not found in phonebook.\n\n");
}

// Function to print all contacts in the phonebook
void print_contacts() {
    // Make sure there are contacts in the phonebook
    if (num_contacts == 0) {
        printf("Phonebook is empty.\n\n");
        return;
    }

    // Print header
    printf("%-30s %-15s\n", "Name", "Phone Number");
    printf("--------------------------------------------\n");

    // Print each contact
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("%-30s %-15s\n", phonebook[i].name, phonebook[i].phone);
    }

    printf("\n");
}

int main() {
    printf("Welcome to the C Phone Book!\n\n");

    while (1) {
        // Print menu
        printf("Please choose an option:\n");
        printf("1) Add contact\n");
        printf("2) Remove contact\n");
        printf("3) Print contacts\n");
        printf("4) Quit program\n\n");

        // Get user choice
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                remove_contact();
                break;
            case 3:
                print_contacts();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}