//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "/var/log/auth.log" // Path to the system log file
#define ALERT_FILE "alert.log"       // Log file for alerts
#define BUFFER_SIZE 256               // Buffer size for reading logs
#define SUSPICIOUS_KEYWORD "failed"   // Keyword for suspicious activity

typedef struct {
    char timestamp[20];
    char username[30];
    char action[50];
} LogEntry;

// Function declarations
void checkLogs(const char *filename);
void logAlert(const LogEntry *entry);

int main() {
    printf("Simple Intrusion Detection System\n");
    printf("Monitoring log file: %s\n", LOG_FILE);
    
    // Check the log file for suspicious activities
    checkLogs(LOG_FILE);
    
    printf("Monitoring complete. Check %s for alerts.\n", ALERT_FILE);
    return 0;
}

void checkLogs(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening log file");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        // Check if the log line contains the suspicious keyword
        if (strstr(buffer, SUSPICIOUS_KEYWORD)) {
            LogEntry entry;
            // Parse the log entry
            sscanf(buffer, "%s %s %s", entry.timestamp, entry.username, entry.action);
            logAlert(&entry);
        }
    }
    
    fclose(file);
}

void logAlert(const LogEntry *entry) {
    FILE *alertFile = fopen(ALERT_FILE, "a");
    if (!alertFile) {
        perror("Error opening alert file");
        return;
    }

    // Log the alert with a timestamp and username
    fprintf(alertFile, "ALERT: Unauthorized access detected!\n");
    fprintf(alertFile, "Timestamp: %s\n", entry->timestamp);
    fprintf(alertFile, "User: %s\n", entry->username);
    fprintf(alertFile, "Action: %s\n\n", entry->action);

    fclose(alertFile);
}