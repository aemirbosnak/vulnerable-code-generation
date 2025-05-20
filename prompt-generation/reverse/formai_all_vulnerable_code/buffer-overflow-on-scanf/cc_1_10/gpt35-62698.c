//FormAI DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for diary entry
struct DiaryEntry {
    int day;
    int month;
    int year;
    char event[256];
    char entry[1024];
};

// Declare function for adding a new entry to the diary
void addEntry(struct DiaryEntry* entries, int numEntries);

// Declare function for displaying entries in the diary
void displayEntries(struct DiaryEntry* entries, int numEntries);

int main() {
    // Create an array to store diary entries
    struct DiaryEntry entries[100];
    int numEntries = 0;

    // Display welcome message
    printf("Greetings traveler!\n");
    printf("This is your digital diary, designed to keep track of all your medieval adventures.\n");

    // Loop to display options for user
    while(1) {
        // Display options for user
        printf("\nWhat would you like to do today?\n");
        printf("1. Add a new entry\n");
        printf("2. Display existing entries\n");
        printf("3. Exit the program\n");
        printf("Please enter the number of your choice: ");

        // Read in user input for menu selection
        int choice;
        scanf("%d", &choice);

        // Handle menu selection
        switch(choice) {
            case 1:
                // Add a new entry to the diary
                addEntry(entries, numEntries);
                numEntries++;
                break;
            case 2:
                // Display existing entries in the diary
                displayEntries(entries, numEntries);
                break;
            case 3:
                // Exit the program
                printf("Farewell adventurer!\n");
                return 0;
            default:
                // Handle invalid input
                printf("I'm sorry, I don't recognize that command. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function for adding a new entry to the diary
void addEntry(struct DiaryEntry* entries, int numEntries) {
    // Create a new entry
    struct DiaryEntry newEntry;
    printf("\nPlease enter the date of your entry (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &newEntry.day, &newEntry.month, &newEntry.year);
    printf("Please describe the event: ");
    fgets(newEntry.event, 256, stdin);
    printf("Please write your entry: ");
    fgets(newEntry.entry, 1024, stdin);

    // Add the new entry to the array of entries
    entries[numEntries] = newEntry;

    // Confirm to user that entry was added successfully
    printf("Entry added successfully!\n");
}

// Function for displaying existing entries in the diary
void displayEntries(struct DiaryEntry* entries, int numEntries) {
    // Check if there are any entries in the diary
    if(numEntries == 0) {
        printf("There are no entries in your diary yet!\n");
        return;
    }

    // Display all existing entries
    printf("\nHere are your existing entries:\n");
    for(int i = 0; i < numEntries; i++) {
        printf("Entry %d: %02d/%02d/%04d - %s\n", i+1, entries[i].day, entries[i].month, entries[i].year, entries[i].event);
        printf("%s\n", entries[i].entry);
    }
}