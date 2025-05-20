//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 512
#define DATE_LENGTH 20

typedef struct DiaryEntry {
    char date[DATE_LENGTH];
    char content[ENTRY_LENGTH];
} DiaryEntry;

diary_entry_t;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    time_t now;
    time(&now);
    strftime(diary[entry_count].date, DATE_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&now));

    printf("Enter your diary entry: ");
    getchar(); // Clear the newline from previous input
    fgets(diary[entry_count].content, ENTRY_LENGTH, stdin);
    diary[entry_count].content[strcspn(diary[entry_count].content, "\n")] = 0; // Remove newline

    printf("Entry added on %s\n", diary[entry_count].date);
    entry_count++;
}

void view_entries() {
    if (entry_count == 0) {
        printf("Your diary is empty.\n");
        return;
    }

    printf("\n--- Diary Entries ---\n");
    for (int i = 0; i < entry_count; i++) {
        printf("[%d] %s\n", i + 1, diary[i].date);
        printf("%s\n\n", diary[i].content);
    }
}

void search_entries() {
    char search_term[ENTRY_LENGTH];
    printf("Enter a search term: ");
    getchar(); // Clear the newline from previous input
    fgets(search_term, ENTRY_LENGTH, stdin);
    search_term[strcspn(search_term, "\n")] = 0; // Remove newline

    int found = 0;
    printf("\n--- Search Results for '%s' ---\n", search_term);
    for (int i = 0; i < entry_count; i++) {
        if (strstr(diary[i].content, search_term) != NULL) {
            printf("[%d] %s\n", i + 1, diary[i].date);
            printf("%s\n\n", diary[i].content);
            found++;
        }
    }

    if (found == 0)
        printf("No entries found containing '%s'.\n", search_term);
}

void delete_entry() {
    int entry_num;
    printf("Enter entry number to delete: ");
    scanf("%d", &entry_num);

    if (entry_num < 1 || entry_num > entry_count) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = entry_num - 1; i < entry_count - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entry_count--;
    printf("Entry %d deleted successfully.\n", entry_num);
}

void save_to_file() {
    FILE *file = fopen("diary.txt", "w");
    if (!file) {
        printf("Could not open file for saving.\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "[%s] %s\n\n", diary[i].date, diary[i].content);
    }
    fclose(file);
    printf("Diary saved to diary.txt successfully.\n");
}

void load_from_file() {
    FILE *file = fopen("diary.txt", "r");
    if (!file) {
        printf("No saved diary found.\n");
        return;
    }

    while (fgets(diary[entry_count].date, DATE_LENGTH, file) && fgets(diary[entry_count].content, ENTRY_LENGTH, file)) {
        strcspn(diary[entry_count].content, "\n"); // Remove newline
        entry_count++;
        if (entry_count >= MAX_ENTRIES) break;
    }
    fclose(file);
    printf("Diary loaded successfully. %d entries found.\n", entry_count);
}

void display_menu() {
    printf("\n--- Digital Diary ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entries\n");
    printf("4. Delete Entry\n");
    printf("5. Save to File\n");
    printf("6. Load from File\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    load_from_file();

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_entry(); break;
            case 2: view_entries(); break;
            case 3: search_entries(); break;
            case 4: delete_entry(); break;
            case 5: save_to_file(); break;
            case 6: load_from_file(); break;
            case 7: printf("Exiting the diary application. Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}