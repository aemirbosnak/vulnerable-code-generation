//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 100

typedef struct {
    char name[MAX_ENTRY_LENGTH];
    int duration;
    int calories;
} Entry;

void add_entry(Entry* entries, int num_entries, char* name, int duration, int calories) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].name, name);
    entries[num_entries].duration = duration;
    entries[num_entries].calories = calories;
    num_entries++;
}

void print_entries(Entry* entries, int num_entries) {
    printf("Total entries: %d\n", num_entries);

    printf("Name\tDuration (sec)\tCalories\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%d\t%d\n", entries[i].name, entries[i].duration, entries[i].calories);
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    printf("Fitness Tracker\n");
    while (1) {
        printf("\nEnter an activity (or 'quit' to exit): ");
        char activity[MAX_ENTRY_LENGTH];
        scanf("%s", activity);

        if (strcmp(activity, "quit") == 0) {
            break;
        }

        printf("Enter activity name: ");
        char name[MAX_ENTRY_LENGTH];
        scanf("%s", name);

        printf("Enter duration (in seconds): ");
        int duration;
        scanf("%d", &duration);

        printf("Enter calories burned: ");
        int calories;
        scanf("%d", &calories);

        add_entry(entries, num_entries, name, duration, calories);
    }

    print_entries(entries, num_entries);

    return 0;
}