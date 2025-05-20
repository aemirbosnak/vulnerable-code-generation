//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 512

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char content[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

// Function prototypes
void display_menu();
void add_entry();
void view_entries();
void save_diary();
void load_diary();
void clear_buffer();

int main() {
    int choice;

    load_diary();

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_buffer(); // Clears the input buffer

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                save_diary();
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

void display_menu() {
    printf("\n--------------------\n");
    printf("   Digital Diary    \n");
    printf("--------------------\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Save Diary\n");
    printf("4. Exit\n");
    printf("--------------------\n");
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Remove some entries before adding new ones.\n");
        return;
    }

    printf("Enter your diary entry:\n");
    fgets(diary[entry_count].content, MAX_LENGTH, stdin);

    // Get Current Date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(diary[entry_count].date, sizeof(diary[entry_count].date), "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    entry_count++;
    printf("Diary entry added on %s\n", diary[entry_count - 1].date);
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries found in the diary.\n");
        return;
    }

    printf("\n----- Diary Entries -----\n");
    for (int i = 0; i < entry_count; i++) {
        printf("[%d] %s : %s", i + 1, diary[i].date, diary[i].content);
    }
    printf("\n-------------------------\n");
}

void save_diary() {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Error saving diary!\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "%s : %s", diary[i].date, diary[i].content);
    }

    fclose(file);
    printf("Diary saved successfully!\n");
}

void load_diary() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No diary file found. Starting a new diary.\n");
        return;
    }

    while (fscanf(file, "%10s : %[^\n]\n", diary[entry_count].date, diary[entry_count].content) != EOF) {
        entry_count++;
        if (entry_count >= MAX_ENTRIES) {
            printf("Maximum entries reached while loading the diary.\n");
            break;
        }
    }

    fclose(file);
    printf("Diary loaded successfully! You have %d entries.\n", entry_count);
}

void clear_buffer() {
    while (getchar() != '\n');
}