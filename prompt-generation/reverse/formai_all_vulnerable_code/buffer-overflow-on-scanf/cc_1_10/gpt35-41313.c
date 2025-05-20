//FormAI DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY_LEN 128
#define MAX_ENTRIES 100

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LEN];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Sorry, you have reached the maximum number of entries.\n");
        return;
    }

    char date[11];
    printf("Enter today's date (yyyy-mm-dd): ");
    scanf("%s", date);

    // Check if entry with given date already exists
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            printf("An entry with this date already exists.\n");
            return;
        }
    }

    char entry[MAX_ENTRY_LEN];
    printf("Enter your diary entry: ");
    getchar(); // consume newline character
    fgets(entry, MAX_ENTRY_LEN, stdin);

    DiaryEntry new_entry;
    strncpy(new_entry.date, date, 11);
    strncpy(new_entry.entry, entry, MAX_ENTRY_LEN);

    entries[entry_count++] = new_entry;
}

void list_entries() {
    for (int i = 0; i < entry_count; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char choice;
    do {
        printf("\n");
        printf("Welcome to Digital Diary!\n");
        printf("1. Add new entry\n");
        printf("2. List all entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_entry();
                break;
            case '2':
                list_entries();
                break;
            case '3':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != '3');

    return 0;
}