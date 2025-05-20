//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 100

typedef struct {
    char name[MAX_ENTRY_LENGTH];
    int year;
    int month;
    int day;
    int duration;
} Entry;

int main() {
    char input[MAX_ENTRY_LENGTH];
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while(1) {
        printf("Enter an exercise (or 'q' to quit): ");
        scanf("%s", input);

        if(strcmp(input, "q") == 0) {
            break;
        }

        strcpy(entries[num_entries].name, input);

        printf("Enter the year (YYYY): ");
        scanf("%d", &entries[num_entries].year);

        printf("Enter the month (1-12): ");
        scanf("%d", &entries[num_entries].month);

        printf("Enter the day (1-31): ");
        scanf("%d", &entries[num_entries].day);

        printf("Enter the duration in minutes: ");
        scanf("%d", &entries[num_entries].duration);

        num_entries++;
    }

    printf("\nFitness Tracker\n");
    printf("================\n");

    for(int i = 0; i < num_entries; i++) {
        printf("%s: %d/%d/%d - %d minutes\n", entries[i].name, entries[i].year, entries[i].month, entries[i].day, entries[i].duration);
    }

    return 0;
}