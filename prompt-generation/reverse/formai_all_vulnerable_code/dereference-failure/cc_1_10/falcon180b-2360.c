//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 256

typedef struct {
    char ip[16];
    char date[32];
    char time[32];
    char request[MAX_LOG_ENTRY_LENGTH];
} log_entry;

int main() {
    FILE *log_file;
    char log_line[MAX_LOG_ENTRY_LENGTH];
    log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    // Open the log file
    log_file = fopen("example.log", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    // Read the log file
    while (fgets(log_line, MAX_LOG_ENTRY_LENGTH, log_file)!= NULL) {
        // Parse the log line
        char *ip_start = strstr(log_line, " ");
        char *date_start = strstr(log_line, " ") + 1;
        char *time_start = strstr(log_line, " ") + 12;
        char *request_start = strstr(log_line, " ") + 25;

        // Copy the fields to the log entry
        strncpy(log_entries[num_entries].ip, ip_start, 16);
        strncpy(log_entries[num_entries].date, date_start, 32);
        strncpy(log_entries[num_entries].time, time_start, 32);
        strncpy(log_entries[num_entries].request, request_start, MAX_LOG_ENTRY_LENGTH - 1);

        // Increment the number of entries
        num_entries++;

        // Check if we've reached the maximum number of entries
        if (num_entries == MAX_LOG_ENTRIES) {
            break;
        }
    }

    // Close the log file
    fclose(log_file);

    // Print the summary
    printf("Log Summary:\n");
    printf("=============\n");
    printf("Number of entries: %d\n", num_entries);

    // Print the entries
    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d:\n", i + 1);
        printf("IP: %s\n", log_entries[i].ip);
        printf("Date: %s\n", log_entries[i].date);
        printf("Time: %s\n", log_entries[i].time);
        printf("Request: %s\n", log_entries[i].request);
        printf("\n");
    }

    return 0;
}