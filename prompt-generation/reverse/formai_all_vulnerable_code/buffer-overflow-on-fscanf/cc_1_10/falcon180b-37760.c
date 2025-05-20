//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 200

// Struct to hold each log entry
typedef struct {
    char message[MAX_LOG_ENTRY_LENGTH];
    int timestamp;
} LogEntry;

// Function to compare two log entries based on their timestamps
int compareLogEntries(const void *a, const void *b) {
    const LogEntry *entryA = (const LogEntry *)a;
    const LogEntry *entryB = (const LogEntry *)b;

    if (entryA->timestamp < entryB->timestamp) {
        return -1;
    } else if (entryA->timestamp > entryB->timestamp) {
        return 1;
    } else {
        return 0;
    }
}

// Function to read log entries from a file and store them in an array
int readLogFile(FILE *file, LogEntry entries[], int maxEntries) {
    int numEntries = 0;

    while (numEntries < maxEntries && fscanf(file, "%s %d\n", entries[numEntries].message, &entries[numEntries].timestamp)!= EOF) {
        numEntries++;
    }

    return numEntries;
}

// Function to write log entries to a file
void writeLogFile(FILE *file, LogEntry entries[], int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%s %d\n", entries[i].message, entries[i].timestamp);
    }
}

// Function to sort log entries by timestamp
void sortLogEntries(LogEntry entries[], int numEntries) {
    qsort(entries, numEntries, sizeof(LogEntry), compareLogEntries);
}

// Function to print log entries in a formatted manner
void printLogEntries(LogEntry entries[], int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printf("%s (%d)\n", entries[i].message, entries[i].timestamp);
    }
}

// Main function to read, sort, and print log entries
int main() {
    // Read log entries from file
    FILE *logFile = fopen("logfile.txt", "r");
    LogEntry entries[MAX_LOG_ENTRIES];
    int numEntries = readLogFile(logFile, entries, MAX_LOG_ENTRIES);

    // Sort log entries by timestamp
    sortLogEntries(entries, numEntries);

    // Print sorted log entries
    printf("Sorted log entries:\n");
    printLogEntries(entries, numEntries);

    // Write sorted log entries to a new file
    FILE *sortedLogFile = fopen("sorted_logfile.txt", "w");
    writeLogFile(sortedLogFile, entries, numEntries);
    fclose(sortedLogFile);

    return 0;
}