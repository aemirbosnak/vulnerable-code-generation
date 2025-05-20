//FormAI DATASET v1.0 Category: System event logger ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct SystemLogs {
    int logId;
    char logTime[20];
    char logType[20];
    char logDetails[100];
};

void logEvent(struct SystemLogs systemLog) {
    time_t t = time(NULL);
    struct tm* timeptr = localtime(&t);
    char timestamp[20];
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", timeptr);
    strcpy(systemLog.logTime, timestamp);
    printf("Event ID: %d\n", systemLog.logId);
    printf("Event Time: %s\n", systemLog.logTime);
    printf("Event Type: %s\n", systemLog.logType);
    printf("Event Details: %s\n", systemLog.logDetails);
}

int main() {
    int eventCount = 0;
    struct SystemLogs systemLogs[100];
    while (1) {
        printf("\nEnter the Event Type (E for Error, W for Warning, I for Info): ");
        char eventType;
        scanf(" %c", &eventType);
        getchar();
        if (eventType == 'E') {
            systemLogs[eventCount].logId = eventCount + 1;
            strcpy(systemLogs[eventCount].logType, "Error");
            printf("Enter the Error Details: ");
            fgets(systemLogs[eventCount].logDetails, 100, stdin);
            logEvent(systemLogs[eventCount]);
            eventCount++;
        }
        else if (eventType == 'W') {
            systemLogs[eventCount].logId = eventCount + 1;
            strcpy(systemLogs[eventCount].logType, "Warning");
            printf("Enter the Warning Details: ");
            fgets(systemLogs[eventCount].logDetails, 100, stdin);
            logEvent(systemLogs[eventCount]);
            eventCount++;
        }
        else if (eventType == 'I') {
            systemLogs[eventCount].logId = eventCount + 1;
            strcpy(systemLogs[eventCount].logType, "Info");
            printf("Enter the Info Details: ");
            fgets(systemLogs[eventCount].logDetails, 100, stdin);
            logEvent(systemLogs[eventCount]);
            eventCount++;
        }
    }
    return 0;
}