//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
        printf("Error: Cannot add more entries.\n");
        return;
    }

    char date[20];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(date, 20, "%Y-%m-%d", t);

    printf("Enter your diary entry for %s:\n", date);
    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
    strcpy(entries[num_entries].date, date);
    num_entries++;
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries(char *keyword) {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Search Results:\n");
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s: %s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    char choice;

    do {
        printf("Digital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Search Entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                add_entry();
                break;
            case '2':
                view_entries();
                break;
            case '3':
                printf("Enter keyword to search: ");
                char keyword[MAX_ENTRY_LENGTH];
                fgets(keyword, MAX_ENTRY_LENGTH, stdin);
                search_entries(keyword);
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '4');

    return 0;
}