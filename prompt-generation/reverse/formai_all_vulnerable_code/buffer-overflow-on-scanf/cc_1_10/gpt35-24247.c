//FormAI DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold phone book entry
struct PhoneEntry {
    char name[50];
    char phoneNum[20];
};

// Function to add a new entry to the phone book
void addNewEntry(struct PhoneEntry phoneBook[], int *size) {
    // Prompt user for name and phone number
    printf("Enter name: ");
    scanf("%s", phoneBook[*size].name);
    printf("Enter phone number: ");
    scanf("%s", phoneBook[*size].phoneNum);
    // Increment size of phone book
    (*size)++;
}

// Function to search for a phone number in the phone book
void searchEntry(struct PhoneEntry phoneBook[], int size) {
    // Prompt user for name to search
    char nameToSearch[50];
    printf("Enter name to search: ");
    scanf("%s", nameToSearch);
    // Loop through phone book to find matching entry
    for (int i = 0; i < size; i++) {
        if (strcmp(phoneBook[i].name, nameToSearch) == 0) {
            printf("Phone number for %s: %s\n", nameToSearch, phoneBook[i].phoneNum);
            return;
        }
    }
    // If entry not found, print error message
    printf("No entry found for %s\n", nameToSearch);
}

// Function to display all entries in the phone book
void displayAllEntries(struct PhoneEntry phoneBook[], int size) {
    // Print header for table
    printf("\n%-20s %-20s\n", "Name", "Phone Number");
    for (int i = 0; i < 40; i++) {
        printf("-");
    }
    printf("\n");
    // Loop through phone book to print each entry
    for (int i = 0; i < size; i++) {
        printf("%-20s %-20s\n", phoneBook[i].name, phoneBook[i].phoneNum);
    }
}

int main() {
    // Initialize phone book
    struct PhoneEntry phoneBook[100];
    int size = 0;
    // Display menu and prompt user for choice
    int choice = 0;
    do {
        printf("\nPhone Book Menu\n");
        printf("1. Add new entry\n");
        printf("2. Search for phone number\n");
        printf("3. Display all entries\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        // Call appropriate function based on user choice
        switch (choice) {
            case 1:
                addNewEntry(phoneBook, &size);
                break;
            case 2:
                searchEntry(phoneBook, size);
                break;
            case 3:
                displayAllEntries(phoneBook, size);
                break;
            case 4:
                printf("Exiting phone book.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}