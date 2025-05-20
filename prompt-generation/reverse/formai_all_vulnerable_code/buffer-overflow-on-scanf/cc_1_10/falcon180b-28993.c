//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
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
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s\t%s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    char input[100];
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    while (1) {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");

        scanf("%s", input);

        switch (input[0]) {
            case '1':
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter entry:\n");
                fgets(entry, MAX_ENTRY_LENGTH, stdin);
                entry[strcspn(entry, "\n")] = '\0';
                add_entry(date, entry);
                break;
            case '2':
                view_entries();
                break;
            case '3':
                printf("Enter keyword to search: ");
                scanf("%s", input);
                search_entries(input);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}