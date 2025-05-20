//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>

#define LOG_FILE "system.log"
#define MAX_LINE_LENGTH 256
#define SUSPICIOUS_KEYWORD "FAILURE"
#define TIME_THRESHOLD 60 // In seconds

typedef struct {
    char timestamp[20];
    char message[MAX_LINE_LENGTH];
} LogEntry;

void log_activity(const char *logMessage) {
    FILE *logFile = fopen(LOG_FILE, "a");
    if (logFile == NULL) {
        fprintf(stderr, "Could not open log file for writing.\n");
        return;
    }
    char timestamp[20];
    time_t now = time(NULL);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
    fprintf(logFile, "%s: %s\n", timestamp, logMessage);
    fclose(logFile);
}

int is_suspicious(const LogEntry *entry) {
    return strstr(entry->message, SUSPICIOUS_KEYWORD) != NULL;
}

void analyze_log() {
    FILE *logFile = fopen(LOG_FILE, "r");
    if (logFile == NULL) {
        fprintf(stderr, "Could not open log file for reading.\n");
        return;
    }

    LogEntry entry;
    time_t currentTime = time(NULL);
    int suspiciousCount = 0;

    while (fgets(entry.message, sizeof(entry.message), logFile) != NULL) {
        // Extract timestamp from log entries
        sscanf(entry.message, "%[^:]", entry.timestamp);
        struct tm tm;
        strptime(entry.timestamp, "%Y-%m-%d %H:%M:%S", &tm);
        time_t logTime = mktime(&tm);

        // Check if the log entry is suspicious and within time threshold
        if (is_suspicious(&entry) && difftime(currentTime, logTime) < TIME_THRESHOLD) {
            suspiciousCount++;
            printf("Suspicious activity detected: %s", entry.message);
        }
    }

    fclose(logFile);
    if (suspiciousCount > 0) {
        printf("\nTotal suspicious activities in the last %d seconds: %d\n", TIME_THRESHOLD, suspiciousCount);
    } else {
        printf("\nNo suspicious activities detected in the last %d seconds.\n", TIME_THRESHOLD);
    }
}

void monitor_loop() {
    while (1) {
        log_activity("User login failure - Invalid credentials");
        sleep(5); // Simulate delay, actual log generation can vary
        analyze_log();
        sleep(10); // Analyze log every 10 seconds
    }
}

int main() {
    printf("Starting Intrusion Detection System...\n");
    monitor_loop();
    return 0;
}