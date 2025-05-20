//Code Llama-13B DATASET v1.0 Category: Log analysis ; Style: random
/*
 * Log analysis program
 *
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing log data
typedef struct {
    int id;
    char message[100];
    int severity;
} LogEntry;

// Function to read a log file and store its contents in an array
void readLogFile(LogEntry *entries, int *numEntries) {
    FILE *fp;
    char line[100];

    // Open the log file
    fp = fopen("log.txt", "r");
    if (fp == NULL) {
        printf("Error: unable to open log file.\n");
        return;
    }

    // Read the log file line by line and store the data in the array
    int i = 0;
    while (fgets(line, 100, fp) != NULL) {
        // Parse the log entry and store it in the array
        entries[i].id = atoi(strtok(line, " "));
        strcpy(entries[i].message, strtok(NULL, " "));
        entries[i].severity = atoi(strtok(NULL, " "));

        i++;
    }

    // Close the log file
    fclose(fp);

    // Set the number of log entries
    *numEntries = i;
}

// Function to print the log entries
void printLogEntries(LogEntry *entries, int numEntries) {
    printf("Log Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("[%d] %s (%d)\n", entries[i].id, entries[i].message, entries[i].severity);
    }
}

// Function to analyze the log entries
void analyzeLogEntries(LogEntry *entries, int numEntries) {
    // Calculate the total number of log entries
    int totalEntries = 0;
    for (int i = 0; i < numEntries; i++) {
        totalEntries += entries[i].severity;
    }

    // Calculate the average severity level
    float avgSeverity = (float)totalEntries / numEntries;

    // Print the results
    printf("Total number of log entries: %d\n", totalEntries);
    printf("Average severity level: %.2f\n", avgSeverity);
}

int main() {
    // Define an array to store the log entries
    LogEntry entries[100];

    // Read the log file and store its contents in the array
    int numEntries = 0;
    readLogFile(entries, &numEntries);

    // Print the log entries
    printLogEntries(entries, numEntries);

    // Analyze the log entries
    analyzeLogEntries(entries, numEntries);

    return 0;
}