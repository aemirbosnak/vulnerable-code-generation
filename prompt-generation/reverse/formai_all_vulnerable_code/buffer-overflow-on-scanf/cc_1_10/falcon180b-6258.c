//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[16];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int num_entries = 0;
Entry entries[MAX_ENTRIES];

void add_entry(char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Date\tEntry\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries(char* keyword) {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Search results:\n");
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)) {
            printf("%s\t%s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    char date[16];
    char entry[MAX_ENTRY_LENGTH];

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter entry: ");
                scanf("%s", entry);
                add_entry(date, entry);
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("Enter keyword: ");
                char keyword[MAX_ENTRY_LENGTH];
                scanf("%s", keyword);
                search_entries(keyword);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}