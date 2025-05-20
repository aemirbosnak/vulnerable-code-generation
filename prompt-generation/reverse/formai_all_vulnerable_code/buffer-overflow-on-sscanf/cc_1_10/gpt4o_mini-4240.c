//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 1000

typedef struct {
    char timestamp[20];
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

void parseLogEntry(char *line, LogEntry *entry) {
    sscanf(line, "%s %s %[^\n]", entry->timestamp, entry->level, entry->message);
}

int isErrorLevel(const char *level) {
    return strcmp(level, "ERROR") == 0;
}

void printLogEntries(LogEntry *entries, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s [%s]: %s\n", entries[i].timestamp, entries[i].level, entries[i].message);
    }
}

void filterLogEntriesByLevel(LogEntry *entries, int count, const char *level) {
    printf("\nFiltered logs for level: %s\n", level);
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].level, level) == 0) {
            printf("%s [%s]: %s\n", entries[i].timestamp, entries[i].level, entries[i].message);
        }
    }
}

void countLogLevels(LogEntry *entries, int count) {
    int infoCount = 0, warningCount = 0, errorCount = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].level, "INFO") == 0) {
            infoCount++;
        } else if (strcmp(entries[i].level, "WARNING") == 0) {
            warningCount++;
        } else if (strcmp(entries[i].level, "ERROR") == 0) {
            errorCount++;
        }
    }

    printf("\nLog Level Counts:\n");
    printf("INFO: %d\n", infoCount);
    printf("WARNING: %d\n", warningCount);
    printf("ERROR: %d\n", errorCount);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return 1;
    }

    LogEntry entries[MAX_LOG_ENTRIES];
    int count = 0;

    while (fgets(entries[count].message, MAX_LINE_LENGTH, file) && count < MAX_LOG_ENTRIES) {
        parseLogEntry(entries[count].message, &entries[count]);
        count++;
    }

    fclose(file);

    printf("Total log entries: %d\n", count);
    printLogEntries(entries, count);
    
    filterLogEntriesByLevel(entries, count, "ERROR");
    
    countLogLevels(entries, count);

    // Additional analysis: find the first occurrence of ERROR
    for (int i = 0; i < count; i++) {
        if (isErrorLevel(entries[i].level)) {
            printf("\nFirst ERROR log found:\n");
            printf("%s [%s]: %s\n", entries[i].timestamp, entries[i].level, entries[i].message);
            break;
        }
    }

    return 0;
}