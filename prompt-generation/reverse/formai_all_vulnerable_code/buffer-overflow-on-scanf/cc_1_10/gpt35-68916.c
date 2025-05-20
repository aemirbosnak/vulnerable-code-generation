//FormAI DATASET v1.0 Category: Digital Diary ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 50 // Maximum number of entries that can be made
#define MAX_NAME 20 // Maximum length of name for each entry

typedef struct {
    char name[MAX_NAME];
    char entry[1000];
} DiaryEntry;

int main() {
    DiaryEntry diary[MAX_ENTRIES]; // Create array for diary entries
    int n_entries = 0; // Counter for number of entries
    char input[1000], name[MAX_NAME]; // Create input strings for adding entries and names
    int i;

    // Introduction message
    printf("Welcome to the Multiplayer Digital Diary!\n");

    // Loop for entering diary entries
    while (1) {
        printf("\nEnter your name (or \"q\" to quit): ");
        scanf("%s", name);
        
        // Quit loop if user wants to quit
        if (strcmp(name, "q") == 0) {
            break;
        }
        
        // Check if user has reached maximum number of entries
        if (n_entries == MAX_ENTRIES) {
            printf("Sorry, the diary is full.\n");
            break;
        }

        // Input diary entry
        printf("Enter your diary entry (maximum 1000 characters):\n");
        scanf(" %[^\n]s", input); // Use %[^\n]s to capture input with spaces
        
        // Add new entry to diary
        strcpy(diary[n_entries].name, name); // Copy name to new entry
        strcpy(diary[n_entries].entry, input); // Copy entry to new entry
        n_entries++; // Increment number of entries
    }

    // Output diary entries
    printf("\n\n\nDiary Entries:\n");
    for (i = 0; i < n_entries; i++) {
        printf("Name: %s\n", diary[i].name);
        printf("Entry: %s\n\n", diary[i].entry);
    }

    return 0;
}