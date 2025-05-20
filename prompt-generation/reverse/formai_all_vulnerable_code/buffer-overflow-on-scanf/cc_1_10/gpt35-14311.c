//FormAI DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100 // Maximum number of contacts allowed in the phone book

// Structure to hold contact information
struct contact {
    char name[50];
    char phone[15];
};

// Function to add a new contact to the phone book
void addContact(struct contact *book, int *size) {
    if (*size >= MAX_CONTACTS) {
        printf("The phone book is full. No more contacts can be added.\n");
        return;
    }
    printf("Enter the name of the contact: ");
    scanf("%s", book[*size].name);
    printf("Enter the phone number of the contact: ");
    scanf("%s", book[*size].phone);
    printf("Contact added successfully.\n");
    (*size)++;
}

// Function to search for a contact by name
void searchContact(struct contact *book, int size) {
    char name[50];
    int found = 0;
    printf("Enter the name of the contact to search for: ");
    scanf("%s", name);
    for (int i = 0; i < size; i++) {
        if (strcmp(name, book[i].name) == 0) {
            printf("Contact found:\nName: %s\nPhone: %s\n", book[i].name, book[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact by name
void deleteContact(struct contact *book, int *size) {
    char name[50];
    int found = 0;
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);
    for (int i = 0; i < *size; i++) {
        if (strcmp(name, book[i].name) == 0) {
            found = 1;
            // Shift all contacts after the deleted contact by one position to the left
            for (int j = i; j < *size - 1; j++) {
                strcpy(book[j].name, book[j+1].name);
                strcpy(book[j].phone, book[j+1].phone);
            }
            // Clear the last contact
            strcpy(book[*size-1].name, "");
            strcpy(book[*size-1].phone, "");
            *size--;
            break;
        }
    }
    if (found) {
        printf("Contact deleted successfully.\n");
    } else {
        printf("Contact not found.\n");
    }
}

int main() {
    struct contact phoneBook[MAX_CONTACTS]; // Array to hold all the contacts
    int size = 0; // Size of the phone book
    int choice = 0;

    printf("Welcome to the C Phone Book!\n");

    do {
        printf("\nMain Menu:\n");
        printf("1. Add a new contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete a contact\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(phoneBook, &size);
                break;
            case 2:
                searchContact(phoneBook, size);
                break;
            case 3:
                deleteContact(phoneBook, &size);
                break;
            case 4:
                printf("Thank you for using C Phone Book!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1-4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}