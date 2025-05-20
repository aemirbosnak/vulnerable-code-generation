//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRIES_PER_DAY 10
#define MAX_ENTRY_LENGTH 80

// Struct to hold a single fitness entry
typedef struct {
    char date[10];
    char activity[MAX_ENTRY_LENGTH];
    int duration;
} FitnessEntry;

// Struct to hold all fitness entries
typedef struct {
    FitnessEntry entries[MAX_ENTRIES];
    int numEntries;
} FitnessLog;

// Function prototypes
void logEntry(FitnessLog *log);
void displayLog(FitnessLog *log);

int main() {
    FitnessLog log;
    log.numEntries = 0;

    // Initialize the log with some sample data
    log.entries[0].date[0] = '0';
    log.entries[0].date[1] = '1';
    log.entries[0].date[2] = '2';
    log.entries[0].date[3] = '2';
    log.entries[0].date[4] = '2';
    log.entries[0].date[5] = '0';
    log.entries[0].date[6] = '\0';
    log.entries[0].activity[0] = 'R';
    log.entries[0].activity[1] = 'u';
    log.entries[0].activity[2] = 'n';
    log.entries[0].activity[3] = 'n';
    log.entries[0].activity[4] = 'i';
    log.entries[0].activity[5] = 'n';
    log.entries[0].activity[6] = 'g';
    log.entries[0].activity[7] = '\0';
    log.entries[0].duration = 30;

    logEntry(&log);
    displayLog(&log);

    return 0;
}

// Function to add a new entry to the log
void logEntry(FitnessLog *log) {
    if (log->numEntries >= MAX_ENTRIES) {
        printf("Log is full.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(log->entries[log->numEntries].date, 10, "%Y%m%d", tm);

    printf("Enter activity (max %d characters): ", MAX_ENTRY_LENGTH - 1);
    scanf("%s", log->entries[log->numEntries].activity);

    printf("Enter duration (in minutes): ");
    scanf("%d", &log->entries[log->numEntries].duration);

    log->numEntries++;
}

// Function to display the log
void displayLog(FitnessLog *log) {
    if (log->numEntries == 0) {
        printf("Log is empty.\n");
        return;
    }

    printf("Date\tActivity\tDuration (min)\n");
    for (int i = 0; i < log->numEntries; i++) {
        printf("%s\t%s\t%d\n", log->entries[i].date, log->entries[i].activity, log->entries[i].duration);
    }
}