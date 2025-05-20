//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11]; // YYYY-MM-DD
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }

    printf("\nEnter date (YYYY-MM-DD): ");
    scanf("%10s", diary[entryCount].date);

    getchar(); // Consume newline left over by scanf
    printf("Enter your diary entry: ");
    fgets(diary[entryCount].entry, MAX_LENGTH, stdin);

    // Remove newline character from entry if present
    size_t len = strlen(diary[entryCount].entry);
    if (len > 0 && diary[entryCount].entry[len-1] == '\n') {
        diary[entryCount].entry[len-1] = '\0';
    }

    entryCount++;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("\nNo diary entries found.\n");
        return;
    }

    printf("\nDiary Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\nEntry: %s\n\n", diary[i].date, diary[i].entry);
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("\nNo diary entries to delete.\n");
        return;
    }

    char date[11];
    printf("\nEnter the date of the entry to delete (YYYY-MM-DD): ");
    scanf("%10s", date);

    int found = -1;
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("No entry found for the given date.\n");
    } else {
        for (int i = found; i < entryCount - 1; i++) {
            diary[i] = diary[i + 1]; // Shift entries left
        }
        entryCount--;
        printf("Entry deleted successfully!\n");
    }
}

void displayMenu() {
    printf("\n--- Digital Diary Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
    printf("--------------------------\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
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
                printf("Exiting the diary. Happy journaling!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}