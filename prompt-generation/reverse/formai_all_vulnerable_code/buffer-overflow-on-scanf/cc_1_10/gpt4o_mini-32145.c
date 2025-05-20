//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define severity levels
typedef enum {
    INFO,
    WARNING,
    ERROR,
    CRITICAL
} Severity;

// Struct to hold log message
typedef struct {
    time_t timestamp;
    Severity severity;
    char message[256];
} LogEntry;

// Function to get current formatted time
const char* getCurrentTime() {
    static char buffer[26];
    time_t timer;
    time(&timer);
    struct tm* localTime = localtime(&timer);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
    return buffer;
}

// Function to log an event
void logEvent(Severity severity, const char *message) {
    FILE *file = fopen("events.log", "a");
    if (!file) {
        fprintf(stderr, "Could not open log file for writing.\n");
        return;
    }

    LogEntry entry;
    entry.timestamp = time(NULL);
    entry.severity = severity;
    strncpy(entry.message, message, sizeof(entry.message) - 1);

    // Write log entry to file
    fprintf(file, "[%s] [%s]: %s\n", getCurrentTime(),
            (severity == INFO) ? "INFO" :
            (severity == WARNING) ? "WARNING" :
            (severity == ERROR) ? "ERROR" : "CRITICAL",
            entry.message);
    fclose(file);
}

// Function to read and display the log file
void readLogFile() {
    FILE *file = fopen("events.log", "r");
    if (!file) {
        fprintf(stderr, "Could not open log file for reading.\n");
        return;
    }

    char line[512];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// Main function where events are logged
int main() {
    logEvent(INFO, "Application started.");
    
    char userInput[256];

    while (1) {
        printf("Enter a message to log (or type 'exit' to quit): ");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = 0; // Remove newline character

        if (strcmp(userInput, "exit") == 0) {
            logEvent(INFO, "Application is exiting.");
            break;
        }

        int severityChoice;
        printf("Choose severity level (1: INFO, 2: WARNING, 3: ERROR, 4: CRITICAL): ");
        scanf("%d", &severityChoice);
        getchar(); // Clear the newline left by scanf

        if (severityChoice < 1 || severityChoice > 4) {
            printf("Invalid choice! Logging as INFO.\n");
            severityChoice = 1;
        }

        logEvent((Severity)(severityChoice - 1), userInput);
    }

    printf("\nEvent Log:\n");
    readLogFile();

    return 0;
}