//FormAI DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct contact {
    char name[20];
    char phone_number[12];
};

int num_contacts = 0; // Number of contacts currently stored
struct contact phone_book[MAX_CONTACTS]; // Phone book data structure

// Function prototypes
int add_contact();
int delete_contact();
void search_contact();
void print_phone_book();

int main() {
    char choice;

    printf("Welcome to the C Phone Book!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Search contact\n");
        printf("4. Print phone book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_contact();
                break;
            case '2':
                delete_contact();
                break;
            case '3':
                search_contact();
                break;
            case '4':
                print_phone_book();
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != '5');

    return 0;
}

// Function to add a contact to the phone book
int add_contact() {
    char name[20];
    char phone_number[12];

    if (num_contacts == MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return 0;
    }

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone_number);

    strcpy(phone_book[num_contacts].name, name);
    strcpy(phone_book[num_contacts].phone_number, phone_number);

    printf("Contact added successfully.\n");

    num_contacts++;

    return 1;
}

// Function to delete a contact from the phone book
int delete_contact() {
    char name[20];
    int i, j = -1;

    if (num_contacts == 0) {
        printf("Phone book is empty. Cannot delete any contacts\n");
        return 0;
    }

    printf("Enter name to delete: ");
    scanf("%s", name);

    // Find the contact in the phone book
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            j = i; // Save the index of the contact to be deleted
            break;
        }
    }

    if (j == -1) {
        printf("Contact not found.\n");
        return 0;
    }

    // Shift all contacts after the deleted contact one position to the left
    for (i = j; i < num_contacts - 1; i++) {
        strcpy(phone_book[i].name, phone_book[i + 1].name);
        strcpy(phone_book[i].phone_number, phone_book[i + 1].phone_number);
    }

    num_contacts--;

    printf("Contact deleted successfully.\n");

    return 1;
}

// Function to search for a contact in the phone book
void search_contact() {
    char name[20];
    int i;

    if (num_contacts == 0) {
        printf("Phone book is empty. Cannot search for any contacts.\n");
        return;
    }

    printf("Enter name to search: ");
    scanf("%s", name);

    // Search for the contact in the phone book
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Name: %s\n", phone_book[i].name);
            printf("Phone Number: %s\n", phone_book[i].phone_number);
            return;
        }
    }

    printf("Contact not found.\n");
}

// Function to print the entire phone book
void print_phone_book() {
    int i;

    if (num_contacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Phone Book:\n");

    for (i = 0; i < num_contacts; i++) {
        printf("%d. Name: %s\n", i + 1, phone_book[i].name);
        printf("   Phone Number: %s\n", phone_book[i].phone_number);
    }
}