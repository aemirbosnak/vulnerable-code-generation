//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

void add_entry(Entry entries[], int num_entries, char date[], char entry[]) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void display_entries(Entry entries[], int num_entries) {
    printf("Digital Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", entries[num_entries].date);

        printf("Enter diary entry:\n");
        fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);

        add_entry(entries, num_entries, entries[num_entries].date, entries[num_entries].entry);

        printf("Press any key to continue...\n");
        getchar();
    }

    return 0;
}