//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 50

typedef struct {
    char activity[MAX_ENTRY_LENGTH];
    time_t start_time;
    time_t end_time;
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* activity) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached\n");
        return;
    }

    entry_t new_entry;
    strcpy(new_entry.activity, activity);
    time(&new_entry.start_time);
    new_entry.end_time = 0;
    entries[num_entries++] = new_entry;
}

void remove_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Error: Invalid entry index\n");
        return;
    }

    num_entries--;
    for (int i = index; i < num_entries; i++) {
        entries[i] = entries[i+1];
    }
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: ", entries[i].activity);
        if (entries[i].end_time == 0) {
            printf("In progress\n");
        } else {
            printf("Completed in %ld seconds\n", difftime(entries[i].end_time, entries[i].start_time));
        }
    }
}

int main() {
    srand(time(NULL));

    char activity[MAX_ENTRY_LENGTH];
    while (1) {
        printf("Enter an activity (up to %d characters): ", MAX_ENTRY_LENGTH-1);
        scanf("%s", activity);

        add_entry(activity);

        int choice;
        printf("1. Print entries\n2. Remove entry\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_entries();
                break;
            case 2:
                printf("Enter index of entry to remove: ");
                scanf("%d", &choice);
                remove_entry(choice-1);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}