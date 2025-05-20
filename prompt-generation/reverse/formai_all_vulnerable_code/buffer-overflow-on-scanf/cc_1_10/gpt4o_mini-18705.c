//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define FILENAME "diary.txt"

typedef struct {
    int id;
    char content[MAX_LENGTH];
} DiaryEntry;

void initializeDiary();
void addEntry();
void displayEntries();
void deleteEntry();
void clearBuffer();

int main() {
    int choice;

    initializeDiary();

    do {
        printf("\n==================== Digital Diary ====================\n");
        printf("1. Add Diary Entry\n");
        printf("2. Display Diary Entries\n");
        printf("3. Delete Diary Entry\n");
        printf("4. Exit\n");
        printf("=========================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // clear newline character left by scanf

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                printf("Exiting the Digital Diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void initializeDiary() {
    FILE *file = fopen(FILENAME, "a+");
    if (file == NULL) {
        fprintf(stderr, "Error opening diary file!\n");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

void addEntry() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        fprintf(stderr, "Error opening diary file!\n");
        return;
    }

    DiaryEntry entry;
    entry.id = 0; // Currently not used for identification

    printf("Enter your diary entry: ");
    fgets(entry.content, MAX_LENGTH, stdin);

    // Remove newline character if present
    entry.content[strcspn(entry.content, "\n")] = 0;

    fprintf(file, "%s\n", entry.content);
    fclose(file);
    printf("Diary entry added successfully.\n");
}

void displayEntries() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening diary file!\n");
        return;
    }

    char line[MAX_LENGTH];
    int lineNumber = 1;

    printf("\n=== Diary Entries ===\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", lineNumber, line);
        lineNumber++;
    }
    fclose(file);
}

void deleteEntry() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening diary file!\n");
        return;
    }

    char lines[MAX_ENTRIES][MAX_LENGTH];
    int count = 0;

    while (fgets(lines[count], sizeof(lines[count]), file) && count < MAX_ENTRIES) {
        count++;
    }
    fclose(file);

    printf("Current Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s", i + 1, lines[i]);
    }

    int deleteIndex;
    printf("Enter the number of the entry you want to delete: ");
    scanf("%d", &deleteIndex);
    clearBuffer(); // clear newline character left by scanf

    if (deleteIndex < 1 || deleteIndex > count) {
        printf("Invalid entry number!\n");
        return;
    }

    file = fopen(FILENAME, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening diary file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i != deleteIndex - 1) { // Skip the deleted entry
            fprintf(file, "%s", lines[i]);
        }
    }
    fclose(file);
    printf("Diary entry deleted successfully.\n");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}