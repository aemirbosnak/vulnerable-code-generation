//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[20];
    char entry[MAX_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *date, char *entry) {
    entry_t new_entry;
    strcpy(new_entry.date, date);
    strcpy(new_entry.entry, entry);
    if (num_entries < MAX_ENTRIES) {
        entries[num_entries++] = new_entry;
    }
}

void print_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);

    // Ask user for date and entry
    printf("Enter date (mm/dd/yy): ");
    char date[20];
    scanf("%19s", date);
    printf("Enter entry: ");
    char entry[MAX_LENGTH];
    scanf("%s", entry);

    // Add entry to diary
    add_entry(date, entry);

    // Print all entries
    print_entries();

    return 0;
}