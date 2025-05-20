//FormAI DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100 // Maximum number of entries that can be stored

// A structure that represents an individual diary entry
struct DiaryEntry {
    char date[11];
    char entry[1001];
};

// Function to print the menu
void printMenu() {
    printf("\n\nC Digital Diary\n");
    printf("----------------\n");
    printf("1. Add Entry\n");
    printf("2. Read Entry\n");
    printf("3. List All Entries\n");
    printf("4. Exit\n");
}

int main() {
    struct DiaryEntry diary[MAX_ENTRIES]; // Array to store diary entries
    int numEntries = 0; // Number of entries currently in diary
    
    // Welcome message
    printf("Welcome to C Digital Diary!\n");
    
    // Loop to display menu and handle user choice
    while (1) {
        printMenu(); // Print menu
        
        // Read user choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Add Entry
                if (numEntries == MAX_ENTRIES) {
                    printf("Diary is full. Cannot add more entries.\n");
                    break;
                }
                
                // Read date and entry from user
                printf("Enter date (in DD/MM/YYYY format): ");
                scanf("%s", diary[numEntries].date);
                printf("Enter entry (maximum 1000 characters):\n");
                scanf(" %[^\n]s", diary[numEntries].entry);
                
                // Increment number of entries
                numEntries++;
                
                printf("Entry added successfully!\n");
                break;
            
            case 2: // Read Entry
                if (numEntries == 0) {
                    printf("Diary is empty. No entries to read.\n");
                    break;
                }
                
                // Read entry number from user
                int entryNum;
                printf("Enter entry number (between 1 and %d): ", numEntries);
                scanf("%d", &entryNum);
                
                // Check if entry number is valid
                if (entryNum < 1 || entryNum > numEntries) {
                    printf("Invalid entry number. Please try again.\n");
                    break;
                }
                
                // Print the entry
                printf("\nEntry %d\n", entryNum);
                printf("Date: %s\n", diary[entryNum-1].date);
                printf("Entry: %s\n", diary[entryNum-1].entry);
                break;
            
            case 3: // List All Entries
                if (numEntries == 0) {
                    printf("Diary is empty. No entries to list.\n");
                    break;
                }
                
                printf("\nList of all entries\n");
                printf("--------------------\n");
                
                // Print all entries
                for (int i=0; i<numEntries; i++) {
                    printf("Entry %d\n", i+1);
                    printf("Date: %s\n", diary[i].date);
                    printf("Entry: %s\n\n", diary[i].entry);
                }
                break;
            
            case 4: // Exit
                printf("Thank you for using C Digital Diary. Have a nice day!\n");
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}