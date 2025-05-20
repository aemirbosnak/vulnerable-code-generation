//FormAI DATASET v1.0 Category: Phone Book ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100 // Maximum number of contacts that can be stored

// Structure to hold contact information
struct Contact {
    char name[40];
    char phone[15];
};

// Function to add a contact
int addContact(struct Contact list[], int count) {
    if (count < MAX_CONTACTS) {
        printf("\nEnter name: ");
        scanf("%s", list[count].name);
        printf("Enter phone: ");
        scanf("%s", list[count].phone);
        printf("Contact added successfully!\n");
        count++;
    } else {
        printf("\nSorry, the phone book is full.\n");
    }
    return count;
}

// Function to search for a contact by name
void searchContact(struct Contact list[], int count) {
    char name[40];
    printf("\nEnter name to search for: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].name, name) == 0) {
            printf("\n%s - %s\n", list[i].name, list[i].phone);
            return;
        }
    }
    printf("\nContact not found.\n");
}

// Function to display all contacts
void displayContacts(struct Contact list[], int count) {
    printf("\nContacts:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", list[i].name, list[i].phone);
    }
}

int main() {
    int count = 0; // Number of contacts currently stored
    struct Contact list[MAX_CONTACTS]; // Array to hold contacts

    printf("Welcome to the Phone Book program!\n");

    // Loop to prompt user for options and act accordingly
    while (1) {
        int choice;
        printf("\nWhat would you like to do?\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact by name\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count = addContact(list, count);
                break;
            case 2:
                searchContact(list, count);
                break;
            case 3:
                displayContacts(list, count);
                break;
            case 4:
                printf("\nThank you for using the Phone Book program!\n");
                return 0;
            default:
                printf("\nInvalid choice.\n");
        }
    }
}