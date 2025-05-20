//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 500

typedef struct {
    char date[20]; // Store date in the format YYYY-MM-DD
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Max entries reached.\n");
        return;
    }

    DiaryEntry new_entry;

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", new_entry.date);
    getchar(); // To consume the newline character

    printf("Write your diary entry (max %d characters):\n", MAX_LENGTH);
    fgets(new_entry.entry, MAX_LENGTH, stdin);

    // Remove newline character at the end of entry
    new_entry.entry[strcspn(new_entry.entry, "\n")] = 0;

    diary[entry_count++] = new_entry;
    printf("Diary entry added successfully.\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries in the diary.\n");
        return;
    }
    printf("==== Diary Entries ====\n");
    for (int i = 0; i < entry_count; i++) {
        printf("[%d] Date: %s\nEntry: %s\n", i + 1, diary[i].date, diary[i].entry);
    }
}

void search_entry() {
    char search_date[20];
    printf("Enter the date to search (YYYY-MM-DD): ");
    scanf("%s", search_date);

    int found = 0;
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(diary[i].date, search_date) == 0) {
            printf("Entry found:\nDate: %s\nEntry: %s\n", diary[i].date, diary[i].entry);
            found = 1;
        }
    }

    if (!found) {
        printf("No entry found for the date %s.\n", search_date);
    }
}

void save_diary() {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "%s\n%s\n", diary[i].date, diary[i].entry);
    }
    fclose(file);
    printf("Diary saved to diary.txt\n");
}

void load_diary() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No saved diary found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%s\n", diary[entry_count].date) != EOF) {
        fgets(diary[entry_count].entry, MAX_LENGTH, file);
        diary[entry_count].entry[strcspn(diary[entry_count].entry, "\n")] = 0; // Remove newline
        entry_count++;
    }
    fclose(file);
    printf("Diary loaded. You have %d entries.\n", entry_count);
}

int main() {
    int choice;

    load_diary();

    while (1) {
        printf("\n=== Digital Diary Menu ===\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Search Entry\n");
        printf("4. Save Diary\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                save_diary();
                break;
            case 5:
                save_diary();
                printf("Exiting the diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}