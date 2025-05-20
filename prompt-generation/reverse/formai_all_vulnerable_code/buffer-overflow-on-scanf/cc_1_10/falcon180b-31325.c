//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 50

typedef struct {
    char exercise[50];
    int duration;
    int calories;
} Entry;

void add_entry(Entry entries[], int num_entries, char exercise[], int duration, int calories) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].exercise, exercise);
    entries[num_entries].duration = duration;
    entries[num_entries].calories = calories;

    num_entries++;
}

void print_entries(Entry entries[], int num_entries) {
    printf("Total number of entries: %d\n", num_entries);
    printf("Exercise\tDuration (min)\tCalories\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%d\t%d\n", entries[i].exercise, entries[i].duration, entries[i].calories);
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    char exercise[50];
    int duration, calories;

    while (1) {
        printf("Enter exercise name: ");
        scanf("%s", exercise);

        printf("Enter duration (in minutes): ");
        scanf("%d", &duration);

        printf("Enter calories burned: ");
        scanf("%d", &calories);

        add_entry(entries, num_entries, exercise, duration, calories);

        printf("Do you want to enter another exercise? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    print_entries(entries, num_entries);

    return 0;
}