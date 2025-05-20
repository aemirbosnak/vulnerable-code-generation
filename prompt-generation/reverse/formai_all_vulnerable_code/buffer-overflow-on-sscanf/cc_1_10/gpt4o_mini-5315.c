//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 1000

typedef struct {
    time_t timestamp;
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

void parseLogLine(const char *line, LogEntry *entry) {
    char timeBuffer[20];
    sscanf(line, "%s %s %[^\n]", timeBuffer, entry->level, entry->message);
    struct tm tm;
    strptime(timeBuffer, "%Y-%m-%d %H:%M:%S", &tm);
    entry->timestamp = mktime(&tm);
}

void printLogEntry(const LogEntry *entry) {
    char timeBuffer[20];
    strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", localtime(&entry->timestamp));
    printf("[%s] [%s]: %s\n", timeBuffer, entry->level, entry->message);
}

int loadLogFile(const char *filename, LogEntry *logEntries) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open log file");
        return -1;
    }

    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) && count < MAX_LOG_ENTRIES) {
        parseLogLine(line, &logEntries[count]);
        count++;
    }

    fclose(file);
    return count;
}

void filterLogsByLevel(const LogEntry *logEntries, int count, const char *level) {
    printf("Logs with level [%s]:\n", level);
    for (int i = 0; i < count; i++) {
        if (strcmp(logEntries[i].level, level) == 0) {
            printLogEntry(&logEntries[i]);
        }
    }
}

void filterLogsByTimeRange(const LogEntry *logEntries, int count, time_t start, time_t end) {
    printf("Logs between %s and %s:\n", ctime(&start), ctime(&end));
    for (int i = 0; i < count; i++) {
        if (logEntries[i].timestamp >= start && logEntries[i].timestamp <= end) {
            printLogEntry(&logEntries[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <logfile> [<level> <start_time> <end_time>]\n", argv[0]);
        return EXIT_FAILURE;
    }

    LogEntry logEntries[MAX_LOG_ENTRIES];
    int count = loadLogFile(argv[1], logEntries);
    if (count < 0) {
        return EXIT_FAILURE;
    }

    if (argc > 2) {
        filterLogsByLevel(logEntries, count, argv[2]);
    }

    if (argc > 4) {
        time_t start, end;
        sscanf(argv[3], "%ld", &start);
        sscanf(argv[4], "%ld", &end);
        filterLogsByTimeRange(logEntries, count, start, end);
    }

    return EXIT_SUCCESS;
}