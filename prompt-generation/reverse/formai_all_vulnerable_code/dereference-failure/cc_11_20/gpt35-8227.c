//FormAI DATASET v1.0 Category: Log analysis ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 10000

struct LogEntry {
    char timestamp[MAX_LINE_LENGTH];
    char message[MAX_LINE_LENGTH];
};

int main() {
    struct LogEntry log[MAX_NUM_LINES];
    int numLines = 0;

    // read log file into memory
    FILE *file = fopen("example.log", "r");
    if (!file) {
        fprintf(stderr, "Failed to open log file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (numLines >= MAX_NUM_LINES) {
            fprintf(stderr, "Exceeded max number of lines in log.\n");
            exit(1);
        }

        char* timestamp = strtok(line, " ");
        if (!timestamp) {
            fprintf(stderr, "Invalid log entry.\n");
            exit(1);
        }

        char* message = strtok(NULL, "");
        if (!message) {
            fprintf(stderr, "Invalid log entry.\n");
            exit(1);
        }

        strncpy(log[numLines].timestamp, timestamp, MAX_LINE_LENGTH);
        strncpy(log[numLines].message, message, MAX_LINE_LENGTH);

        numLines++;
    }

    fclose(file);
    
    // count number of errors and warnings
    int numErrors = 0;
    int numWarnings = 0;
    for (int i = 0; i < numLines; i++) {
        if (strstr(log[i].message, "ERROR")) {
            numErrors++;
        } else if (strstr(log[i].message, "WARNING")) {
            numWarnings++;
        }
    }

    printf("Number of Errors: %d\n", numErrors);
    printf("Number of Warnings: %d\n", numWarnings);

    // calculate average log entry length
    int totalLength = 0;
    for (int i = 0; i < numLines; i++) {
        totalLength += strlen(log[i].message);
    }
    double avgLength = (double) totalLength / numLines;

    printf("Average Log Entry Length: %f\n", avgLength);

    // find most recent log message
    struct tm lastTimestamp;
    strptime(log[0].timestamp, "%Y-%m-%d %H:%M:%S", &lastTimestamp);
    int mostRecentIndex = 0;
    for (int i = 1; i < numLines; i++) {
        struct tm currentTimestamp;
        strptime(log[i].timestamp, "%Y-%m-%d %H:%M:%S", &currentTimestamp);
        if (difftime(mktime(&currentTimestamp), mktime(&lastTimestamp)) > 0) {
            mostRecentIndex = i;
            lastTimestamp = currentTimestamp;
        }
    }

    printf("Most Recent Log: %s", log[mostRecentIndex].message);

    return 0;
}