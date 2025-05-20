//FormAI DATASET v1.0 Category: Log analysis ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_LINES 1000
#define MAX_LOG_LENGTH 100

// A struct to represent a log line
struct LogLine {
    char date[20];
    char time[20];
    char level[10];
    char message[MAX_LOG_LENGTH];
};

// A function to parse a log line
void parseLogLine(char* logLine, struct LogLine* parsedLogLine) {
    sscanf(logLine, "%s %s %s %[^\n]", parsedLogLine->date, parsedLogLine->time, parsedLogLine->level, parsedLogLine->message);
}

int main() {
    // Open the log file for reading
    FILE* logFile = fopen("example.log", "r");
    if (logFile == NULL) {
        printf("Error: Failed to open the log file!\n");
        return 1;
    }

    // Read the log lines into an array of structs
    struct LogLine logLineArray[MAX_LOG_LINES];
    int numLogLines = 0;
    char currentLogLine[MAX_LOG_LENGTH];
    while (fgets(currentLogLine, MAX_LOG_LENGTH, logFile) != NULL && numLogLines < MAX_LOG_LINES) {
        parseLogLine(currentLogLine, &logLineArray[numLogLines]);
        numLogLines++;
    }

    // Close the log file
    fclose(logFile);

    // Count the number of log lines of each level
    int numDebug = 0;
    int numInfo = 0;
    int numWarn = 0;
    int numError = 0;
    for (int i = 0; i < numLogLines; i++) {
        if (strcmp(logLineArray[i].level, "DEBUG") == 0) {
            numDebug++;
        } else if (strcmp(logLineArray[i].level, "INFO") == 0) {
            numInfo++;
        } else if (strcmp(logLineArray[i].level, "WARN") == 0) {
            numWarn++;
        } else if (strcmp(logLineArray[i].level, "ERROR") == 0) {
            numError++;
        }
    }

    // Calculate the percentage of log lines of each level
    double percentDebug = (double)numDebug / numLogLines * 100;
    double percentInfo = (double)numInfo / numLogLines * 100;
    double percentWarn = (double)numWarn / numLogLines * 100;
    double percentError = (double)numError / numLogLines * 100;

    // Print the summary statistics of the log file
    printf("Total number of log lines: %d\n", numLogLines);
    printf("Number of DEBUG log lines: %d (%.2f%%)\n", numDebug, percentDebug);
    printf("Number of INFO log lines: %d (%.2f%%)\n", numInfo, percentInfo);
    printf("Number of WARN log lines: %d (%.2f%%)\n", numWarn, percentWarn);
    printf("Number of ERROR log lines: %d (%.2f%%)\n", numError, percentError);

    return 0;
}