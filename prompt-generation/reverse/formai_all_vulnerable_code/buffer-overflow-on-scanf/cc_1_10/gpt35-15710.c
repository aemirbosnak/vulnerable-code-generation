//FormAI DATASET v1.0 Category: Digital Diary ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 10

// Define a struct to store a single diary entry
typedef struct DiaryEntry {
    char date[11];
    char entry[100];
} DiaryEntry;

int numEntries = 0;
DiaryEntry diary[MAX_ENTRIES];

// Function to add a new entry to the diary
void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Sorry, the diary is full.\n");
        return;
    }

    DiaryEntry newEntry;

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newEntry.date);

    printf("Enter entry: \n");
    getchar(); // Clear the input buffer
    fgets(newEntry.entry, 100, stdin); // Allow for longer entries

    diary[numEntries++] = newEntry;
    printf("Entry added successfully!\n");
}

// Function to display all entries in the diary
void viewEntries() {
    if (numEntries == 0) {
        printf("The diary is empty.\n");
        return;
    }

    printf("Here are all the entries in your diary:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }
}

// Function to delete an entry from the diary
void deleteEntry() {
    if (numEntries == 0) {
        printf("The diary is empty.\n");
        return;
    }

    char dateToDelete[11];
    printf("Enter the date of the entry to delete (YYYY-MM-DD): ");
    scanf("%s", dateToDelete);

    int foundIndex = -1;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(diary[i].date, dateToDelete) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("No entry found with that date.\n");
    } else {
        for (int i = foundIndex; i < numEntries - 1; i++) {
            diary[i] = diary[i + 1];
        }
        numEntries--;
        printf("Entry deleted successfully!\n");
    }
}

int main() {
    int userChoice = -1;

    printf("Welcome to your digital diary!\n");
    while (userChoice != 0) {
        printf("\nPlease choose an option:\n");
        printf("1. Add new entry\n");
        printf("2. View all entries\n");
        printf("3. Delete an entry\n");
        printf("0. Quit\n");

        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 0:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}