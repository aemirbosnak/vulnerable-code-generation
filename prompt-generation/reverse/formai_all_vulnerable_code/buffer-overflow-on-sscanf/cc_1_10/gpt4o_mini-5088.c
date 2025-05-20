//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 1000

typedef struct {
    time_t timestamp;
    char level[10];
    char message[MAX_LOG_LINE_LENGTH];
} LogEntry;

// Function Prototypes
void parseLogLine(const char *line, LogEntry *entry);
void printLogEntries(LogEntry *entries, int entryCount);
void filterByLogLevel(LogEntry *entries, int entryCount, const char *level);
void sortLogEntries(LogEntry *entries, int entryCount);
int compareEntries(const void *a, const void *b);
void loadLogFile(const char *filename, LogEntry *entries, int *entryCount);

int main(int argc, char *argv[]) {
    // Validate input arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <logfile> [level]\n", argv[0]);
        return EXIT_FAILURE;
    }

    LogEntry entries[MAX_LOG_ENTRIES];
    int entryCount = 0;

    // Load the log file
    loadLogFile(argv[1], entries, &entryCount);

    // Sort the log entries by timestamp
    sortLogEntries(entries, entryCount);

    // Print the entire log entries
    printf("All Log Entries:\n");
    printLogEntries(entries, entryCount);

    // If a log level is provided, filter and print those entries
    if (argc == 3) {
        printf("\nFiltered Log Entries (Level: %s):\n", argv[2]);
        filterByLogLevel(entries, entryCount, argv[2]);
    }

    return EXIT_SUCCESS;
}

// Function to load log entries from the specified log file
void loadLogFile(const char *filename, LogEntry *entries, int *entryCount) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LOG_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (*entryCount >= MAX_LOG_ENTRIES) {
            fprintf(stderr, "Maximum log entries reached, truncating extra entries.\n");
            break;
        }
        parseLogLine(line, &entries[*entryCount]);
        (*entryCount)++;
    }

    fclose(file);
}

// Function to parse a log line and fill a LogEntry structure
void parseLogLine(const char *line, LogEntry *entry) {
    char timeBuffer[30];

    // Assuming log lines follow the format: [YYYY-MM-DD HH:MM:SS] [LEVEL] message
    sscanf(line, "[%[^]]] [%[^]]] %[^\n]", timeBuffer, entry->level, entry->message);

    // Convert time string to timestamp
    struct tm tm;
    strptime(timeBuffer, "%Y-%m-%d %H:%M:%S", &tm);
    entry->timestamp = mktime(&tm);
}

// Function to print log entries
void printLogEntries(LogEntry *entries, int entryCount) {
    for (int i = 0; i < entryCount; i++) {
        char timeBuffer[30];
        strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", localtime(&entries[i].timestamp));
        printf("[%s] [%s] %s\n", timeBuffer, entries[i].level, entries[i].message);
    }
}

// Function to filter log entries by level
void filterByLogLevel(LogEntry *entries, int entryCount, const char *level) {
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].level, level) == 0) {
            char timeBuffer[30];
            strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", localtime(&entries[i].timestamp));
            printf("[%s] [%s] %s\n", timeBuffer, entries[i].level, entries[i].message);
        }
    }
}

// Function to sort log entries by timestamp
void sortLogEntries(LogEntry *entries, int entryCount) {
    qsort(entries, entryCount, sizeof(LogEntry), compareEntries);
}

// Comparison function for qsort
int compareEntries(const void *a, const void *b) {
    LogEntry *entryA = (LogEntry *)a;
    LogEntry *entryB = (LogEntry *)b;
    return (entryA->timestamp > entryB->timestamp) - (entryA->timestamp < entryB->timestamp);
}