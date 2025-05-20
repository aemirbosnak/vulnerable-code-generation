//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 50
#define MAX_CONTENT_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    time_t created_at;
} DiaryEntry;

void add_entry(DiaryEntry *entries, int *count);
void view_entries(DiaryEntry *entries, int count);
void delete_entry(DiaryEntry *entries, int *count);
void list_entries(DiaryEntry *entries, int count);
void clear_screen();

void clear_screen() {
    #ifdef __linux__
    system("clear");
    #elif _WIN32
    system("cls");
    #endif
}

void add_entry(DiaryEntry *entries, int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    clear_screen();
    
    printf("Enter the title of the diary entry: ");
    fgets(entries[*count].title, MAX_TITLE_LENGTH, stdin);
    entries[*count].title[strcspn(entries[*count].title, "\n")] = 0; // Remove newline

    printf("Enter the content of the diary entry: ");
    fgets(entries[*count].content, MAX_CONTENT_LENGTH, stdin);
    entries[*count].content[strcspn(entries[*count].content, "\n")] = 0; // Remove newline

    entries[*count].created_at = time(NULL);
    (*count)++;
    
    printf("Entry added successfully!\nPress Enter to continue...");
    getchar();
}

void view_entries(DiaryEntry *entries, int count) {
    clear_screen();

    if (count == 0) {
        printf("No diary entries available.\n");
    } else {
        printf("Diary Entries:\n");
        for (int i = 0; i < count; i++) {
            printf("\nEntry %d:\n", i + 1);
            printf("Title: %s\n", entries[i].title);
            printf("Content: %s\n", entries[i].content);
            printf("Created At: %s", ctime(&entries[i].created_at));
        }
    }
    printf("\nPress Enter to continue...");
    getchar();
}

void delete_entry(DiaryEntry *entries, int *count) {
    clear_screen();
    
    if (*count == 0) {
        printf("No diary entries to delete.\n");
        printf("Press Enter to continue...");
        getchar();
        return;
    }

    list_entries(entries, *count);
    
    printf("Enter the entry number to delete: ");
    int entry_num;
    scanf("%d", &entry_num);
    getchar(); // Consume newline

    if (entry_num < 1 || entry_num > *count) {
        printf("Invalid entry number!\n");
    } else {
        for (int i = entry_num - 1; i < *count - 1; i++) {
            entries[i] = entries[i + 1];
        }
        (*count)--;
        printf("Entry deleted successfully!\n");
    }
    printf("Press Enter to continue...");
    getchar();
}

void list_entries(DiaryEntry *entries, int count) {
    printf("Available Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("Entry %d: %s\n", i + 1, entries[i].title);
    }
    printf("\n");
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    do {
        clear_screen();
        printf("Digital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                add_entry(entries, &count);
                break;
            case 2:
                view_entries(entries, count);
                break;
            case 3:
                delete_entry(entries, &count);
                break;
            case 4:
                printf("Exiting the diary program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                printf("Press Enter to continue...");
                getchar();
                break;
        }
    } while (choice != 4);

    return 0;
}