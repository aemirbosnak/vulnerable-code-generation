//FormAI DATASET v1.0 Category: Mailing list manager ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_ENTRIES 100

// Define a struct for each entry in the mailing list
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} MailingEntry;

// Define global variables for the mailing list and the number of entries
MailingEntry mailingList[MAX_ENTRIES];
int numEntries = 0;

// Define function to add an entry to the mailing list
void addEntry() {
    // If the mailing list is full, print a message and exit the function
    if (numEntries == MAX_ENTRIES) {
        printf("Sorry, the mailing list is full!\n");
        return;
    }

    // Otherwise, prompt the user to enter a name and email address
    printf("Please enter a name: ");
    fgets(mailingList[numEntries].name, MAX_NAME_LENGTH, stdin);
    printf("Please enter an email address: ");
    fgets(mailingList[numEntries].email, MAX_EMAIL_LENGTH, stdin);

    // Increment the count of entries
    numEntries++;

    printf("Entry added successfully!\n");
}

// Define function to print all entries in the mailing list
void printList() {
    // If there are no entries, print a message and exit the function
    if (numEntries == 0) {
        printf("The mailing list is empty!\n");
        return;
    }

    // Otherwise, loop through all entries and print them
    printf("Mailing list:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("Name: %sEmail: %s\n", mailingList[i].name, mailingList[i].email);
    }
}

// Define function to remove an entry from the mailing list
void removeEntry() {
    // If there are no entries, print a message and exit the function
    if (numEntries == 0) {
        printf("The mailing list is empty!\n");
        return;
    }

    // Otherwise, prompt the user to enter the name of the entry to remove
    printf("Please enter the name of the entry to remove: ");
    char name[MAX_NAME_LENGTH];
    fgets(name, MAX_NAME_LENGTH, stdin);

    // Loop through all entries and search for the entry with the given name
    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(mailingList[i].name, name) == 0) {
            // If the entry is found, remove it by shifting all subsequent entries down
            for (int j = i; j < numEntries - 1; j++) {
                strcpy(mailingList[j].name, mailingList[j+1].name);
                strcpy(mailingList[j].email, mailingList[j+1].email);
            }
            // Decrement the count of entries
            numEntries--;
            found = 1;
        }
    }

    if (found) {
        printf("Entry removed successfully!\n");
    } else {
        printf("Entry not found!\n");
    }
}

// Define function to display a menu with options for the user to choose from
void displayMenu() {
    printf("1. Add an entry to the mailing list\n");
    printf("2. Print all entries in the mailing list\n");
    printf("3. Remove an entry from the mailing list\n");
    printf("4. Quit the program\n");
}

// Define main function to run the program
int main() {
    int choice;

    printf("Welcome to the happy mailing list manager!\n");

    do {
        displayMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character from scanf

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                printList();
                break;
            case 3:
                removeEntry();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}