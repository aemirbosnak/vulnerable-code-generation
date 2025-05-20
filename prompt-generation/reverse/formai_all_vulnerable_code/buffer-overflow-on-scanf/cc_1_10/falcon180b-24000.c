//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries == MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);

    strftime(entries[num_entries].date, 20, "%Y-%m-%d", timeinfo);
    printf("Date: %s\n", entries[num_entries].date);

    printf("Enter your entry:\n");
    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
    num_entries++;

    printf("Entry added successfully.\n");
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("Date: %s\nEntry:\n%s\n\n", entries[i].date, entries[i].entry);
    }
}

void search_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    char search_term[MAX_ENTRY_LENGTH];
    printf("Enter search term: ");
    fgets(search_term, MAX_ENTRY_LENGTH, stdin);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, search_term)) {
            printf("Date: %s\nEntry:\n%s\n\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    printf("Welcome to Digital Diary!\n");

    while (1) {
        printf("\n1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}