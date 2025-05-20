//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_TEXT_LENGTH 256

typedef struct {
    int id;
    char text[MAX_TEXT_LENGTH];
} DiaryEntry;

void addEntry(DiaryEntry entries[], int *count);
void viewEntries(DiaryEntry entries[], int count);
void deleteEntry(DiaryEntry entries[], int *count);
void displayMenu();

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // Clear the buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                addEntry(entries, &count);
                break;
            case 2:
                viewEntries(entries, count);
                break;
            case 3:
                deleteEntry(entries, &count);
                break;
            case 4:
                printf("Exiting the Digital Diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void displayMenu() {
    printf("\n=== Digital Diary Menu ===\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Delete Diary Entry\n");
    printf("4. Exit\n");
}

void addEntry(DiaryEntry entries[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    entries[*count].id = *count + 1; // Assign a new ID
    printf("Enter your diary entry: ");
    fgets(entries[*count].text, MAX_TEXT_LENGTH, stdin);
    // Remove newline character if present
    entries[*count].text[strcspn(entries[*count].text, "\n")] = 0;

    (*count)++;
    printf("Diary entry added successfully!\n");
}

void viewEntries(DiaryEntry entries[], int count) {
    if (count == 0) {
        printf("No diary entries found.\n");
        return;
    }

    printf("\n=== Your Diary Entries ===\n");
    for (int i = 0; i < count; i++) {
        printf("Entry ID %d: %s\n", entries[i].id, entries[i].text);
    }
}

void deleteEntry(DiaryEntry entries[], int *count) {
    if (*count == 0) {
        printf("No diary entries to delete.\n");
        return;
    }

    int id;
    printf("Enter the ID of the entry you want to delete: ");
    scanf("%d", &id);
    getchar(); // Clear the buffer

    if (id < 1 || id > *count) {
        printf("Invalid ID! Please try again.\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        entries[i] = entries[i + 1]; // Shift entries up
    }
    (*count)--; // Decrease the count
    printf("Diary entry deleted successfully!\n");
}