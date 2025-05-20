//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    Entry new_entry;
    memset(&new_entry, 0, sizeof(Entry));

    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    strftime(new_entry.date, sizeof(new_entry.date), "%Y-%m-%d", tm);

    printf("Enter your entry:\n");
    fgets(new_entry.entry, sizeof(new_entry.entry), stdin);

    strtok(new_entry.entry, "\n");

    entries[num_entries++] = new_entry;

    printf("Entry added successfully.\n");
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries() {
    char query[MAX_ENTRY_LENGTH];

    printf("Enter query:\n");
    fgets(query, sizeof(query), stdin);

    strtok(query, " ");

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, query)) {
            printf("%s - %s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    int choice;

    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}