//FormAI DATASET v1.0 Category: Phone Book ; Style: Alan Touring
// Unique Phone Book Example Program in Alan Turing Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char number[20];
};

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    // Display menu
    printf("Welcome to the Phone Book, please select an option:\n");
    printf("1. Add new contact\n");
    printf("2. View existing contacts\n");
    printf("3. Search contacts\n");
    printf("4. Exit Phone Book\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Add new contact
            if (num_contacts == MAX_CONTACTS) {
                printf("Phone Book full, cannot add new contacts.\n");
            } else {
                printf("Enter name: ");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter number: ");
                scanf("%s", contacts[num_contacts].number);
                num_contacts++;
                printf("Contact added successfully.\n");
            }
            break;

        case 2:
            // View existing contacts
            if (num_contacts == 0) {
                printf("Phone Book empty, no contacts to display.\n");
            } else {
                printf("Here are your existing contacts:\n");
                for (int i = 0; i < num_contacts; i++) {
                    printf("%s: %s\n", contacts[i].name, contacts[i].number);
                }
            }
            break;

        case 3:
            // Search contacts
            if (num_contacts == 0) {
                printf("Phone Book empty, no contacts to search for.\n");
            } else {
                char name[50];
                printf("Enter name to search for: ");
                scanf("%s", name);
                int found = 0;
                for (int i = 0; i < num_contacts; i++) {
                    if (strcmp(name, contacts[i].name) == 0) {
                        printf("%s: %s\n", contacts[i].name, contacts[i].number);
                        found = 1;
                    }
                }
                if (found == 0) {
                    printf("No matching contacts found.\n");
                }
            }
            break;

        case 4:
            // Exit Phone Book
            printf("Exiting Phone Book... goodbye!\n");
            exit(0);
            break;

        default:
            printf("Invalid choice, please select a valid option.\n");
            break;
    }

    // Prompt user to continue or exit
    printf("Would you like to continue using the Phone Book? (y/n)\n");

    char continue_choice;
    scanf(" %c", &continue_choice);

    if (continue_choice == 'y' || continue_choice == 'Y') {
        main();
    } else {
        printf("Exiting Phone Book... goodbye!\n");
        exit(0);
    }

    return 0;
}