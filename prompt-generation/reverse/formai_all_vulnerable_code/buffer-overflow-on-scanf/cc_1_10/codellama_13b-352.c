//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: automated
/*
 * Phone Book
 *
 * A simple phone book program that allows users to add, delete, and search for contacts.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store contact information
typedef struct {
    char name[50];
    char phone[20];
} Contact;

// Function to add a new contact to the phone book
void addContact(Contact *phoneBook, int *size) {
    Contact newContact;
    printf("Enter the name of the new contact: ");
    scanf("%s", newContact.name);
    printf("Enter the phone number of the new contact: ");
    scanf("%s", newContact.phone);
    phoneBook[*size] = newContact;
    *size += 1;
}

// Function to delete a contact from the phone book
void deleteContact(Contact *phoneBook, int *size, char *name) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            phoneBook[i] = phoneBook[*size - 1];
            *size -= 1;
            break;
        }
    }
}

// Function to search for a contact in the phone book
void searchContact(Contact *phoneBook, int *size, char *name) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            break;
        }
    }
}

int main() {
    Contact phoneBook[100];
    int size = 0;
    char choice;
    char name[50];

    while (1) {
        printf("Phone Book\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                addContact(phoneBook, &size);
                break;
            case '2':
                printf("Enter the name of the contact to delete: ");
                scanf("%s", name);
                deleteContact(phoneBook, &size, name);
                break;
            case '3':
                printf("Enter the name of the contact to search for: ");
                scanf("%s", name);
                searchContact(phoneBook, &size, name);
                break;
            case '4':
                return 0;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}