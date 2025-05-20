//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store contact information
struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

// Function to add a contact to the phone book
void addContact(struct Contact *phoneBook, int *size, int *capacity) {
    // If the phone book is full, reallocate memory
    if (*size == *capacity) {
        *capacity *= 2;
        phoneBook = realloc(phoneBook, *capacity * sizeof(struct Contact));
    }

    // Prompt user for contact information
    printf("Enter name: ");
    scanf("%s", phoneBook[*size].name);
    printf("Enter phone: ");
    scanf("%s", phoneBook[*size].phone);
    printf("Enter email: ");
    scanf("%s", phoneBook[*size].email);

    // Increment size of phone book
    (*size)++;
}

// Function to search for a contact in the phone book
void searchContact(struct Contact *phoneBook, int size, char *name) {
    // Loop through phone book and search for matching name
    for (int i = 0; i < size; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone: %s\n", phoneBook[i].phone);
            printf("Email: %s\n", phoneBook[i].email);
            return;
        }
    }

    // If no matching name is found, print error message
    printf("Contact not found\n");
}

int main() {
    // Initialize phone book variables
    struct Contact *phoneBook = malloc(10 * sizeof(struct Contact));
    int size = 0;
    int capacity = 10;

    // Add contacts to phone book
    addContact(phoneBook, &size, &capacity);
    addContact(phoneBook, &size, &capacity);
    addContact(phoneBook, &size, &capacity);

    // Search for a contact in the phone book
    searchContact(phoneBook, size, "John Doe");

    // Free memory allocated for phone book
    free(phoneBook);

    return 0;
}