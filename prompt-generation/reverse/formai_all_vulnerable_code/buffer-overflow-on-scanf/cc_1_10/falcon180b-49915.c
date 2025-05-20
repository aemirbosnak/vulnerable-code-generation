//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

int num_entries = 0;
entry_t entries[MAX_ENTRIES];

void add_entry(char *date, char *entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strncpy(entries[num_entries].date, date, 11);
    strncpy(entries[num_entries].entry, entry, MAX_ENTRY_LENGTH);

    num_entries++;
}

void print_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char input[MAX_ENTRY_LENGTH];

    while (1) {
        printf("Enter a date (YYYY-MM-DD): ");
        scanf("%s", input);

        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        char date[11];
        strftime(date, 11, "%Y-%m-%d", t);

        printf("Enter your entry:\n");
        fgets(input, MAX_ENTRY_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        add_entry(date, input);
    }

    return 0;
}