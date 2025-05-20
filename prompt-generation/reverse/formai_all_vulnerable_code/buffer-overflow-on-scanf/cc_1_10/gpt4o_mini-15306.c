//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[MAX_LENGTH];
    char content[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

// Function prototypes
void addEntry();
void viewEntries();
void deleteEntry();
void displayMenu();

int main() {
    int choice;
    do {
        displayMenu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from buffer
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                printf("Exiting the diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}

void displayMenu() {
    printf("\n=== Digital Diary ===\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Unable to add more entries.\n");
        return;
    }
    
    printf("Enter date (YYYY-MM-DD): ");
    fgets(diary[entryCount].date, MAX_LENGTH, stdin);
    diary[entryCount].date[strcspn(diary[entryCount].date, "\n")] = '\0'; // Remove newline

    printf("Enter your diary entry: ");
    fgets(diary[entryCount].content, MAX_LENGTH, stdin);
    diary[entryCount].content[strcspn(diary[entryCount].content, "\n")] = '\0'; // Remove newline

    entryCount++;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("\n=== Diary Entries ===\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Date: %s\n", diary[i].date);
        printf("Content: %s\n\n", diary[i].content);
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int index;
    printf("Enter the entry number to delete (1-%d): ", entryCount);
    scanf("%d", &index);
    getchar(); // Clear newline character from buffer

    if (index < 1 || index > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    // Shift entries to delete the specified one
    for (int i = index - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entryCount--;
    printf("Entry deleted successfully!\n");
}