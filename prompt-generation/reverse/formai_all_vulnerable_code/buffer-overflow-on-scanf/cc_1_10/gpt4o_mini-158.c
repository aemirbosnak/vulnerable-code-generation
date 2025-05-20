//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000
#define DIARY_FILE "diary.txt"

// Structure for an entry in the diary
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} DiaryEntry;

// Function prototypes
void addEntry();
void viewEntries();
void deleteEntry();
void displayMenu();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();
        
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
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n=== Digital Diary Menu ===\n");
    printf("1. Add Diary Entry\n");
    printf("2. View All Entries\n");
    printf("3. Delete an Entry\n");
    printf("4. Exit\n");
}

// Function to add an entry to the diary
void addEntry() {
    FILE *file = fopen(DIARY_FILE, "a");
    if (!file) {
        perror("Failed to open diary file");
        return;
    }

    DiaryEntry entry;
    printf("Enter title: ");
    fgets(entry.title, MAX_TITLE_LENGTH, stdin);
    entry.title[strcspn(entry.title, "\n")] = 0; // Remove newline
    printf("Enter content:\n");
    fgets(entry.content, MAX_CONTENT_LENGTH, stdin);
    entry.content[strcspn(entry.content, "\n")] = 0; // Remove newline

    fprintf(file, "%s\n%s\n", entry.title, entry.content);
    fclose(file);
    printf("Entry added successfully!\n");
}

// Function to view all entries in the diary
void viewEntries() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (!file) {
        perror("Failed to open diary file");
        return;
    }

    DiaryEntry entry;
    printf("\n--- Diary Entries ---\n");
    while (fgets(entry.title, MAX_TITLE_LENGTH, file) != NULL) {
        // Read the content for the title
        fgets(entry.content, MAX_CONTENT_LENGTH, file);
        printf("Title: %sContent: %s\n", entry.title, entry.content);
    }
    fclose(file);
}

// Function to delete an entry from the diary
void deleteEntry() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (!file) {
        perror("Failed to open diary file");
        return;
    }

    DiaryEntry entries[MAX_ENTRIES];
    int count = 0;

    // Read existing entries into memory
    while (fgets(entries[count].title, MAX_TITLE_LENGTH, file) != NULL) {
        fgets(entries[count].content, MAX_CONTENT_LENGTH, file);
        count++;
    }
    fclose(file);

    // Display entries for user to choose from
    printf("\n--- Select an Entry to Delete ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s", i + 1, entries[i].title);
    }

    int entryNumber;
    printf("\nEnter the entry number to delete: ");
    scanf("%d", &entryNumber);
    clearBuffer();

    if (entryNumber < 1 || entryNumber > count) {
        printf("Invalid entry number.\n");
        return;
    }

    // Rewrite diary excluding the deleted entry
    file = fopen(DIARY_FILE, "w");
    if (!file) {
        perror("Failed to open diary file for writing");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i != (entryNumber - 1)) { // Skip the entry to delete
            fprintf(file, "%s\n%s\n", entries[i].title, entries[i].content);
        }
    }
    fclose(file);
    printf("Entry deleted successfully!\n");
}

// Function to clear the input buffer
void clearBuffer() {
    while (getchar() != '\n');
}