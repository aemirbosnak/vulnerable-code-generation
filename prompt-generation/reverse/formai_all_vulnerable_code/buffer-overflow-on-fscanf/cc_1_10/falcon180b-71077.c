//Falcon-180B DATASET v1.0 Category: System event logger ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define LOG_FILE "event_log.txt"

// Log entry structure
typedef struct {
    time_t timestamp;
    char event[100];
} LogEntry;

// Function prototypes
void initLogFile(void);
void logEvent(const char *event);
void printLog(void);

int main(void) {
    initLogFile();

    logEvent("Program started");

    // Your program code here

    logEvent("Program ended");

    printLog();

    return 0;
}

// Initialize the log file
void initLogFile(void) {
    FILE *logFile = fopen(LOG_FILE, "w");

    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    fprintf(logFile, "Timestamp\tEvent\n");
    fclose(logFile);
}

// Log an event
void logEvent(const char *event) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char timestamp[20];

    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);

    FILE *logFile = fopen(LOG_FILE, "a");

    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    fprintf(logFile, "%s\t%s\n", timestamp, event);
    fclose(logFile);
}

// Print the log
void printLog(void) {
    FILE *logFile = fopen(LOG_FILE, "r");

    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    LogEntry logEntries[MAX_LOG_ENTRIES];
    int numEntries = 0;

    while (fscanf(logFile, "%s\t%s", &logEntries[numEntries].timestamp, logEntries[numEntries].event) == 2) {
        numEntries++;

        if (numEntries >= MAX_LOG_ENTRIES) {
            break;
        }
    }

    fclose(logFile);

    printf("Log:\n");
    printf("=====\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%s\t%s\n", ctime(&logEntries[i].timestamp), logEntries[i].event);
    }

    printf("\n");
}