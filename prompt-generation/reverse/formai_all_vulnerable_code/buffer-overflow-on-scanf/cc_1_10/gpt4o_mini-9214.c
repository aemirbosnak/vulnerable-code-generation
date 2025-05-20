//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    sprintf(diary[entry_count].date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    
    printf("Enter your diary entry (max %d characters):\n", MAX_LENGTH);
    getchar(); // Clear newline from the buffer
    fgets(diary[entry_count].entry, MAX_LENGTH, stdin);
    // Remove newline character from the entry
    diary[entry_count].entry[strcspn(diary[entry_count].entry, "\n")] = 0;

    entry_count++;
    printf("Entry added for date: %s\n", diary[entry_count - 1].date);
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    printf("\n--- Diary Entries ---\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].entry);
        printf("---------------------\n");
    }
}

void delete_entry() {
    if (entry_count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    printf("Enter the date of the entry to delete (YYYY-MM-DD): ");
    char date[11];
    scanf("%10s", date);
    
    int found = 0;
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            for (int j = i; j < entry_count - 1; j++) {
                diary[j] = diary[j + 1];
            }
            entry_count--;
            found = 1;
            printf("Entry for date %s deleted.\n", date);
            break;
        }
    }

    if (!found) {
        printf("No entry found for the date %s.\n", date);
    }
}

void save_diary() {
    FILE *file = fopen("diary_entries.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "%s\n%s\n", diary[i].date, diary[i].entry);
    }

    fclose(file);
    printf("Diary saved successfully!\n");
}

void load_diary() {
    FILE *file = fopen("diary_entries.txt", "r");
    if (!file) {
        printf("No diary saved yet, starting fresh.\n");
        return;
    }

    while (fscanf(file, "%10s\n%255[^\n]\n", diary[entry_count].date, diary[entry_count].entry) != EOF) {
        entry_count++;
        if (entry_count >= MAX_ENTRIES) {
            break;
        }
    }

    fclose(file);
    printf("Diary loaded successfully with %d entries.\n", entry_count);
}

int main() {
    int choice;

    load_diary();

    do {
        printf("\n--- Digital Diary Menu ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Save Diary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                save_diary();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    save_diary(); // Save before exiting
    return 0;
}