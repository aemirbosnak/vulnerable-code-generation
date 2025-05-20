//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define MAX_IP_SIZE 16
#define MAX_TIME_SIZE 20

typedef struct {
    char ip[MAX_IP_SIZE];
    char time[MAX_TIME_SIZE];
    char message[100];
} LogEntry;

typedef struct {
    LogEntry entries[MAX_LOG_SIZE];
    int size;
} Log;

bool isSuspicious(LogEntry entry) {
    // Logic to determine if a log entry is suspicious goes here.
    // For this example, we'll assume any entry with the message "Access denied"
    // is suspicious.
    return strstr(entry.message, "Access denied") != NULL;
}

void addToLog(Log *log, LogEntry entry) {
    log->entries[log->size++] = entry;
    if (log->size == MAX_LOG_SIZE) {
        printf("Log is full. Writing to file...\n");
        FILE *file = fopen("log.txt", "a");
        if (file != NULL) {
            for (int i = 0; i < MAX_LOG_SIZE; i++) {
                fprintf(file, "%s, %s - %s\n", log->entries[i].ip,
                        log->entries[i].time, log->entries[i].message);
            }
            fclose(file);
            log->size = 0;
        } else {
            printf("Error writing to file.\n");
        }
    }
}

int main() {
    Log log = { .size = 0 };
    printf("Intrusion detection system running.\n");
    while (true) {
        printf("Enter IP address (or 'exit' to quit): ");
        char ip[MAX_IP_SIZE];
        scanf("%s", ip);
        if (strcmp(ip, "exit") == 0) {
            break;
        }
        printf("Enter timestamp (e.g. '2022-08-01 10:31:45'): ");
        char time[MAX_TIME_SIZE];
        scanf("%s", time);
        printf("Enter log message: ");
        char message[100];
        fgets(message, 100, stdin);
        fgets(message, 100, stdin); // To fix scanf newline bug
        LogEntry entry = { .ip = ip, .time = time };
        strncpy(entry.message, message, sizeof(entry.message));
        entry.message[sizeof(entry.message) - 1] = '\0'; // Ensure null-terminator
        if (isSuspicious(entry)) {
            printf("Suspicious log entry detected!\n");
        }
        addToLog(&log, entry);
    }
    printf("Exiting intrusion detection system.\n");
    return 0;
}