//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 512

typedef struct {
    char entry[MAX_LENGTH];
    time_t timestamp;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

// Function to add a diary entry
void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Write your diary entry: ");
    getchar(); // Consume newline left in buffer
    fgets(diary[entryCount].entry, MAX_LENGTH, stdin);
    
    // Remove newline character from entry
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = '\0';

    diary[entryCount].timestamp = time(NULL);
    entryCount++;

    printf("Entry added successfully!\n");
}

// Function to display all diary entries
void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries to display.\n");
        return;
    }

    printf("\n--- Your Diary ---\n");
    for (int i = 0; i < entryCount; i++) {
        char buffer[26];
        struct tm* tm_info;

        tm_info = localtime(&diary[i].timestamp);
        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

        printf("[%s] Entry %d: %s\n", buffer, i + 1, diary[i].entry);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Diary Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Exit\n");
    printf("Select an option (1-3): ");
}

// Main function
int main() {
    int choice;

    printf("Welcome to the Digital Diary Program!\n");
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                printf("Exiting the Diary. Have a great day!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    }
    return 0;
}