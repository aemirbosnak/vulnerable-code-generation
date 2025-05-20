//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 50

typedef struct {
    char date[MAX_ENTRY_LENGTH];
    char exercise[MAX_ENTRY_LENGTH];
    int duration;
} FitnessEntry;

void addEntry(FitnessEntry *entries, int count, char *date, char *exercise, int duration) {
    if (count >= MAX_ENTRIES) {
        printf("Cannot add more entries. Maximum limit reached.\n");
        return;
    }

    strncpy(entries[count].date, date, MAX_ENTRY_LENGTH);
    strncpy(entries[count].exercise, exercise, MAX_ENTRY_LENGTH);
    entries[count].duration = duration;
    count++;
}

void displayEntries(FitnessEntry *entries, int count) {
    printf("Fitness Log\n");
    printf("Date        Exercise       Duration\n");

    for (int i = 0; i < count; i++) {
        printf("%s     %s          %d\n", entries[i].date, entries[i].exercise, entries[i].duration);
    }
}

int main() {
    FitnessEntry entries[MAX_ENTRIES];
    int count = 0;
    char date[MAX_ENTRY_LENGTH];
    char exercise[MAX_ENTRY_LENGTH];
    int duration;

    time_t now = time(NULL);
    strftime(date, MAX_ENTRY_LENGTH, "%Y-%m-%d", localtime(&now));

    while (count < MAX_ENTRIES) {
        printf("Enter the date in YYYY-MM-DD format: ");
        scanf("%s", date);

        printf("Enter the exercise: ");
        scanf("%s", exercise);

        printf("Enter the duration in minutes: ");
        scanf("%d", &duration);

        addEntry(entries, count, date, exercise, duration);
    }

    displayEntries(entries, count);

    return 0;
}