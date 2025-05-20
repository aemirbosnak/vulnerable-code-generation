//FormAI DATASET v1.0 Category: Log analysis ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE_PATH "example.log" // Path of the log file to analyze
#define MAX_LINE_LENGTH 1024 // Maximum length of a line in the log file
#define DATE_FORMAT "%Y-%m-%d %H:%M:%S" // Format of the log timestamp

// Structure to hold information about a log entry
typedef struct {
    time_t time;
    char message[MAX_LINE_LENGTH];
} LogEntry;

// Main function
int main() {
    FILE* logFile = fopen(LOG_FILE_PATH, "r"); // Open the log file for reading
    if (logFile == NULL) {
        printf("Error: could not open file.\n"); // Exit if the file could not be opened
        return 1;
    }

    int numEntries = 0;
    LogEntry entries[MAX_LINE_LENGTH]; // Array to hold the log entries

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, logFile) != NULL) { // Read each line of the file
        char* token = strtok(line, " "); // Split the line by spaces
        
        // Parse the timestamp
        struct tm tm;
        if (strptime(token, DATE_FORMAT, &tm) == NULL) {
            printf("Error: invalid date format.\n"); // Exit if the timestamp is invalid
            return 1;
        }
        time_t time = mktime(&tm);
        
        // Parse the message
        char message[MAX_LINE_LENGTH];
        strcpy(message, "");
        while (token != NULL) {
            strcat(message, token);
            strcat(message, " ");
            token = strtok(NULL, " ");
        }
        strtok(message, "\n"); // Remove the newline character from the end of the message
        
        LogEntry entry = {
            .time = time,
        };
        strcpy(entry.message, message);

        entries[numEntries++] = entry;
    }

    fclose(logFile); // Close the log file

    // Print the number of log entries
    printf("Number of log entries: %d\n", numEntries);

    // Print the earliest and latest timestamps
    time_t earliestTime = entries[0].time;
    time_t latestTime = entries[0].time;    
    for (int i = 1; i < numEntries; i++) {
        if (entries[i].time < earliestTime) {
            earliestTime = entries[i].time;
        }
        if (entries[i].time > latestTime) {
            latestTime = entries[i].time;
        }
    }
    printf("Earliest timestamp: %s", asctime(localtime(&earliestTime)));
    printf("Latest timestamp: %s", asctime(localtime(&latestTime)));

    // Count the number of times each message appeared
    int numMessages = 0;
    char messages[MAX_LINE_LENGTH][MAX_LINE_LENGTH];
    int messageCounts[MAX_LINE_LENGTH];
    memset(messageCounts, 0, sizeof(messageCounts));
    for (int i = 0; i < numEntries; i++) {
        int j;
        for (j = 0; j < numMessages; j++) {
            if (strcmp(entries[i].message, messages[j]) == 0) {
                messageCounts[j]++;
                break;
            }
        }
        if (j == numMessages) {
            strcpy(messages[numMessages], entries[i].message);
            messageCounts[numMessages] = 1;
            numMessages++;
        }
    }

    // Print the number of unique messages and their counts
    printf("Number of unique messages: %d\n", numMessages);
    for (int i = 0; i < numMessages; i++) {
        printf("%d occurrences of: \"%s\"\n", messageCounts[i], messages[i]);
    }

    return 0;
}