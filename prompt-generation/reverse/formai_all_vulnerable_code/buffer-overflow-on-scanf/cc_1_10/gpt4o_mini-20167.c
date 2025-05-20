//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LEN 50
#define MAX_ENTRY_LEN 500

typedef struct{
    char title[MAX_TITLE_LEN];
    char content[MAX_ENTRY_LEN];
} DiaryEntry;

DiaryEntry diaryEntries[MAX_ENTRIES];
int entryCount = 0;

void addEntry();
void viewEntries();
void updateEntry();
void deleteEntry();
void showMenu();
void clearInputBuffer();

int main() {
    int choice;

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch(choice) {
            case 1: 
                addEntry();
                break;
            case 2: 
                viewEntries();
                break;
            case 3: 
                updateEntry();
                break;
            case 4: 
                deleteEntry();
                break;
            case 5: 
                printf("Exiting... Goodbye!\n");
                break;
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void showMenu() {
    printf("\n*** Digital Diary Menu ***\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Update Diary Entry\n");
    printf("4. Delete Diary Entry\n");
    printf("5. Exit\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addEntry() {
    if (entryCount == MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    
    printf("Enter title of the diary entry: ");
    fgets(diaryEntries[entryCount].title, MAX_TITLE_LEN, stdin);
    diaryEntries[entryCount].title[strcspn(diaryEntries[entryCount].title, "\n")] = 0;  // Remove newline
    
    printf("Enter content of the diary entry: ");
    fgets(diaryEntries[entryCount].content, MAX_ENTRY_LEN, stdin);
    diaryEntries[entryCount].content[strcspn(diaryEntries[entryCount].content, "\n")] = 0;  // Remove newline
    
    entryCount++;
    printf("Diary entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries available.\n");
        return;
    }
    
    printf("\n*** Diary Entries ***\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Title: %s\n", diaryEntries[i].title);
        printf("Content: %s\n\n", diaryEntries[i].content);
    }
}

void updateEntry() {
    int idx;
    
    if (entryCount == 0) {
        printf("No diary entries to update.\n");
        return;
    }
    
    printf("Enter the entry number to update (1-%d): ", entryCount);
    scanf("%d", &idx);
    clearInputBuffer();

    if (idx < 1 || idx > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    printf("Updating Entry %d:\n", idx);
    printf("Enter new title: ");
    fgets(diaryEntries[idx - 1].title, MAX_TITLE_LEN, stdin);
    diaryEntries[idx - 1].title[strcspn(diaryEntries[idx - 1].title, "\n")] = 0;  // Remove newline

    printf("Enter new content: ");
    fgets(diaryEntries[idx - 1].content, MAX_ENTRY_LEN, stdin);
    diaryEntries[idx - 1].content[strcspn(diaryEntries[idx - 1].content, "\n")] = 0;  // Remove newline

    printf("Diary entry updated successfully!\n");
}

void deleteEntry() {
    int idx;
    
    if (entryCount == 0) {
        printf("No diary entries to delete.\n");
        return;
    }
    
    printf("Enter the entry number to delete (1-%d): ", entryCount);
    scanf("%d", &idx);
    clearInputBuffer();

    if (idx < 1 || idx > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = idx - 1; i < entryCount - 1; i++) {
        diaryEntries[i] = diaryEntries[i + 1];
    }
    
    entryCount--;
    printf("Diary entry deleted successfully!\n");
}