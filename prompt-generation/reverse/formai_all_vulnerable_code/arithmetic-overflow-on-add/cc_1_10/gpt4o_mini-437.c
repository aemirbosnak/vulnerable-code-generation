//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 512

typedef struct {
    char date[11]; // To store the date in YYYY-MM-DD format
    char content[MAX_LENGTH]; // To store the diary entry
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    
    DiaryEntry new_entry;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(new_entry.date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    printf("Enter your diary entry (limit: %d characters):\n", MAX_LENGTH - 1);
    getchar(); // To clear the newline left in the buffer
    fgets(new_entry.content, MAX_LENGTH, stdin);
    
    // Remove the newline character at the end of the input
    new_entry.content[strcspn(new_entry.content, "\n")] = 0;

    diary[entry_count++] = new_entry;
    printf("Entry added for date: %s\n", new_entry.date);
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries found in the diary.\n");
        return;
    }

    printf("Viewing diary entries:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].content);
        printf("-------------------------\n");
    }
}

void search_entry() {
    char keyword[MAX_LENGTH];
    printf("Enter a keyword to search in diary entries:\n");
    getchar(); // To clear the newline left in the buffer
    fgets(keyword, MAX_LENGTH, stdin);
    
    // Remove the newline character at the end of the input
    keyword[strcspn(keyword, "\n")] = 0;

    printf("Searching for entries containing: '%s'\n", keyword);
    int found = 0;
    
    for (int i = 0; i < entry_count; i++) {
        if (strstr(diary[i].content, keyword) != NULL) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n", diary[i].content);
            printf("-------------------------\n");
            found = 1;
        }
    }
    
    if (!found) {
        printf("No entries found containing the keyword '%s'.\n", keyword);
    }
}

void delete_entry() {
    if (entry_count == 0) {
        printf("No entries to delete.\n");
        return;
    }
    
    int entry_index;
    printf("Enter the entry number to delete (1-%d):\n", entry_count);
    scanf("%d", &entry_index);

    if (entry_index < 1 || entry_index > entry_count) {
        printf("Invalid entry number.\n");
        return;
    }
    
    // Shift entries to fill the deleted entry's position
    for (int i = entry_index - 1; i < entry_count - 1; i++) {
        diary[i] = diary[i + 1];
    }
    
    entry_count--;
    printf("Entry number %d deleted successfully.\n", entry_index);
}

void display_menu() {
    printf("Welcome to the Digital Diary\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Search Diary Entry\n");
    printf("4. Delete Diary Entry\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    
    while (1) {
        display_menu();
        printf("Enter your choice (1-5): ");
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
                delete_entry();
                break;
            case 5:
                printf("Exiting the Digital Diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}