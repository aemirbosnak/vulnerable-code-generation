//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 50

struct entry {
    char name[MAX_ENTRY_LENGTH];
    int calories;
    int distance;
    int time;
};

void add_entry(struct entry *entries, int num_entries, char *name, int calories, int distance, int time) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            entries[i].calories += calories;
            entries[i].distance += distance;
            entries[i].time += time;
            return;
        }
    }
    strcpy(entries[num_entries].name, name);
    entries[num_entries].calories = calories;
    entries[num_entries].distance = distance;
    entries[num_entries].time = time;
    num_entries++;
}

void print_entries(struct entry *entries, int num_entries) {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s: calories = %d, distance = %d, time = %d\n", entries[i].name, entries[i].calories, entries[i].distance, entries[i].time);
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char name[MAX_ENTRY_LENGTH];
    int calories, distance, time;

    while (1) {
        printf("Enter name (or type 'quit' to exit): ");
        scanf("%s", name);
        if (strcmp(name, "quit") == 0) {
            break;
        }
        printf("Enter calories, distance, and time (in minutes): ");
        scanf("%d %d %d", &calories, &distance, &time);
        add_entry(entries, num_entries, name, calories, distance, time);
        num_entries++;
    }

    printf("Fitness tracker results:\n");
    print_entries(entries, num_entries);

    return 0;
}