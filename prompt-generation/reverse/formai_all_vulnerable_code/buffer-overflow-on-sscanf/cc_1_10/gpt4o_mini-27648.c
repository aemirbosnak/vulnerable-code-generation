//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LOG_FILE "server.log"
#define MAX_LINE_LENGTH 256
#define TIMESTAMP_LENGTH 20

void analyzeLogFile(const char *filename);
void extractErrorDetails(const char *line);
void calculateErrorRate(int totalEntries, int errorCount);

int main() {
    analyzeLogFile(LOG_FILE);
    return 0;
}

void analyzeLogFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int totalEntries = 0;
    int errorCount = 0;

    printf("Analyzing log file: %s\n", filename);
    printf("-------------------------------------------------\n");
    printf("%-20s | %s\n", "Timestamp", "Message");
    printf("-------------------------------------------------\n");

    while (fgets(line, sizeof(line), file)) {
        totalEntries++;
        char timestamp[TIMESTAMP_LENGTH];
        char message[MAX_LINE_LENGTH];

        // Parse timestamp and message from the log line
        sscanf(line, "%19s %[^\n]", timestamp, message);
        printf("%-20s | %s\n", timestamp, message);

        // Check if the message indicates an error
        if (strstr(message, "ERROR") != NULL) {
            errorCount++;
            extractErrorDetails(line);
        }
    }

    fclose(file);

    calculateErrorRate(totalEntries, errorCount);
}

void extractErrorDetails(const char *line) {
    // Here we simply print the line for demonstration purposes
    printf("Extracted Error: %s", line);
}

void calculateErrorRate(int totalEntries, int errorCount) {
    if (totalEntries == 0) {
        printf("No log entries found.\n");
        return;
    }

    float errorRate = (float)errorCount / totalEntries * 100;
    printf("-------------------------------------------------\n");
    printf("Total Entries: %d\n", totalEntries);
    printf("Total Errors: %d\n", errorCount);
    printf("Error Rate: %.2f%%\n", errorRate);
}