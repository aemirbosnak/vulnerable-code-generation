//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 512

typedef struct {
    char date[32];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

void add_entry(Entry* entries, int num_entries, char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void view_entries(Entry* entries, int num_entries) {
    printf("Date\tEntry\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries(Entry* entries, int num_entries, char* search_term) {
    printf("Search results:\n");

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, search_term)) {
            printf("%s\t%s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));

    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    add_entry(entries, num_entries, "2022-01-01", "First entry!");
    add_entry(entries, num_entries, "2022-01-02", "Second entry!");
    add_entry(entries, num_entries, "2022-01-03", "Third entry!");

    view_entries(entries, num_entries);

    char search_term[MAX_ENTRY_LENGTH];
    printf("Enter a search term: ");
    scanf("%s", search_term);

    search_entries(entries, num_entries, search_term);

    return 0;
}