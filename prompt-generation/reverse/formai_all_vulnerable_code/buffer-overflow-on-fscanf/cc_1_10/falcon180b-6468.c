//Falcon-180B DATASET v1.0 Category: System event logger ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_SIZE 1000

struct LogEntry {
    time_t timestamp;
    char message[256];
};

int main() {
    FILE *logFile;
    struct LogEntry log[MAX_LOG_SIZE];
    int logSize = 0;
    char *logFilePath = "event.log";

    // Open the log file
    logFile = fopen(logFilePath, "a");
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    // Read existing log entries from the file
    while (fscanf(logFile, "%ld %s\n", &log[logSize].timestamp, log[logSize].message) == 2) {
        logSize++;
        if (logSize >= MAX_LOG_SIZE) {
            break;
        }
    }

    // Log an event
    time_t currentTime = time(NULL);
    strftime(log[logSize].message, sizeof(log[logSize].message), "%Y-%m-%d %H:%M:%S", localtime(&currentTime));
    sprintf(log[logSize].message + strlen(log[logSize].message), " - Event logged.\n");
    log[logSize].timestamp = currentTime;
    logSize++;

    // Write the new log entry to the file
    rewind(logFile);
    for (int i = 0; i < logSize; i++) {
        fprintf(logFile, "%ld %s\n", log[i].timestamp, log[i].message);
    }

    // Close the log file
    fclose(logFile);

    return 0;
}