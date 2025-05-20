//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: mathematical
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

void get_current_date(char *buffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(buffer, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add new entry.\n");
        return;
    }

    char date[11];
    get_current_date(date);
    
    printf("Enter your diary entry (max %d characters): ", MAX_LENGTH - 1);
    getchar(); // Clear newline character from buffer
    fgets(diary[entry_count].entry, MAX_LENGTH, stdin);
    
    // Remove newline character if present
    size_t len = strlen(diary[entry_count].entry);
    if (len > 0 && diary[entry_count].entry[len - 1] == '\n') {
        diary[entry_count].entry[len - 1] = '\0';
    }

    strcpy(diary[entry_count].date, date);
    entry_count++;
    printf("Entry added for date: %s\n", date);
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries in the diary yet.\n");
        return;
    }
    
    printf("\nDiary Entries:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }
}

void search_entry() {
    char search_date[11];
    printf("Enter date to search for (YYYY-MM-DD): ");
    scanf("%10s", search_date);
    
    int found = 0;
    printf("\nSearching for entries on: %s\n", search_date);
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(diary[i].date, search_date) == 0) {
            printf("%s: %s\n", diary[i].date, diary[i].entry);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No entries found for date: %s\n", search_date);
    }
}

void delete_entry() {
    char delete_date[11];
    printf("Enter date of the entry to delete (YYYY-MM-DD): ");
    scanf("%10s", delete_date);
    
    int found = 0;
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(diary[i].date, delete_date) == 0) {
            found = 1;
            // Shift entries down to overwrite the deleted entry
            for (int j = i; j < entry_count - 1; j++) {
                diary[j] = diary[j + 1];
            }
            entry_count--;
            printf("Entry on %s deleted successfully!\n", delete_date);
            break;
        }
    }
    
    if (!found) {
        printf("No entry found on date: %s\n", delete_date);
    }
}

void display_menu() {
    printf("\nDiary Menu:\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
    printf("Select an option (1-5): ");
}

int main() {
    int choice;

    do {
        display_menu();
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
            printf("Exiting the diary. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please select from 1 to 5.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}