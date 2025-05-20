//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int entryCount = 0;

void getCurrentDate(char *dateBuffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(dateBuffer, 20, "%Y-%m-%d %H:%M:%S", t);
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries!\n");
        return;
    }

    char date[20];
    getCurrentDate(date);
    
    printf("Enter your diary entry:\n");
    fgets(entries[entryCount].entry, MAX_LENGTH, stdin);
    entries[entryCount].entry[strcspn(entries[entryCount].entry, "\n")] = '\0'; // Remove newline

    strcpy(entries[entryCount].date, date);
    entryCount++;
    printf("Entry added on %s\n", date);
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries available.\n");
        return;
    }

    printf("\n--- Diary Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("[%d] %s:\n%s\n", i + 1, entries[i].date, entries[i].entry);
    }
}

void deleteEntry() {
    int index;
    if (entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }

    printf("Select entry number to delete (1 to %d): ", entryCount);
    scanf("%d", &index);
    getchar(); // Clear newline

    if (index < 1 || index > entryCount) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = index - 1; i < entryCount - 1; i++) {
        entries[i] = entries[i + 1];
    }
    entryCount--;

    printf("Entry %d deleted.\n", index);
}

void menu() {
    printf("Welcome to the Post-Apocalyptic Diary\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    
    while (1) {
        menu();
        scanf("%d", &choice);
        getchar(); // Clear newline character after scanf
        
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
                printf("Exiting the diary...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}