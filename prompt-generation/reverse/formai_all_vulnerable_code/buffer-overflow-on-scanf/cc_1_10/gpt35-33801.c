//FormAI DATASET v1.0 Category: Digital Diary ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRY_LENGTH 500
#define MAX_ENTRIES 100

typedef struct DiaryEntry {
    char date[11]; // format: YYYY-MM-DD
    char time[6]; // format: HH:MM
    char content[MAX_ENTRY_LENGTH];
} DiaryEntry;

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void add_entry(DiaryEntry* entries, int* num_entries) {
    if (*num_entries >= MAX_ENTRIES) {
        printf("Diary is full.");
        return;
    }
    DiaryEntry new_entry;
    printf("Enter date (YYYY-MM-DD): ");
    fgets(new_entry.date, sizeof(new_entry.date), stdin);
    printf("Enter time (HH:MM): ");
    fgets(new_entry.time, sizeof(new_entry.time), stdin);
    printf("Enter content (max %d characters):\n", MAX_ENTRY_LENGTH);
    fgets(new_entry.content, sizeof(new_entry.content), stdin);
    // remove the newline character at the end of each input string
    new_entry.date[strcspn(new_entry.date, "\n")] = 0;
    new_entry.time[strcspn(new_entry.time, "\n")] = 0;
    new_entry.content[strcspn(new_entry.content, "\n")] = 0;
    entries[*num_entries] = new_entry;
    (*num_entries)++;
}

void print_entry(DiaryEntry entry) {
    printf("\n");
    printf("Date: %s\n", entry.date);
    printf("Time: %s\n", entry.time);
    printf("Content: %s\n", entry.content);
}

void print_all_entries(DiaryEntry* entries, int num_entries) {
    if (num_entries == 0) {
        printf("Diary is empty.");
        return;
    }
    for (int i = 0; i < num_entries; i++) {
        print_entry(entries[i]);
    }
}

void menu() {
    printf("\n");
    printf("1- Add new entry\n");
    printf("2- View all entries\n");
    printf("3- Exit\n");
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;
    do {
        menu();
        printf("Enter choice (1-3): ");
        scanf("%d", &choice);
        clear_input_buffer();
        switch (choice) {
            case 1:
                add_entry(entries, &num_entries);
                break;
            case 2:
                print_all_entries(entries, num_entries);
                break;
            case 3:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice.");
                break;
        }
    } while (choice != 3);
    return 0;
}