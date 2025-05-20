//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts
#define MAX_CONTACTS 100

// Define the structure for a contact
typedef struct {
    char name[50];
    char phone[15];
} contact;

// Function to add a new contact
void add_contact(contact *book, int *count, char *name, char *phone) {
    // Check if the book is full
    if (*count >= MAX_CONTACTS) {
        printf("Sorry, the phone book is full!\n");
        return;
    }

    // Copy the name and phone number to the book
    strcpy(book[*count].name, name);
    strcpy(book[*count].phone, phone);

    // Increment the contact count
    (*count)++;
}

// Function to search for a contact
int search_contact(contact *book, int count, char *name) {
    // Loop through the contacts
    for (int i = 0; i < count; i++) {
        // Compare the names
        if (strcmp(book[i].name, name) == 0) {
            // Print the contact information
            printf("Name: %s\nPhone: %s\n", book[i].name, book[i].phone);
            return i;
        }
    }

    // Contact not found
    return -1;
}

// Main function
int main() {
    // Initialize the phone book
    contact book[MAX_CONTACTS];
    int count = 0;

    // Add some contacts
    add_contact(&book, &count, "Alice", "123-4567");
    add_contact(&book, &count, "Bob", "987-6543");
    add_contact(&book, &count, "Charlie", "555-4321");

    // Search for a contact
    char name[50];
    printf("Enter a name to search for: ");
    scanf("%s", name);

    int index = search_contact(&book, count, name);

    if (index!= -1) {
        printf("Contact found at index %d\n", index);
    } else {
        printf("Contact not found\n");
    }

    return 0;
}