//FormAI DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_ENTRIES 100 // Maximum number of diary entries

typedef struct {
    int day;
    int month;
    int year;
    char message[255];
} DiaryEntry; // Structure to hold a single diary entry

int main() {
    DiaryEntry diary[MAX_ENTRIES]; // Array to hold all diary entries
    int numEntries = 0; // Number of entries currently in the array
    char choice = ' '; // Variable to store user's menu choice

    printf("Welcome to your digital diary!\n");

    while (choice != 'Q') { // Continue displaying menu until user chooses to quit
        printf("\nWhat would you like to do?\n");
        printf("A - Add an entry\n");
        printf("V - View all entries\n");
        printf("C - Clear all entries\n");
        printf("Q - Quit\n");

        printf("Your choice: ");
        scanf(" %c", &choice); // Get user's menu choice, ignoring any leading whitespace

        switch (toupper(choice)) { // Convert user's choice to uppercase to simplify comparison
            case 'A': // Add an entry
                if (numEntries >= MAX_ENTRIES) {
                    printf("Error: Diary is full.\n");
                } else {
                    printf("Enter the date for your entry (DD/MM/YYYY): ");
                    scanf("%d/%d/%d", &diary[numEntries].day, &diary[numEntries].month, &diary[numEntries].year); // Get date of entry
                    printf("Enter your message (max 255 characters):\n");
                    getchar(); // Clear input buffer
                    fgets(diary[numEntries].message, 255, stdin); // Get message of entry
                    numEntries++; // Increment number of entries stored
                }
                break;

            case 'V': // View all entries
                if (numEntries == 0) {
                    printf("No entries to display.\n");
                } else {
                    printf("Date       | Message\n");
                    printf("------------------------\n");
                    for (int i = 0; i < numEntries; i++) { // Display all entries in reverse order (most recent first)
                        printf("%02d/%02d/%04d | %s", diary[numEntries - i - 1].day, diary[numEntries - i - 1].month, diary[numEntries - i - 1].year, diary[numEntries - i - 1].message);
                    }
                }
                break;

            case 'C': // Clear all entries
                printf("Are you sure you want to clear all entries? (Y/N): ");
                scanf(" %c", &choice); // Get confirmation from user
                if (toupper(choice) == 'Y') {
                    numEntries = 0; // Reset number of entries stored to zero
                    printf("All entries cleared.\n");
                } else {
                    printf("No entries cleared.\n");
                }
                break;

            case 'Q': // Quit
                printf("Goodbye!\n");
                break;

            default: // Invalid choice
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}