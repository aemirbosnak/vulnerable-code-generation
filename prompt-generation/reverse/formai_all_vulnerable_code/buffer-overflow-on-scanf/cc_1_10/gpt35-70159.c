//FormAI DATASET v1.0 Category: Digital Diary ; Style: calm
// Digital Diary Example Program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a struct to store each entry in the diary
typedef struct {
    int year;
    int month;
    int day;
    char entry[1000];
} DiaryEntry;

// Main function
int main() {
    DiaryEntry* entries = NULL;
    int numEntries = 0;

    // Display welcome message and options to user
    printf("Welcome to your digital diary!\n");
    printf("Enter 'a' to add a new entry or 'v' to view existing entries:\n");

    // Infinite loop until user chooses to exit
    while (1) {

        // Get user input
        char choice;
        scanf(" %c", &choice);

        // Add new entry
        if (choice == 'a') {

            // Increment number of entries and reallocate memory
            numEntries++;
            entries = realloc(entries, numEntries * sizeof(DiaryEntry));

            // Get date and entry from user
            printf("Enter the year, month, and day (separated by spaces) of the entry:\n");
            scanf("%d %d %d", &entries[numEntries-1].year, &entries[numEntries-1].month, &entries[numEntries-1].day);
            printf("Enter your entry:\n ");
            scanf(" %[^\n]", entries[numEntries-1].entry);

            // Success message
            printf("Entry added successfully!\n");
            printf("Enter 'a' to add another entry or 'v' to view existing entries:\n");
        }

        // View existing entries
        else if (choice == 'v') {

            // Check if any entries exist
            if (numEntries == 0) {
                printf("You have no existing entries.\n");
                printf("Enter 'a' to add a new entry or 'v' to view existing entries:\n");
                continue;
            }

            // Display entries
            printf("You have %d existing entries:\n", numEntries);
            for (int i = 0; i < numEntries; i++) {
                printf("%04d-%02d-%02d: %s\n", entries[i].year, entries[i].month, entries[i].day, entries[i].entry);
            }

            // Prompt user to make another choice
            printf("Enter 'a' to add a new entry or 'v' to view existing entries or 'q' to quit:\n");
        }

        // Quit program
        else if (choice == 'q') {
            printf("Thank you for using your digital diary! Goodbye.\n");
            break;
        }

        // Invalid input
        else {
            printf("Invalid choice. Enter 'a' to add a new entry or 'v' to view existing entries or 'q' to quit.\n");
        }
    }

    // Free memory and exit program
    free(entries);
    return 0;
}