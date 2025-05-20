//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
// Welcome to Ada's Mailing List Manager program!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of names and emails
#define MAX_LEN 100

// Define struct for each person on the mailing list
typedef struct {
    char name[MAX_LEN];
    char email[MAX_LEN];
} Person;

// Initialize an array of Person structs to store the mailing list
Person contacts[100];

// Function to add a Person to the mailing list
void addPerson(char name[], char email[]) {
    // Determine the size of the current mailing list
    int size = sizeof(contacts) / sizeof(contacts[0]);

    // Find the first empty slot in the mailing list
    int i;
    for (i = 0; i < size; i++) {
        if (strlen(contacts[i].name) == 0) {
            break;
        }
    }

    // Add the new Person to the mailing list in the empty slot
    strcpy(contacts[i].name, name);
    strcpy(contacts[i].email, email);

    printf("Successfully added %s with email %s to the mailing list!\n", name, email);
}

int main() {
    char choice;
    char name[MAX_LEN];
    char email[MAX_LEN];

    // Print out a menu of options for the user
    printf("Welcome to Ada's Mailing List Manager program!\n");
    while (1) {
        printf("\nMENU\n");
        printf("====\n");
        printf("1. Add a person to the mailing list\n");
        printf("2. View the mailing list\n");
        printf("3. Exit the program\n");
        printf("Please enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("\nEnter the person's name: ");
                scanf("%s", name);
                printf("Enter the person's email: ");
                scanf("%s", email);
                addPerson(name, email);
                break;
            case '2':
                printf("\nMAILING LIST\n");
                printf("============\n");
                int size = sizeof(contacts) / sizeof(contacts[0]);
                for (int i = 0; i < size; i++) {
                    if (strlen(contacts[i].name) != 0) {
                        printf("%s - %s\n", contacts[i].name, contacts[i].email);
                    }
                }
                break;
            case '3':
                printf("\nExiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}