//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 50

typedef struct {
    char date[11];
    char activity[MAX_ENTRY_LENGTH];
    int duration;
    int calories;
} Entry;

int compare_dates(const void* a, const void* b) {
    Entry* entry_a = (Entry*)a;
    Entry* entry_b = (Entry*)b;
    time_t time_a = mktime(strptime(entry_a->date, "%Y-%m-%d"));
    time_t time_b = mktime(strptime(entry_b->date, "%Y-%m-%d"));
    return difftime(time_a, time_b);
}

int main() {
    FILE* file = fopen("fitness_tracker.txt", "a+");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    int num_entries = 0;
    Entry entries[MAX_ENTRIES];
    while (fscanf(file, "%s %s %d %d\n", entries[num_entries].date, entries[num_entries].activity, &entries[num_entries].duration, &entries[num_entries].calories)!= EOF) {
        num_entries++;
        if (num_entries >= MAX_ENTRIES) {
            fprintf(stderr, "Maximum number of entries reached\n");
            exit(1);
        }
    }

    fclose(file);

    qsort(entries, num_entries, sizeof(Entry), compare_dates);

    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s (%d minutes, %d calories)\n", entries[i].date, entries[i].activity, entries[i].duration, entries[i].calories);
    }

    return 0;
}