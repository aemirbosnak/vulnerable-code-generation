//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 1024
#define DATE_LENGTH 20

typedef struct {
    char date[DATE_LENGTH];
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(diary[entry_count].date, sizeof(diary[entry_count].date), "%Y-%m-%d %H:%M:%S", t);
    
    printf("Write your diary entry (max %d characters):\n", ENTRY_LENGTH);
    getchar(); // Clear the buffer
    fgets(diary[entry_count].entry, ENTRY_LENGTH, stdin);
    
    // Remove newline character added by fgets
    size_t len = strlen(diary[entry_count].entry);
    if (len > 0 && diary[entry_count].entry[len - 1] == '\n') {
        diary[entry_count].entry[len - 1] = '\0';
    }
    
    entry_count++;
    printf("Entry added on %s\n", diary[entry_count - 1].date);
}

void view_entries() {
    if (entry_count == 0) {
        printf("No diary entries found.\n");
        return;
    }
    
    printf("\n--- Your Diary Entries ---\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Entry %d - %s\n", i + 1, diary[i].date);
        printf("%s\n\n", diary[i].entry);
    }
    printf("---------------------------\n");
}

void search_entry() {
    char keyword[ENTRY_LENGTH];
    printf("Enter a keyword to search: ");
    getchar(); // Clear the buffer
    fgets(keyword, ENTRY_LENGTH, stdin);
    
    // Remove newline character
    size_t len = strlen(keyword);
    if (len > 0 && keyword[len - 1] == '\n') {
        keyword[len - 1] = '\0';
    }

    printf("\n--- Search Results for '%s' ---\n", keyword);
    int found = 0;
    for (int i = 0; i < entry_count; i++) {
        if (strstr(diary[i].entry, keyword) != NULL) {
            printf("Entry %d - %s\n", i + 1, diary[i].date);
            printf("%s\n\n", diary[i].entry);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found with that keyword.\n");
    }
    printf("---------------------------------\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\n=== Welcome to Your Digital Diary ===\n");
        printf("1. Add a Diary Entry\n");
        printf("2. View All Entries\n");
        printf("3. Search Entries\n");
        printf("4. Exit\n");
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
                printf("Exiting the diary. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}