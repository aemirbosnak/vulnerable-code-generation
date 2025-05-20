//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    char* activity;
    int duration;
    time_t timestamp;
};

void add_entry(struct entry* entries, int count, char* activity, int duration) {
    if (count >= MAX_ENTRIES) {
        printf("Error: Maximum entries reached.\n");
        return;
    }

    entries[count].activity = strdup(activity);
    entries[count].duration = duration;
    entries[count].timestamp = time(NULL);
    count++;
}

void print_entries(struct entry* entries, int count) {
    printf("Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %d minutes - %s\n", entries[i].activity, entries[i].duration, ctime(&entries[i].timestamp));
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    while (1) {
        printf("Enter an activity (or type 'quit' to exit):\n");
        char activity[100];
        scanf("%s", activity);

        if (strcmp(activity, "quit") == 0) {
            break;
        }

        printf("Enter the duration in minutes:\n");
        int duration;
        scanf("%d", &duration);

        add_entry(entries, count, activity, duration);
    }

    print_entries(entries, count);

    return 0;
}