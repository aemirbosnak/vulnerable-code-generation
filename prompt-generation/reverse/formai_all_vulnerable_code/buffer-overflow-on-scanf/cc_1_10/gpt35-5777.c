//FormAI DATASET v1.0 Category: Digital Diary ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Defines the maximum length of the diary entry */
#define MAX_ENTRY_LENGTH 500

/* Defines the maximum number of diary entries that can be stored */
#define MAX_ENTRIES 100

/* Declares a struct for the diary entry that contains a timestamp and the entry itself */
struct DiaryEntry {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
};

/* Declares an array to store the diary entries */
struct DiaryEntry entries[MAX_ENTRIES];

/* Declares a counter for the number of entries */
int numEntries = 0;

/* Declares a helper function to print the menu */
void printMenu() {
    printf("Digital Diary\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Quit\n");
}

/* Declares a helper function to add a new entry to the diary */
void addEntry() {
    /* Checks if the maximum number of entries has been reached */
    if (numEntries < MAX_ENTRIES) {
        /* Prompts the user for the diary entry */
        printf("Enter diary entry (%d character limit):\n", MAX_ENTRY_LENGTH);
        char entry[MAX_ENTRY_LENGTH];
        scanf(" %[^\n]", entry);
        /* Adds the entry to the diary */
        entries[numEntries].timestamp = time(NULL);
        strcpy(entries[numEntries].entry, entry);
        numEntries++;
    } else {
        printf("Digital Diary is full\n");
    }
}

/* Declares a helper function to view all entries in the diary */
void viewEntries() {
    /* Prints each entry in the diary */
    for (int i = 0; i < numEntries; i++) {
        struct tm* timeinfo = localtime(&(entries[i].timestamp));
        char timeStr[100];
        strftime(timeStr, sizeof(timeStr), "%c", timeinfo);
        printf("Entry #%d: %s\n%s\n", i+1, timeStr, entries[i].entry);
    }
}

int main() {
    /* Displays the menu and prompts the user for a choice */
    int choice = 0;
    while (choice != 3) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}