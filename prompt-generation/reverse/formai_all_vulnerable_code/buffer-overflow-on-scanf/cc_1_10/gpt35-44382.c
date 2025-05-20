//FormAI DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10  // Maximum entries in the diary

struct diary_entry {
    char date[20];
    char entry[500];
};

struct diary {
    struct diary_entry entries[MAX_ENTRIES];
    int count;
};

void write_entry(struct diary *d) {
    // Prompt user for date and entry
    char date[20];
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", date);

    char entry[500];
    printf("Enter diary entry: ");
    scanf(" %[^\n]s", entry);

    // Create and add new entry to diary
    struct diary_entry new_entry;
    strcpy(new_entry.date, date);
    strcpy(new_entry.entry, entry);
    d->entries[d->count] = new_entry;
    d->count++;

    printf("Entry added successfully!\n\n");
}

void read_entry(struct diary *d) {
    // Prompt user for date to read entry
    char date[20];
    printf("Enter date to read (MM/DD/YYYY): ");
    scanf("%s", date);

    // Search for entry with matching date
    int i;
    for (i = 0; i < d->count; i++) {
        if (strcmp(d->entries[i].date, date) == 0) {
            printf("%s\n\n", d->entries[i].entry);
            return;
        }
    }

    // If no entry is found, print error message
    printf("Entry not found for date %s\n\n", date);
}

void print_menu() {
    printf("Digital Diary Menu:\n");
    printf("1. Write new entry\n");
    printf("2. Read previous entry\n");
    printf("3. Exit\n");
}

int main() {
    // Initialize diary with 0 entries
    struct diary my_diary;
    my_diary.count = 0;

    int choice;
    do {
        print_menu();
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                write_entry(&my_diary);
                break;
            case 2:
                read_entry(&my_diary);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Choice. Try again!\n\n");
        }
    } while (choice != 3);

    return 0;
}