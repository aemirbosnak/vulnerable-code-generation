//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 1000

struct ExerciseEntry {
    int duration;
    int reps;
    int sets;
};

struct WorkoutLog {
    int numEntries;
    struct ExerciseEntry entries[MAX_ENTRIES];
};

void addEntry(struct WorkoutLog *log, struct ExerciseEntry entry) {
    if (log->numEntries >= MAX_ENTRIES) {
        printf("Unable to add entry to log: maximum number of entries reached.\n");
        return;
    }
    log->entries[log->numEntries] = entry;
    log->numEntries++;
}

void printLog(struct WorkoutLog *log) {
    printf("Workout Log:\n");
    for (int i = 0; i < log->numEntries; i++) {
        printf("Entry %d: Duration=%d min, Reps=%d, Sets=%d\n", i+1, log->entries[i].duration, log->entries[i].reps, log->entries[i].sets);
    }
}

int main() {
    struct WorkoutLog myLog = {0};
    printf("Welcome to my cryptic C fitness tracker example program!\n");
    printf("To add an exercise entry, please enter the duration in minutes, reps, and sets separated by spaces:\n");
    while (myLog.numEntries < MAX_ENTRIES) {
        int duration, reps, sets;
        scanf("%d %d %d", &duration, &reps, &sets);
        struct ExerciseEntry entry = {duration, reps, sets};
        addEntry(&myLog, entry);
        printf("Entry added! Please enter another exercise, or type 'c' to print your workout log.\n");
        char c;
        scanf(" %c", &c);
        if (c == 'c') {
            printLog(&myLog);
            printf("Thanks for using my cryptic C fitness tracker example program! Goodbye.\n");
            return 0;
        }
        printf("Enter another exercise:\n");
    }
    printf("Maximum number of entries reached! Your workout log:\n");
    printLog(&myLog);
    printf("Thanks for using my cryptic C fitness tracker example program! Goodbye.\n");
    return 0;
}