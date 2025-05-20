//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: future-proof
/*
 * Phone Book
 *
 * This program allows users to add, search, and delete contacts from a phone book.
 * It uses a future-proof approach to ensure that the program is able to handle large amounts of data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a contact
typedef struct {
    char name[50];
    char phone[20];
} Contact;

// Function to add a contact to the phone book
void addContact(Contact *phoneBook, int *numContacts) {
    printf("Enter the name of the contact: ");
    scanf("%s", &phoneBook[*numContacts].name);
    printf("Enter the phone number of the contact: ");
    scanf("%s", &phoneBook[*numContacts].phone);
    (*numContacts)++;
}

// Function to search for a contact in the phone book
void searchContact(Contact *phoneBook, int numContacts) {
    char name[50];
    printf("Enter the name of the contact to search for: ");
    scanf("%s", &name);
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("The contact %s has the phone number %s.\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("The contact %s was not found in the phone book.\n", name);
}

// Function to delete a contact from the phone book
void deleteContact(Contact *phoneBook, int *numContacts) {
    char name[50];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", &name);
    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < *numContacts; j++) {
                phoneBook[j] = phoneBook[j+1];
            }
            (*numContacts)--;
            return;
        }
    }
    printf("The contact %s was not found in the phone book.\n", name);
}

int main() {
    int numContacts = 0;
    Contact phoneBook[100];

    char option;
    do {
        printf("Phone Book\n");
        printf("---------\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete a contact\n");
        printf("4. Quit\n");
        printf("Enter your option: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                addContact(phoneBook, &numContacts);
                break;
            case '2':
                searchContact(phoneBook, numContacts);
                break;
            case '3':
                deleteContact(phoneBook, &numContacts);
                break;
            case '4':
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option != '4');

    return 0;
}