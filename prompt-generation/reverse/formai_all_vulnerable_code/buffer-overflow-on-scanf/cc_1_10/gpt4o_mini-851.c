//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11];
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void display_menu() {
    printf("\n=== Sherlock's Digital Diary ===\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entry\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Enter your diary entry: ");
    getchar();  // to capture the newline character from previous inputs
    fgets(diary[entry_count].entry, MAX_LENGTH, stdin);
    diary[entry_count].entry[strcspn(diary[entry_count].entry, "\n")] = 0;  // Remove newline character

    snprintf(diary[entry_count].date, sizeof(diary[entry_count].date), "%04d-%02d-%02d", 
             tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    entry_count++;
    printf("Entry added on %s\n", diary[entry_count - 1].date);
}

void view_entries() {
    printf("\n=== Your Entries ===\n");
    if (entry_count == 0) {
        printf("No entries found.\n");
        return;
    }
    for (int i = 0; i < entry_count; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n\n", diary[i].entry);
    }
}

void search_entry() {
    char search_term[MAX_LENGTH];
    printf("Enter search term: ");
    getchar();  // to capture the newline character
    fgets(search_term, MAX_LENGTH, stdin);
    search_term[strcspn(search_term, "\n")] = 0;  // Remove newline character

    printf("\n=== Search Results ===\n");
    int found = 0;
    for (int i = 0; i < entry_count; i++) {
        if (strstr(diary[i].entry, search_term) != NULL) {
            printf("Found on %s: %s\n", diary[i].date, diary[i].entry);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries matched your search.\n");
    }
}

int main() {
    int choice;

    while (1) {
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
                printf("Exiting the diary. Until next time, Watson!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}