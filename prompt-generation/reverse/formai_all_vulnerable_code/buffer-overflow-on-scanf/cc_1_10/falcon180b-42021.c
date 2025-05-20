//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[16];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char date_str[16];
    time_t now = time(NULL);
    strftime(date_str, sizeof(date_str), "%Y-%m-%d", localtime(&now));

    printf("Enter your diary entry for %s:\n", date_str);
    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);

    strcpy(entries[num_entries].date, date_str);
    num_entries++;
}

void view_entries() {
    printf("Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries(char* keyword) {
    printf("Search Results:\n");
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)) {
            printf("%s: %s\n", entries[i].date, entries[i].entry);
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
        printf("Choose an option: ");
        scanf(" %c", &choice);

        switch (choice) {
        case 'A':
            add_entry();
            break;
        case 'V':
            view_entries();
            break;
        case 'S':
            printf("Enter keyword to search: ");
            char keyword[MAX_ENTRY_LENGTH];
            fgets(keyword, MAX_ENTRY_LENGTH, stdin);
            search_entries(keyword);
            break;
        case 'Q':
            exit(0);
        default:
            printf("Invalid option. Try again.\n");
        }
    } while (1);

    return 0;
}