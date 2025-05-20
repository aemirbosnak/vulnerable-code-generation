//FormAI DATASET v1.0 Category: Digital Diary ; Style: interoperable
// C Digital Diary Example Program

#include <stdio.h>
#include <string.h>

// Define a structure for a diary entry
struct DiaryEntry {
    char date[11];      // Format: DD/MM/YYYY
    char time[6];       // Format: HH:MM
    char location[50];
    char description[200];
};

// Define the maximum number of entries that can be stored
#define MAX_ENTRIES 100

// Initialize the diary with an empty array of entries
struct DiaryEntry diary[MAX_ENTRIES];
int diarySize = 0;

// Function to add a new entry to the diary
void addEntry() {
    // Check if the maximum number of entries has been reached
    if(diarySize == MAX_ENTRIES) {
        printf("\nSorry, the diary is full. Cannot add new entry.");
        return;
    }

    // Create a new DiaryEntry struct to store the new entry
    struct DiaryEntry newEntry;

    // Get input from the user for the new entry's data
    printf("\nEnter Date (DD/MM/YYYY): ");
    scanf("%s", newEntry.date);
    printf("Enter Time (HH:MM): ");
    scanf("%s", newEntry.time);

    // Consume the remaining newline character from the previous input
    getchar();

    printf("Enter Location: ");
    fgets(newEntry.location, 50, stdin);

    printf("Enter Description: ");
    fgets(newEntry.description, 200, stdin);

    // Add the new entry to the diary and increment the size
    diary[diarySize] = newEntry;
    diarySize++;

    printf("\nNew entry added successfully!");
}

// Function to display all entries in the diary
void displayEntries() {
    // Check if there are no entries in the diary
    if(diarySize == 0) {
        printf("\nSorry, the diary is empty.");
        return;
    }

    printf("\nDIARY ENTRIES:\n");
    printf("---------------------------------------------------------------------------\n");
    printf("| %-11s | %-6s | %-50s | %-200s |\n", "DATE", "TIME", "LOCATION", "DESCRIPTION");
    printf("---------------------------------------------------------------------------\n");

    // Loop through all entries in the diary and display them
    for(int i=0; i<diarySize; i++) {
        struct DiaryEntry currentEntry = diary[i];
        printf("| %-11s | %-6s | %-50s | %-200s |\n", currentEntry.date, currentEntry.time, currentEntry.location, currentEntry.description);
    }

    printf("---------------------------------------------------------------------------\n");
}

int main() {
    int choice;

    do {
        // Display the menu and get user input
        printf("\nDIARY MENU:");
        printf("\n1. Add new entry");
        printf("\n2. Display all entries");
        printf("\n3. Exit");
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                printf("\nExiting digital diary...");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }
    } while(choice != 3);

    return 0;
}