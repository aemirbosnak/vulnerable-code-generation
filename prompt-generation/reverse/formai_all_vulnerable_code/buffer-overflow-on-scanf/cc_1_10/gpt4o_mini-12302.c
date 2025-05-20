//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char content[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }
    printf("Enter your diary entry (max 255 characters):\n");
    getchar();  // Clear newline from buffer
    fgets(diary[entryCount].content, MAX_LENGTH, stdin);
    DiaryEntry currentEntry;
    strcpy(currentEntry.content, diary[entryCount].content);
    entryCount++;
    printf("Your entry has been added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries in diary.\n");
        return;
    }
    printf("\nYour Diary Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d: %s", i + 1, diary[i].content);
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }
    
    int entryNumber;
    printf("Enter the entry number to delete (1 to %d): ", entryCount);
    scanf("%d", &entryNumber);
    
    if (entryNumber < 1 || entryNumber > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    // Shift entries to delete the selected one
    for (int i = entryNumber - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entryCount--;  // Decrease the count of entries
    printf("Entry %d has been deleted successfully!\n", entryNumber);
}

void displayMenu() {
    printf("\n--- Digital Diary Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
    printf("---------------------------\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

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
                printf("Exiting the diary. Thank you for using your Digital Diary!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}