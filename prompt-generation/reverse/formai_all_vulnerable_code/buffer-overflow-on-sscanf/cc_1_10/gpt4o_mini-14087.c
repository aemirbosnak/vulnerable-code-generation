//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "event_log.txt"
#define BUFFER_SIZE 256

typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

const char *logLevelToString(LogLevel level) {
    switch (level) {
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void logEvent(LogLevel level, const char *message) {
    FILE *logFile = fopen(LOG_FILE, "a");
    if (logFile == NULL) {
        perror("Could not open log file");
        return;
    }

    // Get the current time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    // Format the time
    char timeString[20];
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", t);
    
    // Write to the log file
    fprintf(logFile, "[%s] [%s]: %s\n", timeString, logLevelToString(level), message);
    fclose(logFile);
}

void handleUserInput() {
    char input[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    
    printf("Enter log level (INFO, WARNING, ERROR) and message (separated by a space):\n");
    while (fgets(input, sizeof(input), stdin) != NULL) {
        char levelStr[10];
        if (sscanf(input, "%9s %[^\n]", levelStr, message) != 2) {
            printf("Invalid input. Please enter in the format: LEVEL MESSAGE\n");
            continue;
        }

        LogLevel level;
        if (strcmp(levelStr, "INFO") == 0) {
            level = INFO;
        } else if (strcmp(levelStr, "WARNING") == 0) {
            level = WARNING;
        } else if (strcmp(levelStr, "ERROR") == 0) {
            level = ERROR;
        } else {
            printf("Unknown log level: %s. Please use INFO, WARNING, or ERROR.\n", levelStr);
            continue;
        }

        logEvent(level, message);
        printf("Logged: [%s] %s\n", logLevelToString(level), message);
    }
}

int main() {
    printf("Event Logger\n");
    printf("Type the log level followed by your message, or Ctrl+C to exit.\n");
    
    handleUserInput();
    
    return 0;
}