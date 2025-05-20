//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char time[10];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

int num_entries = 0;
diary_entry entries[MAX_ENTRIES];

void add_entry() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(entries[num_entries].date, 20, "%Y-%m-%d", t);
    strftime(entries[num_entries].time, 10, "%H:%M:%S", t);

    printf("Enter your diary entry:\n");
    scanf("%[^\n]", entries[num_entries].entry);
    entries[num_entries].entry[strcspn(entries[num_entries].entry, "\n")] = '\0';

    num_entries++;
}

void view_entries() {
    printf("Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

void search_entries(char *keyword) {
    printf("Search Results:\n");
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)) {
            printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].entry);
        }
    }
}

int main() {
    char choice;

    do {
        printf("Digital Diary\n");
        printf("A - Add Entry\n");
        printf("V - View Entries\n");
        printf("S - Search Entries\n");
        printf("Q - Quit\n");
        scanf(" %c", &choice);

        switch (choice) {
        case 'A':
            add_entry();
            break;
        case 'V':
            view_entries();
            break;
        case 'S':
            printf("Enter keyword to search:\n");
            char keyword[MAX_ENTRY_LENGTH];
            scanf("%[^\n]", keyword);
            search_entries(keyword);
            break;
        case 'Q':
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 'Q');

    return 0;
}