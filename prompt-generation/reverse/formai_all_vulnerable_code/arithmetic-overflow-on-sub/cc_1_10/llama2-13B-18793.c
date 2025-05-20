//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DAY_LENGTH 24 * 60 * 60
#define MAX_ENTRIES 30

typedef struct {
    char date[20];
    char entry[100];
} entry_t;

entry_t entries[MAX_ENTRIES];
int cur_entry = 0;

void init_digital_diary() {
    clock_t start_time = clock();
    for (int i = 0; i < MAX_ENTRIES; i++) {
        entries[i].date[0] = '\0';
        entries[i].entry[0] = '\0';
    }
    printf("Digital Diary initialized in %lf seconds\n",
           (double)(clock() - start_time) / CLOCKS_PER_SEC);
}

void add_entry(char *date, char *entry) {
    if (cur_entry >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached\n");
        return;
    }
    strcpy(entries[cur_entry].date, date);
    strcpy(entries[cur_entry].entry, entry);
    cur_entry++;
    printf("Entry added: %s - %s\n", date, entry);
}

void view_entries() {
    for (int i = 0; i < cur_entry; i++) {
        printf("%d. %s - %s\n", i + 1, entries[i].date, entries[i].entry);
    }
    printf("Total number of entries: %d\n", cur_entry);
}

int main() {
    init_digital_diary();

    char date[20];
    char entry[100];

    // Add entries
    add_entry("2023-02-20", "Went to the park and saw a squirrel");
    add_entry("2023-02-21", "Had a productive day at work");
    add_entry("2023-02-22", "Cooked dinner for my family");

    // View entries
    view_entries();

    return 0;
}