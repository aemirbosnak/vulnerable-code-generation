//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_TITLE 100
#define MAX_CONTENT 1000
#define FILENAME "diary_entries.txt"

typedef struct {
    char title[MAX_TITLE];
    char content[MAX_CONTENT];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int entryCount = 0;

void loadEntries() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return; // If file does not exist, we'll create new entries
    }
    
    while (fscanf(file, "%99[^\n]\n%999[^\n]\n", entries[entryCount].title,
                  entries[entryCount].content) != EOF) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) {
            break; // Prevent exceeding the maximum entries
        }
    }
    fclose(file);
}

void saveEntries() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error saving entries!\n");
        return;
    }
    
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s\n%s\n", entries[i].title, entries[i].content);
    }
    fclose(file);
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    
    printf("Enter title: ");
    getchar(); // Clear the newline character in input buffer
    fgets(entries[entryCount].title, MAX_TITLE, stdin);
    entries[entryCount].title[strcspn(entries[entryCount].title, "\n")] = 0; // Remove newline

    printf("Enter content (End with 'END'):\n");
    char buffer[MAX_CONTENT];
    strcpy(entries[entryCount].content, "");
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (strcmp(buffer, "END\n") == 0) {
            break;
        }
        strcat(entries[entryCount].content, buffer);
    }

    entryCount++;
    saveEntries();
    printf("Diary entry added!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries found.\n");
        return;
    }

    printf("\n--- DIARY ENTRIES ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\nTitle: %s\nContent:\n%s\n", i + 1, entries[i].title, entries[i].content);
        printf("---------------------\n");
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No diary entries to delete.\n");
        return;
    }
    
    int index;
    printf("Enter the entry number to delete (1-%d): ", entryCount);
    scanf("%d", &index);
    
    if (index < 1 || index > entryCount) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = index - 1; i < entryCount - 1; i++) {
        entries[i] = entries[i + 1];
    }
    entryCount--;
    saveEntries();
    printf("Diary entry deleted.\n");
}

void displayMenu() {
    printf("\n--- Digital Diary ---\n");
    printf("1. Add entry\n");
    printf("2. View entries\n");
    printf("3. Delete entry\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    loadEntries();

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
                deleteEntry();
                break;
            case 4:
                printf("Exiting the Digital Diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}