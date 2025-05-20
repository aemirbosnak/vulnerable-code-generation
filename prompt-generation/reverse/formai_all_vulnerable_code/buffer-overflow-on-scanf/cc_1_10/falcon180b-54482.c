//Falcon-180B DATASET v1.0 Category: System event logger ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FILE "system_events.log"
#define MAX_LOG_SIZE 100000 // 100 KB

typedef struct {
    char event[50];
    time_t timestamp;
} LogEntry;

FILE *logFile = NULL;
int logSize = 0;

void openLogFile() {
    logFile = fopen(LOG_FILE, "a");
    if (logFile == NULL) {
        printf("Error opening log file\n");
        exit(1);
    }
}

void closeLogFile() {
    fclose(logFile);
}

void writeLogEntry(const char *event) {
    if (logSize >= MAX_LOG_SIZE) {
        printf("Log file size limit reached\n");
        return;
    }

    LogEntry entry;
    strncpy(entry.event, event, 49);
    entry.timestamp = time(NULL);

    fwrite(&entry, sizeof(LogEntry), 1, logFile);
    logSize += sizeof(LogEntry);
}

int main() {
    openLogFile();

    while (1) {
        char input[100];
        printf("Enter system event: ");
        scanf("%s", input);

        writeLogEntry(input);

        printf("Event logged: %s\n", input);
    }

    closeLogFile();
    return 0;
}