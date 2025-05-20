//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define MAX_WORD_SIZE 50

typedef struct {
    char ip[20];
    char date_time[30];
    char request_type[20];
    char url[MAX_WORD_SIZE];
    int response_code;
} LogEntry;

int main() {
    FILE *log_file;
    char log_buffer[MAX_LOG_SIZE];
    LogEntry log_entry;
    int num_entries = 0;

    // Open the log file for reading
    log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    // Read the log file line by line
    while (fgets(log_buffer, MAX_LOG_SIZE, log_file)!= NULL) {
        // Parse the log entry
        if (sscanf(log_buffer, "%s %s %s %s %d", log_entry.ip, log_entry.date_time, log_entry.request_type, log_entry.url, &log_entry.response_code) == 5) {
            // Print the log entry
            printf("IP address: %s\n", log_entry.ip);
            printf("Date and time: %s\n", log_entry.date_time);
            printf("Request type: %s\n", log_entry.request_type);
            printf("URL: %s\n", log_entry.url);
            printf("Response code: %d\n\n", log_entry.response_code);
            num_entries++;
        }
    }

    // Close the log file
    fclose(log_file);

    // Print the total number of log entries
    printf("Total number of log entries: %d\n", num_entries);

    return 0;
}