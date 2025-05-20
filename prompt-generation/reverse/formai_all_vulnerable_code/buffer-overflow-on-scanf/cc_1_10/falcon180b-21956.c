//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

struct entry {
    char name[MAX_NAME_LENGTH];
    int calories;
    int steps;
    time_t timestamp;
};

void add_entry(struct entry *entries, int num_entries) {
    printf("Enter your name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter the number of calories burned: ");
    scanf("%d", &entries[num_entries].calories);
    printf("Enter the number of steps taken: ");
    scanf("%d", &entries[num_entries].steps);
    time(&entries[num_entries].timestamp);
    printf("Entry added!\n");
}

void display_entries(struct entry *entries, int num_entries) {
    printf("Name\tCalories\tSteps\tTimestamp\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%d\t%d\t%s", entries[i].name, entries[i].calories, entries[i].steps, ctime(&entries[i].timestamp));
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("\nFitness Tracker\n");
        printf("1. Add entry\n");
        printf("2. Display entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_entries >= MAX_ENTRIES) {
                    printf("Sorry, maximum entries reached!\n");
                } else {
                    add_entry(entries, num_entries);
                    num_entries++;
                }
                break;
            case 2:
                if (num_entries == 0) {
                    printf("No entries found!\n");
                } else {
                    display_entries(entries, num_entries);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}