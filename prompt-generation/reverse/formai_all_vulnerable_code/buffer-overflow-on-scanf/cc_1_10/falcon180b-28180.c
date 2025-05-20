//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

// Structure to hold each diary entry
typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

// Function to compare two entries by date
int compare_entries(const void *a, const void *b) {
    Entry *entry1 = (Entry *)a;
    Entry *entry2 = (Entry *)b;
    return strcmp(entry1->date, entry2->date);
}

// Function to print all entries in the diary
void print_entries(Entry *entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

// Function to add a new entry to the diary
void add_entry(Entry *entries, int *num_entries) {
    char date[11];
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", date);

    char entry[MAX_ENTRY_LENGTH];
    printf("Enter entry: ");
    scanf("%[^\n]", entry);

    strcpy(entries[*num_entries].date, date);
    strcpy(entries[*num_entries].entry, entry);

    (*num_entries)++;
}

// Function to search for an entry by date
int search_entry(Entry *entries, int num_entries, char *date) {
    qsort(entries, num_entries, sizeof(Entry), compare_entries);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    // Initialize diary with some entries
    add_entry(entries, &num_entries);
    add_entry(entries, &num_entries);
    add_entry(entries, &num_entries);

    // Print all entries
    print_entries(entries, num_entries);

    // Search for an entry by date
    char search_date[11];
    printf("Enter date to search: ");
    scanf("%s", search_date);

    int index = search_entry(entries, num_entries, search_date);
    if (index!= -1) {
        printf("Entry found on %s:\n%s\n", entries[index].date, entries[index].entry);
    } else {
        printf("Entry not found.\n");
    }

    return 0;
}