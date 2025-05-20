//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the structure of a diary entry
typedef struct {
    char date[11];
    char title[31];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

// Define the diary itself
DiaryEntry diary[MAX_ENTRIES];

// Define the current number of diary entries
int numEntries = 0;

// Function to add a new diary entry
void addEntry() {
    // Get the date, title, and entry from the user
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", diary[numEntries].date);
    printf("Enter the title: ");
    scanf("%s", diary[numEntries].title);
    printf("Enter the entry: ");
    scanf("%s", diary[numEntries].entry);

    // Increment the number of diary entries
    numEntries++;
}

// Function to view a diary entry
void viewEntry() {
    // Get the index of the entry to view
    int index;
    printf("Enter the index of the entry to view: ");
    scanf("%d", &index);

    // Check if the index is valid
    if (index < 0 || index >= numEntries) {
        printf("Invalid index.\n");
        return;
    }

    // Print the entry
    printf("Date: %s\n", diary[index].date);
    printf("Title: %s\n", diary[index].title);
    printf("Entry: %s\n", diary[index].entry);
}

// Function to edit a diary entry
void editEntry() {
    // Get the index of the entry to edit
    int index;
    printf("Enter the index of the entry to edit: ");
    scanf("%d", &index);

    // Check if the index is valid
    if (index < 0 || index >= numEntries) {
        printf("Invalid index.\n");
        return;
    }

    // Get the new date, title, and entry from the user
    printf("Enter the new date (YYYY-MM-DD): ");
    scanf("%s", diary[index].date);
    printf("Enter the new title: ");
    scanf("%s", diary[index].title);
    printf("Enter the new entry: ");
    scanf("%s", diary[index].entry);
}

// Function to delete a diary entry
void deleteEntry() {
    // Get the index of the entry to delete
    int index;
    printf("Enter the index of the entry to delete: ");
    scanf("%d", &index);

    // Check if the index is valid
    if (index < 0 || index >= numEntries) {
        printf("Invalid index.\n");
        return;
    }

    // Shift all the entries after the deleted entry to the left
    for (int i = index; i < numEntries - 1; i++) {
        diary[i] = diary[i + 1];
    }

    // Decrement the number of diary entries
    numEntries--;
}

// Function to search a diary entry by date
void searchEntryByDate() {
    // Get the date to search for
    char date[11];
    printf("Enter the date to search for (YYYY-MM-DD): ");
    scanf("%s", date);

    // Search for the entry
    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            // Print the entry
            printf("Date: %s\n", diary[i].date);
            printf("Title: %s\n", diary[i].title);
            printf("Entry: %s\n", diary[i].entry);
            found = 1;
        }
    }

    // If the entry was not found, print an error message
    if (!found) {
        printf("No entry found for that date.\n");
    }
}

// Function to search a diary entry by title
void searchEntryByTitle() {
    // Get the title to search for
    char title[31];
    printf("Enter the title to search for: ");
    scanf("%s", title);

    // Search for the entry
    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(diary[i].title, title) == 0) {
            // Print the entry
            printf("Date: %s\n", diary[i].date);
            printf("Title: %s\n", diary[i].title);
            printf("Entry: %s\n", diary[i].entry);
            found = 1;
        }
    }

    // If the entry was not found, print an error message
    if (!found) {
        printf("No entry found for that title.\n");
    }
}

// Function to print the menu
void printMenu() {
    printf("\n");
    printf("1. Add a new entry\n");
    printf("2. View an entry\n");
    printf("3. Edit an entry\n");
    printf("4. Delete an entry\n");
    printf("5. Search an entry by date\n");
    printf("6. Search an entry by title\n");
    printf("7. Quit\n");
    printf("\n");
    printf("Enter your choice: ");
}

// Function to get the user's choice
int getChoice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Main function
int main() {
    // Print the welcome message
    printf("Welcome to your digital diary!\n");

    // Loop until the user quits
    int choice;
    do {
        // Print the menu
        printMenu();

        // Get the user's choice
        choice = getChoice();

        // Perform the selected action
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntry();
                break;
            case 3:
                editEntry();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                searchEntryByDate();
                break;
            case 6:
                searchEntryByTitle();
                break;
            case 7:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}