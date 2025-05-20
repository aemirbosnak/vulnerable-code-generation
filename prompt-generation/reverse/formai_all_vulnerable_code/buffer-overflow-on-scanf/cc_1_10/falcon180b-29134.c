//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int calories_burned;
    int steps_taken;
    int distance_traveled;
    int duration;
} Entry;

void add_entry(Entry entries[], int num_entries, char name[], int calories_burned, int steps_taken, int distance_traveled, int duration) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached\n");
        return;
    }

    strcpy(entries[num_entries].name, name);
    entries[num_entries].calories_burned = calories_burned;
    entries[num_entries].steps_taken = steps_taken;
    entries[num_entries].distance_traveled = distance_traveled;
    entries[num_entries].duration = duration;

    num_entries++;
}

void display_entries(Entry entries[], int num_entries) {
    printf("Name\tCalories Burned\tSteps Taken\tDistance Traveled\tDuration\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n", entries[i].name, entries[i].calories_burned, entries[i].steps_taken, entries[i].distance_traveled, entries[i].duration);
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    char name[MAX_NAME_LENGTH];
    int calories_burned, steps_taken, distance_traveled, duration;

    while (1) {
        printf("Enter name of activity (up to %d characters): ", MAX_NAME_LENGTH - 1);
        scanf("%s", name);

        printf("Enter calories burned: ");
        scanf("%d", &calories_burned);

        printf("Enter steps taken: ");
        scanf("%d", &steps_taken);

        printf("Enter distance traveled (in meters): ");
        scanf("%d", &distance_traveled);

        printf("Enter duration (in seconds): ");
        scanf("%d", &duration);

        add_entry(entries, num_entries, name, calories_burned, steps_taken, distance_traveled, duration);

        printf("Do you want to enter another activity? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (tolower(choice) == 'n') {
            break;
        }
    }

    display_entries(entries, num_entries);

    return 0;
}