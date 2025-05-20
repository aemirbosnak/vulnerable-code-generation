//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256
#define FILENAME "diary.txt"

void addEntry();
void viewEntries();
void deleteEntry();

int main() {
    int choice;

    while (1) {
        printf("\nDiary Application\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // to consume newline after entering choice

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
                printf("Exiting the diary application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addEntry() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char entry[ENTRY_SIZE];
    printf("Enter your diary entry: ");
    fgets(entry, ENTRY_SIZE, stdin);
    
    fprintf(file, "%s", entry);
    fclose(file);
    printf("Entry added successfully!\n");
}

void viewEntries() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    
    char entry[ENTRY_SIZE];
    printf("\nYour Diary Entries:\n");
    while (fgets(entry, ENTRY_SIZE, file)) {
        printf("%s", entry);
    }
    fclose(file);
}

void deleteEntry() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char entries[MAX_ENTRIES][ENTRY_SIZE];
    int count = 0;

    while (fgets(entries[count], ENTRY_SIZE, file) && count < MAX_ENTRIES) {
        count++;
    }
    fclose(file);

    printf("\nYour Diary Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s", i + 1, entries[i]);
    }

    int entryToDelete;
    printf("Enter the number of the entry to delete: ");
    scanf("%d", &entryToDelete);
    getchar(); // to consume newline

    if (entryToDelete < 1 || entryToDelete > count) {
        printf("Invalid entry number!\n");
        return;
    }

    FILE *newFile = fopen(FILENAME, "w");
    if (!newFile) {
        perror("Unable to open file");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i != entryToDelete - 1) {
            fprintf(newFile, "%s", entries[i]);
        }
    }

    fclose(newFile);
    printf("Entry deleted successfully!\n");
}