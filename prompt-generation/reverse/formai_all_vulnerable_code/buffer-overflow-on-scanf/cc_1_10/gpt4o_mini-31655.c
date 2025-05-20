//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[20];
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void clearScreen() {
    printf("\033[H\033[J");
}

void displayMenu() {
    printf("***** Digital Diary *****\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
    printf("Please select an option: ");
}

void getCurrentDate(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", t);
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    char entryText[MAX_LENGTH];
    getCurrentDate(diary[entryCount].date);
    
    printf("Enter your entry: ");
    getchar(); // Consuming the newline character left by previous input
    fgets(entryText, MAX_LENGTH, stdin);
    entryText[strcspn(entryText, "\n")] = '\0'; // Remove newline character

    strcpy(diary[entryCount].entry, entryText);
    entryCount++;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries found!\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d - Date: %s\n", i + 1, diary[i].date);
        printf("Content: %s\n\n", diary[i].entry);
    }
}

void searchEntry() {
    if (entryCount == 0) {
        printf("No diary entries to search through!\n");
        return;
    }

    char searchTerm[MAX_LENGTH];
    printf("Enter search term: ");
    getchar(); 
    fgets(searchTerm, MAX_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strstr(diary[i].entry, searchTerm) != NULL) {
            printf("Found in Entry %d - Date: %s\n", i + 1, diary[i].date);
            printf("Content: %s\n\n", diary[i].entry);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching entries found for '%s'.\n", searchTerm);
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete!\n");
        return;
    }

    int index;
    printf("Enter the entry number to delete (1 to %d): ", entryCount);
    scanf("%d", &index);

    if (index < 1 || index > entryCount) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = index - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entryCount--;
    printf("Entry deleted successfully!\n");
}

int main() {
    int choice;

    while (1) {
        clearScreen();
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
                printf("Exiting the diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("Press Enter to continue...\n");
        getchar(); // Consume newline after number input
        getchar(); // Wait for another Enter
    }

    return 0;
}