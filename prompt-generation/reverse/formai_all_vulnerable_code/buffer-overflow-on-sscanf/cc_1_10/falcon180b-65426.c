//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[100];
    int time;
    int distance;
    int calories;
} Entry;

int compare(const void *a, const void *b) {
    const Entry *entry1 = a;
    const Entry *entry2 = b;
    if (entry1->time > entry2->time) {
        return -1;
    } else if (entry1->time < entry2->time) {
        return 1;
    } else {
        return 0;
    }
}

void print_entry(const Entry *entry) {
    printf("%s: %d minutes, %d distance, %d calories\n", entry->name, entry->time, entry->distance, entry->calories);
}

void print_entries(Entry *entries, int count) {
    printf("Total entries: %d\n", count);
    qsort(entries, count, sizeof(Entry), compare);
    for (int i = 0; i < count; i++) {
        print_entry(&entries[i]);
    }
}

int main() {
    char input[1000];
    Entry entries[MAX_ENTRIES];
    int count = 0;

    while (1) {
        printf("Enter fitness activity (quit to exit):\n");
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        Entry entry;
        sscanf(input, "%s %d minutes %d distance %d calories", entry.name, &entry.time, &entry.distance, &entry.calories);
        if (count >= MAX_ENTRIES) {
            printf("Maximum entries reached!\n");
        } else {
            strcpy(entries[count].name, entry.name);
            entries[count].time = entry.time;
            entries[count].distance = entry.distance;
            entries[count].calories = entry.calories;
            count++;
        }
    }

    print_entries(entries, count);

    return 0;
}