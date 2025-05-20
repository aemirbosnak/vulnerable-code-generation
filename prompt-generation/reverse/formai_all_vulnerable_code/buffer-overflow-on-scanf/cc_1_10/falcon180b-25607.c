//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char date[10];
    char activity[50];
    int duration;
};

void add_entry(struct entry entries[], int num_entries, char date[], char activity[], int duration) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].activity, activity);
    entries[num_entries].duration = duration;

    num_entries++;
}

void display_entries(struct entry entries[], int num_entries) {
    printf("Fitness Tracker Entries:\n\n");

    for (int i = 0; i < num_entries; i++) {
        printf("Date: %s\nActivity: %s\nDuration: %d minutes\n\n", entries[i].date, entries[i].activity, entries[i].duration);
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        char date[10];
        scanf("%s", date);

        printf("Enter activity: ");
        char activity[50];
        scanf("%s", activity);

        printf("Enter duration (in minutes): ");
        int duration;
        scanf("%d", &duration);

        add_entry(entries, num_entries, date, activity, duration);
    }

    return 0;
}