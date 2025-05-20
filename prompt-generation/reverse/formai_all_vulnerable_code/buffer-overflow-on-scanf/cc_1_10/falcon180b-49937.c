//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    char *date;
    char *activity;
    int duration;
};

void add_entry(struct entry *entries, int count, char *date, char *activity, int duration) {
    if (count >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    entries[count].date = strdup(date);
    entries[count].activity = strdup(activity);
    entries[count].duration = duration;
    count++;
}

void print_entries(struct entry entries[], int count) {
    printf("Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("Date: %s\nActivity: %s\nDuration: %d minutes\n", entries[i].date, entries[i].activity, entries[i].duration);
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    char *date = NULL;
    char *activity = NULL;
    int duration = 0;

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);

        printf("Enter activity: ");
        scanf("%s", activity);

        printf("Enter duration (in minutes): ");
        scanf("%d", &duration);

        add_entry(entries, count, date, activity, duration);

        printf("Do you want to add another entry? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    print_entries(entries, count);

    return 0;
}