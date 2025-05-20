//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 500
#define FILE_NAME "diary_entries.txt"

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(diary[entry_count].date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    printf("Enter your diary entry (max %d characters):\n", MAX_LENGTH);
    getchar(); // Clear newline buffer
    fgets(diary[entry_count].entry, MAX_LENGTH, stdin);
    diary[entry_count].entry[strcspn(diary[entry_count].entry, "\n")] = 0; // Remove newline

    entry_count++;
    printf("Entry added for %s!\n", diary[entry_count - 1].date);
}

void display_entries() {
    if (entry_count == 0) {
        printf("No diary entries found.\n");
        return;
    }

    printf("\n---- Your Diary Entries ----\n");
    for (int i = 0; i < entry_count; i++) {
        printf("[%s]: %s\n", diary[i].date, diary[i].entry);
    }
    printf("-----------------------------\n");
}

void save_entries() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "[%s]: %s\n", diary[i].date, diary[i].entry);
    }

    fclose(file);
    printf("Diary entries saved to %s\n", FILE_NAME);
}

void load_entries() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No existing diary entries to load.\n");
        return;
    }

    while (fgets(diary[entry_count].entry, MAX_LENGTH, file) && entry_count < MAX_ENTRIES) {
        char *date_start = strchr(diary[entry_count].entry, '[') + 1; // Find '['
        char *date_end = strchr(diary[entry_count].entry, ']'); // Find ']'
        strncpy(diary[entry_count].date, date_start, date_end - date_start);
        diary[entry_count].date[date_end - date_start] = '\0'; // Null terminate

        diary[entry_count].entry[strcspn(diary[entry_count].entry, "\n")] = 0; // Remove newline
        entry_count++;
    }

    fclose(file);
    printf("Loaded %d diary entries from %s\n", entry_count, FILE_NAME);
}

int main() {
    int choice;

    load_entries();

    while (1) {
        printf("\n=== Digital Diary ===\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Save Entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                display_entries();
                break;
            case 3:
                save_entries();
                break;
            case 4:
                printf("Exiting the program. Have a nice day!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}