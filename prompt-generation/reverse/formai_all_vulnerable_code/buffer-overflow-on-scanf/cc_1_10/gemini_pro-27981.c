//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure to store a single entry in the diary
typedef struct {
    char date[11];
    char time[9];
    char entry[1024];
} Entry;

// Array to store all the entries in the diary
Entry entries[100];

// Current number of entries in the diary
int numEntries = 0;

// Function to add a new entry to the diary
void addEntry() {
    // Get the current date and time
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(entries[numEntries].date, sizeof(entries[numEntries].date), "%Y-%m-%d", tm);
    strftime(entries[numEntries].time, sizeof(entries[numEntries].time), "%H:%M:%S", tm);

    // Get the entry text from the user
    printf("Enter your entry: ");
    fgets(entries[numEntries].entry, sizeof(entries[numEntries].entry), stdin);

    // Increment the number of entries
    numEntries++;
}

// Function to print all the entries in the diary
void printEntries() {
    for (int i = 0; i < numEntries; i++) {
        printf("%s %s\n", entries[i].date, entries[i].time);
        printf("%s\n\n", entries[i].entry);
    }
}

// Function to search the diary for a specific entry
void searchEntries() {
    char searchTerm[100];

    // Get the search term from the user
    printf("Enter your search term: ");
    fgets(searchTerm, sizeof(searchTerm), stdin);

    // Search the diary for the search term
    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].entry, searchTerm) != NULL) {
            printf("%s %s\n", entries[i].date, entries[i].time);
            printf("%s\n\n", entries[i].entry);
        }
    }
}

// Main function
int main() {
    // Welcome the user
    printf("Welcome to your digital diary!\n");

    // Loop until the user quits
    while (1) {
        // Display the menu
        printf("\n1. Add an entry\n2. Print all entries\n3. Search entries\n4. Quit\n");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                printEntries();
                break;
            case 3:
                searchEntries();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}