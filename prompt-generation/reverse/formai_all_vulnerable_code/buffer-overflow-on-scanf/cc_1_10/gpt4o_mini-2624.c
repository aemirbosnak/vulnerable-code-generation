//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }
    
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", diary[entryCount].date);
    
    printf("Write your diary entry: ");
    getchar(); // Consume newline left by previous scanf
    fgets(diary[entryCount].entry, MAX_LENGTH, stdin);
    
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0; // Remove newline
    entryCount++;
    
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries in the diary.\n");
        return;
    }
    
    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].entry);
        printf("-------------------------\n");
    }
}

void searchEntry() {
    char searchDate[11];
    printf("Enter the date to search (YYYY-MM-DD): ");
    scanf("%s", searchDate);
    
    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(diary[i].date, searchDate) == 0) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n", diary[i].entry);
            printf("-------------------------\n");
            found++;
        }
    }
    
    if (found == 0) {
        printf("No entries found for date: %s\n", searchDate);
    }
}

void deleteEntry() {
    char deleteDate[11];
    printf("Enter the date of the entry to delete (YYYY-MM-DD): ");
    scanf("%s", deleteDate);
    
    int found = -1;
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(diary[i].date, deleteDate) == 0) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        printf("No entries found for date: %s\n", deleteDate);
        return;
    }
    
    for (int i = found; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    
    entryCount--;
    printf("Entry deleted successfully!\n");
}

void displayMenu() {
    printf("\n===== Digital Diary =====\n");
    printf("1. Add Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
    printf("===========================\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    do {
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
                searchEntry();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                printf("Exiting the diary application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}