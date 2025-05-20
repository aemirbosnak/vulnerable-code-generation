//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", entries[num_entries].date);

    printf("Enter entry:\n");
    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);

    num_entries++;
}

void view_entries() {
    printf("Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries() {
    char search_term[MAX_ENTRY_LENGTH];

    printf("Enter search term:\n");
    fgets(search_term, MAX_ENTRY_LENGTH, stdin);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, search_term)) {
            printf("%s: %s\n", entries[i].date, entries[i].entry);
        }
    }
}

void delete_entry() {
    printf("Enter date to delete entry (YYYY-MM-DD): ");
    char date[20];
    scanf("%s", date);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(date, entries[i].date) == 0) {
            memmove(&entries[i], &entries[i + 1], sizeof(entry_t) * (num_entries - i - 1));
            num_entries--;
            break;
        }
    }
}

int main() {
    printf("Digital Diary\n");

    while (1) {
        printf("\n1. Add entry\n2. View entries\n3. Search entries\n4. Delete entry\n0. Exit\n");
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
                delete_entry();
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}