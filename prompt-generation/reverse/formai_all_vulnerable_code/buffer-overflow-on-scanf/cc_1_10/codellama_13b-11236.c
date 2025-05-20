//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: romantic
/*
 * Romantic Mailing List Manager
 *
 * A program to manage a mailing list for a romantic relationship.
 *
 * Developed by: [Your Name]
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

// Struct to store contact information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

// Function to add a contact to the mailing list
void addContact(Contact *list, int *size) {
    // Prompt user for name and email
    printf("Enter name: ");
    scanf("%s", list[*size].name);
    printf("Enter email: ");
    scanf("%s", list[*size].email);

    // Increment size of list
    (*size)++;
}

// Function to remove a contact from the mailing list
void removeContact(Contact *list, int *size) {
    // Prompt user for name to remove
    printf("Enter name to remove: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    // Find the contact with the given name
    for (int i = 0; i < *size; i++) {
        if (strcmp(list[i].name, name) == 0) {
            // Remove the contact from the list
            for (int j = i; j < *size - 1; j++) {
                list[j] = list[j + 1];
            }
            (*size)--;
            break;
        }
    }
}

// Function to display the mailing list
void displayList(Contact *list, int size) {
    // Print the name and email of each contact
    for (int i = 0; i < size; i++) {
        printf("%s <%s>\n", list[i].name, list[i].email);
    }
}

int main() {
    // Initialize the mailing list
    Contact list[MAX_LIST_SIZE];
    int size = 0;

    // Prompt user for input
    char input;
    do {
        printf("Enter a command (a)dd, (r)emove, or (d)isplay: ");
        scanf(" %c", &input);

        // Add a contact to the list
        if (input == 'a') {
            addContact(list, &size);
        }
        // Remove a contact from the list
        else if (input == 'r') {
            removeContact(list, &size);
        }
        // Display the mailing list
        else if (input == 'd') {
            displayList(list, size);
        }
    } while (input != 'q');

    return 0;
}