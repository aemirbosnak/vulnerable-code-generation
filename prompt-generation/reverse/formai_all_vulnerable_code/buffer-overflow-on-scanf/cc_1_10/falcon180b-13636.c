//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    int id;
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int num_entries = 0;
Entry entries[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Cannot add more entries.\n");
        return;
    }

    Entry new_entry;
    printf("Enter entry ID (0-9): ");
    scanf("%d", &new_entry.id);

    time_t now = time(NULL);
    strftime(new_entry.date, 20, "%Y-%m-%d", localtime(&now));

    printf("Enter entry (up to %d characters): ", MAX_ENTRY_LENGTH);
    fgets(new_entry.entry, MAX_ENTRY_LENGTH, stdin);
    new_entry.entry[strcspn(new_entry.entry, "\n")] = '\0';

    entries[num_entries++] = new_entry;
    printf("Entry added.\n");
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries to view.\n");
        return;
    }

    printf("ID   Date        Entry\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%-3d %s      %s\n", entries[i].id, entries[i].date, entries[i].entry);
    }
}

void search_entries() {
    char search_term[MAX_ENTRY_LENGTH];
    printf("Enter search term: ");
    scanf("%s", search_term);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, search_term)) {
            printf("ID: %d\nDate: %s\nEntry: %s\n", entries[i].id, entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    printf("Digital Diary\n");
    while (1) {
        printf("\nOptions:\n1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            view_entries();
            break;
        case 3:
            search_entries();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}