//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_CONTENT 500

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char content[MAX_CONTENT];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

// Function declarations
void addEntry();
void viewEntries();
void deleteEntry();
void displayMenu();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character
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
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Digital Diary Menu ---\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Delete Diary Entry\n");
    printf("4. Exit\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }
    
    printf("Enter date (YYYY-MM-DD): ");
    fgets(diary[entryCount].date, sizeof(diary[entryCount].date), stdin);
    diary[entryCount].date[strcspn(diary[entryCount].date, "\n")] = 0; // Remove newline

    printf("Enter your diary entry: ");
    fgets(diary[entryCount].content, sizeof(diary[entryCount].content), stdin);
    diary[entryCount].content[strcspn(diary[entryCount].content, "\n")] = 0; // Remove newline

    entryCount++;
    printf("Diary entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries found.\n");
        return;
    }
    
    printf("\n--- Diary Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Date: %s\n", diary[i].date);
        printf("Content: %s\n", diary[i].content);
        printf("---------------------\n");
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No diary entries to delete.\n");
        return;
    }

    int entryNumber;
    printf("Enter the entry number to delete (1 to %d): ", entryCount);
    scanf("%d", &entryNumber);
    getchar(); // Consume newline character

    if (entryNumber < 1 || entryNumber > entryCount) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = entryNumber - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1]; // Shift entries left
    }
    entryCount--;
    printf("Diary entry deleted successfully!\n");
}