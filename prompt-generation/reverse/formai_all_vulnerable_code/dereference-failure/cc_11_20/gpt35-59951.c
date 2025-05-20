//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define some constants */
#define MAX_LOG_ENTRIES 100
#define MAX_LOG_ENTRY_SIZE 256
#define MAX_SUSPICIOUS_ENTRIES 10
#define SUSPICIOUS_LOGIN_THRESHOLD 3
#define SUSPICIOUS_COMMAND_THRESHOLD 10

/* Define structs to hold log data */
struct LogEntry {
    char username[50];
    char timestamp[20];
    char command[100];
};

struct SuspiciousEntry {
    char username[50];
    int numFailedLogins;
    int numSuspiciousCommands;
};

int main() {

    /* Initialize variables */
    char logFilename[] = "systemlog.txt";
    struct LogEntry logEntries[MAX_LOG_ENTRIES];
    struct SuspiciousEntry suspiciousEntries[MAX_SUSPICIOUS_ENTRIES];
    int numEntries = 0;
    int numSuspiciousEntries = 0;

    /* Read log file */
    FILE *logFile = fopen(logFilename, "r");
    if (logFile == NULL){
        printf("Error opening log file\n");
        exit(1);
    }
    char logEntry[MAX_LOG_ENTRY_SIZE];
    while (fgets(logEntry, MAX_LOG_ENTRY_SIZE, logFile) != NULL && numEntries < MAX_LOG_ENTRIES) {
        /* Parse log entry */
        char *token = strtok(logEntry, ",");
        strcpy(logEntries[numEntries].username, token);
        token = strtok(NULL, ",");
        strcpy(logEntries[numEntries].timestamp, token);
        token = strtok(NULL, ",");
        strcpy(logEntries[numEntries].command, token);
        numEntries++;
    }
    fclose(logFile);

    /* Check for suspicious activity */
    for (int i = 0; i < numEntries; i++) {
        int numFailedLogins = 0;
        int numSuspiciousCommands = 0;
        for (int j = 0; j < numEntries; j++) {
            if (strcmp(logEntries[i].username, logEntries[j].username) == 0) {
                /* Check for failed logins */
                if (strstr(logEntries[j].command, "login") != NULL && strstr(logEntries[j].command, "failed") != NULL) {
                    numFailedLogins++;
                }
                /* Check for suspicious commands */
                if (strstr(logEntries[j].command, "rm") != NULL || strstr(logEntries[j].command, "sudo") != NULL || strstr(logEntries[j].command, "wget") != NULL) {
                    numSuspiciousCommands++;
                }
            }
        }
        /* Add suspicious entry to array if thresholds are met */
        if (numFailedLogins >= SUSPICIOUS_LOGIN_THRESHOLD || numSuspiciousCommands >= SUSPICIOUS_COMMAND_THRESHOLD) {
            struct SuspiciousEntry suspiciousEntry;
            strcpy(suspiciousEntry.username, logEntries[i].username);
            suspiciousEntry.numFailedLogins = numFailedLogins;
            suspiciousEntry.numSuspiciousCommands = numSuspiciousCommands;
            suspiciousEntries[numSuspiciousEntries] = suspiciousEntry;
            numSuspiciousEntries++;
        }
    }

    /* Print suspicious activity */
    printf("Suspicious Activity:\n");
    for (int i = 0; i < numSuspiciousEntries; i++) {
        printf("Username: %s\n", suspiciousEntries[i].username);
        printf("  Number of failed logins: %d\n", suspiciousEntries[i].numFailedLogins);
        printf("  Number of suspicious commands: %d\n", suspiciousEntries[i].numSuspiciousCommands);
    }

    return 0;
}