//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 100

struct entry {
    char name[MAX_ENTRY_LENGTH];
    int calories;
    int steps;
    int distance;
    int time;
};

void add_entry(struct entry* entries, int* num_entries) {
    printf("Enter the name of the activity:\n");
    scanf("%s", entries[*num_entries].name);

    printf("Enter the calories burned:\n");
    scanf("%d", &entries[*num_entries].calories);

    printf("Enter the number of steps taken:\n");
    scanf("%d", &entries[*num_entries].steps);

    printf("Enter the distance covered (in meters):\n");
    scanf("%d", &entries[*num_entries].distance);

    printf("Enter the duration of the activity (in seconds):\n");
    scanf("%d", &entries[*num_entries].time);

    (*num_entries)++;
}

void display_entries(struct entry* entries, int num_entries) {
    printf("Name\tCalories\tSteps\tDistance\tTime\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n", entries[i].name, entries[i].calories, entries[i].steps, entries[i].distance, entries[i].time);
    }
}

void sort_entries(struct entry* entries, int num_entries) {
    for (int i = 0; i < num_entries - 1; i++) {
        for (int j = i + 1; j < num_entries; j++) {
            if (entries[j].calories > entries[i].calories) {
                struct entry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (num_entries < MAX_ENTRIES) {
        add_entry(entries, &num_entries);
    }

    printf("Unsorted entries:\n");
    display_entries(entries, num_entries);

    sort_entries(entries, num_entries);

    printf("\nSorted entries:\n");
    display_entries(entries, num_entries);

    return 0;
}