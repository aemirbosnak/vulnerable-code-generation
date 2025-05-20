//FormAI DATASET v1.0 Category: System event logger ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "system_events.log"
#define MAX_LINE_LENGTH 512

typedef struct {
    char source[64];
    char description[128];
    time_t timestamp;
} SystemEvent;

void logEvent(SystemEvent event);
char* getTimeString(time_t timestamp);

int main() {
    SystemEvent event;
    char input[128];

    printf("Enter source of event: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s", event.source);

    printf("Enter description of event: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s", event.description);

    event.timestamp = time(NULL);
    logEvent(event);

    printf("Event successfully logged!\n");

    return 0;
}

void logEvent(SystemEvent event) {
    FILE* logFile = fopen(LOG_FILE, "a");
    char logLine[MAX_LINE_LENGTH];

    sprintf(logLine, "[%s] %s - %s\n", getTimeString(event.timestamp), event.source, event.description);

    fputs(logLine, logFile);
    fclose(logFile);
}

char* getTimeString(time_t timestamp) {
    struct tm* timeInfo = localtime(&timestamp);
    char* timeString = (char*)malloc(20 * sizeof(char));

    strftime(timeString, 20, "%Y-%m-%d %H:%M:%S", timeInfo);
    return timeString;
}