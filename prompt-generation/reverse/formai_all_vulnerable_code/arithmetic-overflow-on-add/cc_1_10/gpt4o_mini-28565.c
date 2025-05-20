//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000
#define FILENAME "diary_entries.txt"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

// Function declarations
void display_menu();
void add_entry();
void view_entries();
void save_entries();
void load_entries();

int main() {
    load_entries(); // Load any existing diary entries from file
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after integer input

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                save_entries();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void display_menu() {
    printf("\n=== Digital Diary ===\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Save Diary Entries\n");
    printf("4. Exit\n");
}

void add_entry() {
    if (entry_count < MAX_ENTRIES) {
        printf("Enter title: ");
        fgets(diary[entry_count].title, MAX_TITLE_LENGTH, stdin);
        diary[entry_count].title[strcspn(diary[entry_count].title, "\n")] = 0; // Remove newline

        printf("Enter content (Max 1000 chars): ");
        fgets(diary[entry_count].content, MAX_CONTENT_LENGTH, stdin);
        diary[entry_count].content[strcspn(diary[entry_count].content, "\n")] = 0; // Remove newline

        entry_count++;
        printf("Entry added successfully.\n");
    } else {
        printf("Diary is full. Cannot add more entries.\n");
    }
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("\n=== Diary Entries ===\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Entry %d\n", i + 1);
        printf("Title: %s\n", diary[i].title);
        printf("Content: %s\n\n", diary[i].content);
    }
}

void save_entries() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error saving entries to file!\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "Entry %d:\n", i + 1);
        fprintf(file, "Title: %s\n", diary[i].title);
        fprintf(file, "Content: %s\n\n", diary[i].content);
    }
    
    fclose(file);
    printf("Entries saved successfully to %s.\n", FILENAME);
}

void load_entries() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No previous entries found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "Entry %d:\nTitle: %[^\n]\nContent: %[^\n]\n\n", &entry_count, diary[entry_count].title, diary[entry_count].content) == 3) {
        entry_count++;
    }

    fclose(file);
}