//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[MAX_LENGTH];
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("The diary is full, my dear Watson. No more entries can be added.\n");
        return;
    }
    
    printf("Date (format: yyyy-mm-dd): ");
    scanf("%s", diary[entryCount].date);
    getchar();  // to consume the newline character
    printf("Enter the diary entry: ");
    fgets(diary[entryCount].entry, MAX_LENGTH, stdin);
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0; // remove newline character
    entryCount++;
    printf("An entry has been recorded, Watson.\n");
}

void viewEntries() {
    printf("\n--- Diary Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n\n", diary[i].entry);
    }
}

void searchEntry() {
    char keyword[MAX_LENGTH];
    printf("Enter a keyword to search in the diary: ");
    scanf("%s", keyword);
    int found = 0;
    
    printf("\n--- Search Results for \"%s\" ---\n", keyword);
    for (int i = 0; i < entryCount; i++) {
        if (strstr(diary[i].entry, keyword) != NULL) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n\n", diary[i].entry);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found containing the keyword \"%s\".\n", keyword);
    }
}

void displayMenu() {
    printf("\n--- Sherlock Holmes Digital Diary ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entry\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    
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
                searchEntry();
                break;
            case 4:
                printf("As we part ways, remember that the game is afoot!\n");
                return 0;
            default:
                printf("That is not a valid choice, Watson. Try again.\n");
        }
    }
    
    return 0;
}