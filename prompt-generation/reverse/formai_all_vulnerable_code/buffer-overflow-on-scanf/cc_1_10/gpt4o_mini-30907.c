//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256

typedef struct {
    char date[20];
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int currentEntryCount = 0;

void addEntry();
void viewEntries();
void displayMenu();
void clearInputBuffer();

int main() {
    int choice;
    // An introductory message
    printf("Welcome to the C Digital Diary!\n");
    printf("You can store your daily thoughts and events here.\n");

    // Main loop allowing the user to choose actions
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer();  // clear newline character from input buffer

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                printf("Exiting the diary. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

// Function to add a new diary entry
void addEntry() {
    if (currentEntryCount >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add new entry.\n");
        return;
    }

    DiaryEntry newEntry;

    // Enter the date
    printf("Enter the date (e.g., YYYY-MM-DD): ");
    fgets(newEntry.date, sizeof(newEntry.date), stdin);
    newEntry.date[strcspn(newEntry.date, "\n")] = 0;  // remove newline

    // Enter the diary entry
    printf("Enter your diary entry: ");
    fgets(newEntry.entry, sizeof(newEntry.entry), stdin);
    newEntry.entry[strcspn(newEntry.entry, "\n")] = 0;  // remove newline

    // Store entry in the diary array
    diary[currentEntryCount++] = newEntry;

    printf("Entry added successfully!\n");
}

// Function to view all diary entries
void viewEntries() {
    if (currentEntryCount == 0) {
        printf("No entries found in the diary. How about adding one?\n");
        return;
    }

    printf("Diary Entries:\n");
    for (int i = 0; i < currentEntryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Date: %s\n", diary[i].date);
        printf("Content: %s\n\n", diary[i].entry);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n======= Digital Diary Menu =======\n");
    printf("1. Add a Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Exit Diary\n");
    printf("Select an option: ");
}

// Function to clear the input buffer (caveat for scanf)
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}