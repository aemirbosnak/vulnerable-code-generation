//FormAI DATASET v1.0 Category: Log analysis ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 200 // Maximum characters that a log line can contain
#define TIMESTAMP_LENGTH 20 // Length of the timestamp field

// Define a structure to hold a log record
typedef struct LogRecord {
    char timestamp[TIMESTAMP_LENGTH];
    char message[MAX_LINE_LENGTH];
} LogRecord;

int main() {
    char filename[100];
    printf("Enter the name of the log file to analyze: ");
    scanf("%s", filename);

    // Open the log file for reading
    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    // Count the number of log records in the file
    int count = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        count++;
    }

    // Allocate memory for the log records array
    LogRecord *records = (LogRecord *)malloc(count * sizeof(LogRecord));

    // Return to the beginning of the file
    fseek(fp, 0, SEEK_SET);

    // Read each line of the file and parse into LogRecord structs
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Extract the timestamp field
        strncpy(records[i].timestamp, line, TIMESTAMP_LENGTH - 1);
        records[i].timestamp[TIMESTAMP_LENGTH - 1] = '\0';

        // Extract the message field
        int message_start = TIMESTAMP_LENGTH + 1;
        int message_length = strlen(line) - message_start - 1;
        strncpy(records[i].message, line + message_start, message_length);
        records[i].message[message_length] = '\0';

        i++;
    }

    fclose(fp);

    // Print the number of log records found
    printf("Found %d log records in %s.\n", count, filename);

    // Print the earliest and latest timestamp
    char earliest_timestamp[TIMESTAMP_LENGTH];
    char latest_timestamp[TIMESTAMP_LENGTH];

    strncpy(earliest_timestamp, records[0].timestamp, TIMESTAMP_LENGTH);
    strncpy(latest_timestamp, records[0].timestamp, TIMESTAMP_LENGTH);

    for (int i = 1; i < count; i++) {
        if (strcmp(records[i].timestamp, earliest_timestamp) < 0) {
            strncpy(earliest_timestamp, records[i].timestamp, TIMESTAMP_LENGTH);
        }

        if (strcmp(records[i].timestamp, latest_timestamp) > 0) {
            strncpy(latest_timestamp, records[i].timestamp, TIMESTAMP_LENGTH);
        }
    }

    printf("Earliest timestamp: %s\n", earliest_timestamp);
    printf("Latest timestamp: %s\n", latest_timestamp);

    // Count the number of log messages with the word "Error" in them
    int error_count = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(records[i].message, "Error") != NULL) {
            error_count++;
        }
    }

    printf("Found %d log messages with the word 'Error' in them.\n", error_count);

    // Free memory allocated for log records
    free(records);

    return 0;
}