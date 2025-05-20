//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define DIARY_FILE "diary.txt"

typedef struct {
    int id;
    char content[MAX_LENGTH];
} DiaryEntry;

void writeEntryToFile(DiaryEntry *entry);
void readEntriesFromFile(DiaryEntry entries[], int *count);
void addEntry();
void viewEntries();
void deleteEntry();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Digital Diary ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);
        clearBuffer(); // Clear the newline character from the input buffer

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
                printf("Exiting the diary. Have a nice day!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}

void addEntry() {
    DiaryEntry entry;
    FILE *file = fopen(DIARY_FILE, "a");
    
    if (file == NULL) {
        perror("Could not open diary file");
        return;
    }
    
    printf("Enter your diary entry: ");
    fgets(entry.content, MAX_LENGTH, stdin);
    entry.id = rand() % 100000; // Generate a random ID for simplicity

    writeEntryToFile(&entry);

    printf("Your entry has been saved!\n");
    fclose(file);
}

void writeEntryToFile(DiaryEntry *entry) {
    FILE *file = fopen(DIARY_FILE, "a");
    if (file) {
        fprintf(file, "%d: %s", entry->id, entry->content);
        fclose(file);
    }
}

void viewEntries() {
    DiaryEntry entries[MAX_ENTRIES];
    int count = 0;

    readEntriesFromFile(entries, &count);

    printf("\n--- Your Diary Entries ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s", entries[i].id, entries[i].content);
    }
}

void readEntriesFromFile(DiaryEntry entries[], int *count) {
    FILE *file = fopen(DIARY_FILE, "r");

    if (file == NULL) {
        printf("No entries available in the diary.\n");
        return;
    }

    while (fscanf(file, "%d: %[^\n]\n", &entries[*count].id, entries[*count].content) != EOF) {
        (*count)++;
    }
    fclose(file);
}

void deleteEntry() {
    DiaryEntry entries[MAX_ENTRIES];
    int count = 0;

    readEntriesFromFile(entries, &count);

    if (count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int idToDelete;
    printf("Enter the ID of the entry to delete: ");
    scanf("%d", &idToDelete);
    clearBuffer(); // Clear the newline character

    FILE *file = fopen(DIARY_FILE, "w");
    
    if (file) {
        for (int i = 0; i < count; i++) {
            if (entries[i].id != idToDelete) {
                fprintf(file, "%d: %s", entries[i].id, entries[i].content);
            }
        }
        fclose(file);
        printf("Entry with ID %d has been deleted!\n", idToDelete);
    } else {
        perror("Could not open diary file");
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the standard input buffer
}