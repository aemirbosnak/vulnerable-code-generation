//FormAI DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define max length of entry text
#define MAX_ENTRY_LENGTH 500

// Define struct for diary entry
typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

// Function to add a new entry to the diary
void addEntry(DiaryEntry* diary, int numEntries) {
    // Get current timestamp
    time_t now = time(NULL);
    
    // Allocate memory for new entry
    DiaryEntry newEntry;
    
    // Set timestamp for new entry
    newEntry.timestamp = now;
    
    // Prompt user for entry text
    printf("Enter your diary entry (max %d characters):\n", MAX_ENTRY_LENGTH);
    fgets(newEntry.entry, MAX_ENTRY_LENGTH, stdin);
    
    // Add new entry to the diary
    diary[numEntries++] = newEntry;
    
    // Print confirmation message
    printf("Entry added to diary.\n");
}

// Function to display all entries in the diary
void displayEntries(DiaryEntry* diary, int numEntries) {
    printf("Diary Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        // Format timestamp as a string
        char timestampStr[20];
        strftime(timestampStr, sizeof(timestampStr), "%Y-%m-%d %H:%M:%S", localtime(&diary[i].timestamp));
        
        // Print entry information
        printf("%s: %s\n", timestampStr, diary[i].entry);
    }
}

int main() {
    // Initialize diary with space for 100 entries
    DiaryEntry diary[100];
    int numEntries = 0;
    
    // Main program loop
    while (1) {
        // Print menu options to console
        printf("\nDigital Diary Menu:\n");
        printf("1. Add new entry\n");
        printf("2. Display all entries\n");
        printf("3. Exit\n");
        
        // Prompt user for choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin); // Clear input buffer
        
        // Execute user's choice
        switch (choice) {
            case 1: {
                // Add a new entry to the diary
                addEntry(diary, numEntries);
                numEntries++;
                break;
            }
            case 2: {
                // Display all entries in the diary
                displayEntries(diary, numEntries);
                break;
            }
            case 3: {
                // Exit the program
                printf("Exiting Digital Diary.\n");
                return 0;
            }
            default: {
                // Invalid input
                printf("Invalid input. Please enter a valid option.\n");
            }
        }
    }
}