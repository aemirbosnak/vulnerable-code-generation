//Falcon-180B DATASET v1.0 Category: System event logger ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LOG_FILE_SIZE (1024 * 1024 * 10) // 10 MB
#define MAX_LOG_ENTRIES 1000

typedef struct {
    char timestamp[32];
    char message[256];
} LogEntry;

static char logFilePath[256] = {0};
static int logFileSize = 0;
static FILE *logFile = NULL;
static int numLogEntries = 0;

void initLogger(const char *logDir) {
    snprintf(logFilePath, sizeof(logFilePath), "%s/event.log", logDir);
    logFile = fopen(logFilePath, "a+");
    if (logFile == NULL) {
        printf("Error: could not open log file\n");
        exit(1);
    }
    logFileSize = 0;
    numLogEntries = 0;
}

void logMessage(const char *message) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    strftime(logFilePath + strlen(logFilePath) - 32, 32, "%Y%m%d_%H%M%S", localtime(&tv.tv_sec));
    logFileSize += snprintf(logFilePath + strlen(logFilePath), sizeof(logFilePath) - strlen(logFilePath), ".%06d\0", numLogEntries++);
    logFile = fopen(logFilePath, "a+");
    if (logFile == NULL) {
        printf("Error: could not open log file\n");
        exit(1);
    }
    fprintf(logFile, "%s: %s\n", message, logFilePath + strlen(logFilePath) - 32);
    fclose(logFile);
}

void closeLogger() {
    if (logFile!= NULL) {
        fclose(logFile);
    }
}

int main() {
    initLogger("/var/log/myapp");

    for (int i = 0; i < 10; i++) {
        logMessage("This is a test message");
    }

    closeLogger();

    return 0;
}