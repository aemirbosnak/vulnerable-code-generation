//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of logs to analyze
#define MAX_LOGS 100

// Define the maximum length of a log message
#define MAX_LOG_LENGTH 256

// Define the maximum number of words in a log message
#define MAX_WORDS 10

// Define the structure for a log message
typedef struct {
    char message[MAX_LOG_LENGTH];
    int length;
    int words[MAX_WORDS];
} LogMessage;

// Function to split a log message into words
void splitLogMessage(LogMessage* log) {
    char* token = strtok(log->message, " ");
    int count = 0;

    while (token!= NULL && count < MAX_WORDS) {
        log->words[count] = atoi(token);
        count++;
        token = strtok(NULL, " ");
    }

    log->length = count;
}

// Function to analyze the logs and generate statistics
void analyzeLogs(LogMessage logs[], int numLogs) {
    int totalWords = 0;
    int maxWords = 0;
    int minWords = MAX_WORDS;

    for (int i = 0; i < numLogs; i++) {
        totalWords += logs[i].length;

        if (logs[i].length > maxWords) {
            maxWords = logs[i].length;
        }

        if (logs[i].length < minWords) {
            minWords = logs[i].length;
        }
    }

    printf("Total words: %d\n", totalWords);
    printf("Average words per log: %.2f\n", (float)totalWords / numLogs);
    printf("Max words in a log: %d\n", maxWords);
    printf("Min words in a log: %d\n", minWords);
}

// Function to read the logs from a file
int readLogsFromFile(LogMessage logs[], int numLogs, FILE* file) {
    int count = 0;

    while (fscanf(file, "%s", logs[count].message)!= EOF) {
        splitLogMessage(&logs[count]);
        count++;

        if (count >= numLogs) {
            break;
        }
    }

    return count;
}

int main() {
    LogMessage logs[MAX_LOGS];
    int numLogs = 0;

    // Read the logs from the file
    FILE* file = fopen("logs.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    numLogs = readLogsFromFile(logs, MAX_LOGS, file);

    // Analyze the logs
    analyzeLogs(logs, numLogs);

    return 0;
}