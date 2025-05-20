//FormAI DATASET v1.0 Category: Log analysis ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 10000 // maximum number of log entries to read in
#define MAX_LINE_LENGTH 1024 // maximum length of a single log line

// struct to hold information about a single log entry
typedef struct {
    char date[11]; // date of log entry in format YYYY/MM/DD
    char time[9]; // time of log entry in format HH:MM:SS
    char level[10]; // log level (e.g. ERROR, INFO, WARNING)
    char message[MAX_LINE_LENGTH]; // log message
} LogEntry;

// function to parse a single line of log file and populate a LogEntry struct
void parseLogLine(char *line, LogEntry *entry) {
    char date[11], time[9], level[10], message[MAX_LINE_LENGTH];
    sscanf(line, "%s %s %s %[^\n]", date, time, level, message);
    strcpy(entry->date, date);
    strcpy(entry->time, time);
    strcpy(entry->level, level);
    strcpy(entry->message, message);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file_name>\n", argv[0]);
        return 1;
    }

    char *logFileName = argv[1];

    // open log file in read-only mode
    FILE *logFile = fopen(logFileName, "r");
    if (logFile == NULL) {
        printf("Error opening log file: %s", logFileName);
        return 1;
    }

    LogEntry logEntries[MAX_LOG_ENTRIES];
    int numEntries = 0;

    // read log file one line at a time and populate logEntries array
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, logFile)) {
        LogEntry entry;
        parseLogLine(line, &entry);
        logEntries[numEntries++] = entry;

        if (numEntries >= MAX_LOG_ENTRIES) {
            printf("Maximum log entries exceeded!");
            break;
        }
    }

    // close log file
    fclose(logFile);

    // process log entries according to configuration options
    // these options can be specified on the command line or read from a configuration file

    // example: count number of ERROR entries and output the count to console
    int numErrors = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(logEntries[i].level, "ERROR") == 0) {
            numErrors++;
        }
    }
    printf("Number of ERROR entries in log file: %d\n", numErrors);

    // example: output all log entries that contain a certain keyword
    char *keyword = "memory";
    for (int i = 0; i < numEntries; i++) {
        if (strstr(logEntries[i].message, keyword) != NULL) {
            printf("%s %s %s: %s\n", logEntries[i].date, logEntries[i].time, logEntries[i].level, logEntries[i].message);
        }
    }

    // other configuration options could include filtering by date/time range, outputting to different file formats, etc.

    return 0;
}