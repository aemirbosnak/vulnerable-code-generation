//FormAI DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 365 // Maximum entries per year

typedef struct {
    char date[11]; // Date format = YYYY/MM/DD
    char entry[1000]; // Maximum of 1000 characters per entry
} DiaryEntry;

int main() {

    DiaryEntry entries[MAX_ENTRIES]; // Array to store diary entries
    int numEntries = 0; // Counter for number of entries

    int option = 0; // User input option

    // Display welcome message
    printf("Welcome to my Digital Diary\n");
    printf("===============================================\n");

    // Loop until user exits
    while (option != 3) {
        // Display menu options
        printf("Please select from the following options:\n");
        printf("1. Add an entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                if (numEntries == MAX_ENTRIES) {
                    printf("Maximum diary entries reached for the year. Please create a new diary for the next year.\n");
                    break;
                }
                // Prompt user for date and entry
                printf("Please enter the date for the new entry (YYYY/MM/DD): ");
                scanf("%s", entries[numEntries].date);
                printf("Please enter your entry for %s: ", entries[numEntries].date);
                scanf("%s", entries[numEntries].entry);
                numEntries++;
                printf("Entry added successfully.\n");
                break;
            case 2:
                if (numEntries == 0) {
                    printf("No entries to display.\n");
                    break;
                }
                // Display all entries
                printf("All diary entries:\n");
                for (int i = 0; i < numEntries; i++) {
                    printf("Date: %s\n", entries[i].date);
                    printf("Entry: %s\n", entries[i].entry);
                    printf("-----------------------------------------------\n");
                }
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option selected. Please try again.\n");
        }
    }

    return 0;
}