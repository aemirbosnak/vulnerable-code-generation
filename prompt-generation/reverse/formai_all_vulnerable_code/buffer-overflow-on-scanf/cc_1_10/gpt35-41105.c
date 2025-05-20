//FormAI DATASET v1.0 Category: Phone Book ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a structure for each contact
typedef struct {
    char name[50];
    char phone[20];
} Contact;

// Function to create a new contact and add it to the phone book
void addContact(Contact *phoneBook, int *size) {
    printf("Enter name: ");
    scanf("%s", phoneBook[*size].name);
    printf("Enter phone number: ");
    scanf("%s", phoneBook[*size].phone);
    (*size)++;
}

// Function to print out all the contacts in the phone book
void printContacts(Contact *phoneBook, int size) {
    printf("Contacts:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

int main() {
    Contact phoneBook[100];
    int size = 0;

    printf("Welcome to your phone book!\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add a contact\n");
        printf("2. Print contacts\n");
        printf("3. Exit\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                addContact(phoneBook, &size);
                break;
            case 2:
                printContacts(phoneBook, size);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}