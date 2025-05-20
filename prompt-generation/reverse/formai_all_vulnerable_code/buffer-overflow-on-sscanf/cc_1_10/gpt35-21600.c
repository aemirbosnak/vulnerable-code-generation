//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100

// Definition of a log entry for intrusion detection
typedef struct {
    char date[20];
    char time[20];
    char sourceIP[20];
    char message[100];
} LogEntry;

int main() {
    LogEntry logEntries[MAX_LOG_ENTRIES];
    int currentLogIndex = 0;

    // Code to read log file and store entries in struct array
    FILE* logFile = fopen("intrusion_log.txt", "r");
    if (logFile == NULL) {
        printf("Error: could not open log file\n");
        return 1;
    }

    char buffer[200];
    while (fgets(buffer, sizeof(buffer), logFile)) {
        sscanf(buffer, "%[^','],%[^','],%[^','],%[^\n]s", 
            logEntries[currentLogIndex].date,
            logEntries[currentLogIndex].time,
            logEntries[currentLogIndex].sourceIP,
            logEntries[currentLogIndex].message);
        currentLogIndex++;
    }

    fclose(logFile);

    // Code to analyze log entries for suspicious activity
    int suspiciousCount = 0;
    for (int i = 0; i < currentLogIndex; i++) {
        if (strstr(logEntries[i].message, "unauthorized access")) {
            printf("Suspicious activity detected at %s, %s from %s\n",
                logEntries[i].date, logEntries[i].time, logEntries[i].sourceIP);
            suspiciousCount++;
        }
    }

    if (suspiciousCount == 0) {
        printf("No suspicious activity detected\n");
    } else {
        printf("%d suspicious activity detected\n", suspiciousCount);
    }

    return 0;
}