//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000
#define DIARY_FILE "diary.txt"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Entry;

void addEntry();
void viewEntries();
void deleteEntry();
void displayMenu();
void loadEntries(Entry entries[], int *count);
void saveEntries(Entry entries[], int count);

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

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
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n=== Digital Diary ===\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
}

void addEntry() {
    Entry newEntry;
    
    printf("Enter entry title: ");
    fgets(newEntry.title, MAX_TITLE_LENGTH, stdin);
    newEntry.title[strcspn(newEntry.title, "\n")] = 0; // remove newline

    printf("Enter entry content:\n");
    fgets(newEntry.content, MAX_CONTENT_LENGTH, stdin);
    newEntry.content[strcspn(newEntry.content, "\n")] = 0; // remove newline

    FILE *file = fopen(DIARY_FILE, "a");
    if (file) {
        fprintf(file, "%s\n%s\n", newEntry.title, newEntry.content);
        fclose(file);
        printf("Entry added successfully!\n");
    } else {
        printf("Error saving the entry.\n");
    }
}

void viewEntries() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (!file) {
        printf("No entries found or error opening diary.\n");
        return;
    }

    char line[1000];
    int entryCount = 0;
    printf("\n=== Diary Entries ===\n");

    while (fgets(line, sizeof(line), file)) {
        entryCount++;
        printf("Entry %d:\n", entryCount);
        printf("%s", line);
        
        fgets(line, sizeof(line), file);
        printf("%s\n", line);
    }

    fclose(file);
}

void deleteEntry() {
    Entry entries[MAX_ENTRIES];
    int count = 0;
    loadEntries(entries, &count);

    if (count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    printf("\n=== Entries ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s", i + 1, entries[i].title);
    }

    int choice;
    printf("\nEnter the number of the entry to delete: ");
    scanf("%d", &choice);
    getchar(); // consume newline character

    if (choice < 1 || choice > count) {
        printf("Invalid entry number.\n");
        return;
    }

    // Shift entries down to delete the selected entry
    for (int i = choice - 1; i < count - 1; i++) {
        entries[i] = entries[i + 1];
    }
    
    count--;
    saveEntries(entries, count);
    printf("Entry deleted successfully!\n");
}

void loadEntries(Entry entries[], int *count) {
    FILE *file = fopen(DIARY_FILE, "r");
    if (!file) {
        *count = 0;
        return;
    }

    char line[1000];
    *count = 0;

    while (fgets(entries[*count].title, sizeof(entries[*count].title), file)) {
        entries[*count].title[strcspn(entries[*count].title, "\n")] = 0; // remove newline
        fgets(entries[*count].content, sizeof(entries[*count].content), file);
        (*count)++;
    }

    fclose(file);
}

void saveEntries(Entry entries[], int count) {
    FILE *file = fopen(DIARY_FILE, "w");
    if (file) {
        for (int i = 0; i < count; i++) {
            fprintf(file, "%s\n%s\n", entries[i].title, entries[i].content);
        }
        fclose(file);
    } else {
        printf("Error saving the entries.\n");
    }
}