//FormAI DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for each entry in the phone book
typedef struct {
    char name[50];
    char number[20];
} entry;

// Function to display the entire phone book
void displayPhoneBook(entry phoneBook[], int numEntries) {
    printf("Phone Book:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", phoneBook[i].name, phoneBook[i].number);
    }
    printf("\n");
}

int main() {
    int numEntries = 0; // Keep track of how many entries are in the phone book
    entry phoneBook[100]; // Array of entries (max 100 entries)

    // Display the welcome message and menu
    printf("Welcome to the C Phone Book!\n\n");
    printf("What would you like to do?\n");
    printf("1. Add an entry\n");
    printf("2. Search for an entry\n");
    printf("3. Display phone book\n");
    printf("4. Quit\n");

    // Loop through menu options until the user quits
    int choice = 0;
    while (choice != 4) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Add an entry
            printf("\nEnter the name: ");
            scanf("%s", phoneBook[numEntries].name);

            printf("Enter the phone number: ");
            scanf("%s", phoneBook[numEntries].number);

            printf("%s's phone number (%s) has been added to the phone book!\n", phoneBook[numEntries].name, phoneBook[numEntries].number);
            numEntries++;
        }
        else if (choice == 2) {
            // Search for an entry
            char searchName[50];
            printf("\nEnter the name to search for: ");
            scanf("%s", searchName);

            // Loop through all entries in the phone book and check if the name matches
            int found = 0;
            for (int i = 0; i < numEntries; i++) {
                if (strcmp(phoneBook[i].name, searchName) == 0) {
                    printf("\n%s's phone number is %s\n", searchName, phoneBook[i].number);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("\n%s was not found in the phone book\n", searchName);
            }
        }
        else if (choice == 3) {
            // Display the entire phone book
            displayPhoneBook(phoneBook, numEntries);
        }
        else if (choice != 4) { // choice == 4 means the user wants to quit
            printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}