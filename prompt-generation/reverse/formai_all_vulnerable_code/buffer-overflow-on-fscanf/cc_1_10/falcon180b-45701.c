//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
// Digital Diary in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_SIZE 5000

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_SIZE];
} Entry;

int compare_dates(const void* a, const void* b) {
    Entry* entry_a = (Entry*) a;
    Entry* entry_b = (Entry*) b;
    return strcmp(entry_a->date, entry_b->date);
}

int main() {
    FILE* diary_file = fopen("diary.txt", "r");
    if (diary_file == NULL) {
        printf("Diary file not found. Creating new file.\n");
        diary_file = fopen("diary.txt", "w");
        if (diary_file == NULL) {
            printf("Error creating diary file.\n");
            return 1;
        }
    }

    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (fscanf(diary_file, "%s %s\n", entries[num_entries].date, entries[num_entries].entry) == 2) {
        num_entries++;
        if (num_entries == MAX_ENTRIES) {
            printf("Diary is full. Cannot add more entries.\n");
            break;
        }
    }

    fclose(diary_file);

    qsort(entries, num_entries, sizeof(Entry), compare_dates);

    diary_file = fopen("diary.txt", "w");
    if (diary_file == NULL) {
        printf("Error creating diary file.\n");
        return 1;
    }

    for (int i = 0; i < num_entries; i++) {
        fprintf(diary_file, "%s %s\n", entries[i].date, entries[i].entry);
    }

    fclose(diary_file);

    return 0;
}

// End of Digital Diary in C