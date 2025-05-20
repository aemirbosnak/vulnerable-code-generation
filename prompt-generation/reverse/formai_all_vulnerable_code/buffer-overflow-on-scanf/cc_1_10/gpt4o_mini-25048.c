//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_CONTENT 512

typedef struct {
    char date[11];
    char content[MAX_CONTENT];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter your diary entry:\n");
    getchar(); // Clear the newline character from buffer
    fgets(diary[entry_count].content, MAX_CONTENT, stdin);
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    strftime(diary[entry_count].date, sizeof(diary[entry_count].date), "%Y-%m-%d", t);
    entry_count++;

    printf("Entry added successfully on %s!\n", diary[entry_count - 1].date);
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries found in the diary.\n");
        return;
    }

    printf("\n--- Your Diary Entries ---\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Date: %s\nEntry: %s\n", diary[i].date, diary[i].content);
    }
    printf("--------------------------\n");
}

void delete_entry() {
    if (entry_count == 0) {
        printf("No entries found to delete.\n");
        return;
    }

    int idx;
    printf("Enter the entry number to delete (1 to %d): ", entry_count);
    scanf("%d", &idx);

    if (idx < 1 || idx > entry_count) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = idx - 1; i < entry_count - 1; i++) {
        diary[i] = diary[i + 1]; // Shift entries to the left
    }
    entry_count--;

    printf("Entry %d deleted successfully!\n", idx);
}

void save_to_file() {
    FILE *file = fopen("diary.txt", "w");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "%s: %s", diary[i].date, diary[i].content);
    }

    fclose(file);
    printf("Diary saved successfully to diary.txt\n");
}

void load_from_file() {
    FILE *file = fopen("diary.txt", "r");
    if (!file) {
        printf("No saved diary found. Starting fresh!\n");
        return;
    }

    while (fscanf(file, "%10s: %[^\n]\n", diary[entry_count].date, diary[entry_count].content) != EOF) {
        entry_count++;
        if (entry_count >= MAX_ENTRIES) break; // Prevent overflow
    }

    fclose(file);
    printf("Diary loaded successfully with %d entries!\n", entry_count);
}

void display_menu() {
    printf("\n--- Digital Diary Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Save Diary to File\n");
    printf("5. Load Diary from File\n");
    printf("6. Exit\n");
    printf("--------------------------\n");
}

int main() {
    load_from_file();

    int choice;
    do {
        display_menu();
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
                delete_entry();
                break;
            case 4:
                save_to_file();
                break;
            case 5:
                load_from_file();
                break;
            case 6:
                printf("Exiting the diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}