//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strncpy(entries[num_entries].date, date, 11);
    strncpy(entries[num_entries].entry, entry, MAX_ENTRY_LENGTH);

    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);

        printf("Enter entry: ");
        fgets(entry, MAX_ENTRY_LENGTH, stdin);

        add_entry(date, entry);

        printf("Entry added.\n");

        char choice;
        printf("Press 'p' to print entries, 'q' to quit: ");
        scanf(" %c", &choice);

        if (choice == 'p') {
            print_entries();
        } else if (choice == 'q') {
            break;
        }
    }

    return 0;
}