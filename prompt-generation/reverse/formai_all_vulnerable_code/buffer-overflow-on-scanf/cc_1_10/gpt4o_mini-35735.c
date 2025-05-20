//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 500
#define DATE_LENGTH 11

typedef struct {
    char date[DATE_LENGTH];
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void greetUser() {
    printf("Welcome to your Digital Diary!\n");
    printf("A safe place for your thoughts.\n\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Please delete an entry before adding a new one.\n");
        return;
    }
    
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    strftime(diary[entryCount].date, DATE_LENGTH, "%Y-%m-%d", local);
    
    printf("Enter your diary entry: ");
    getchar(); // Clear buffer
    fgets(diary[entryCount].entry, ENTRY_LENGTH, stdin);
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = '\0'; // Remove newline

    entryCount++;
    printf("Entry added on %s\n\n", diary[entryCount-1].date);
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found in the diary.\n\n");
        return;
    }
    
    printf("Your Diary Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].entry);
        printf("-----------------------\n");
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete!\n\n");
        return;
    }

    int index;
    printf("Enter the entry number to delete (1 - %d): ", entryCount);
    scanf("%d", &index);

    if (index < 1 || index > entryCount) {
        printf("Invalid entry number.\n\n");
        return;
    }

    index--; // Adjust for zero-based index
    for (int i = index; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1]; // Shift entries up
    }
    entryCount--; // Reduce the count
    printf("Entry deleted successfully.\n\n");
}

void exitDiary() {
    printf("Thank you for using the Digital Diary! Have a great day!\n");
    exit(0);
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
}

int main() {
    greetUser();

    while (1) {
        displayMenu();
        int choice;
        printf("Select an option: ");
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
                exitDiary();
                break;
            default:
                printf("Invalid option. Please try again.\n\n");
        }
    }
    
    return 0;
}