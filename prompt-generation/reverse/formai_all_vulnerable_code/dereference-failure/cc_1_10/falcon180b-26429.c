//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_LINE_LENGTH 256

typedef struct {
    char ip[16];
    char method[10];
    char url[256];
    int response_code;
} log_entry;

int main() {
    FILE *log_file;
    char log_line[MAX_LINE_LENGTH];
    log_entry entries[MAX_LOG_LINES];
    int num_entries = 0;

    // Open the log file
    log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    // Read the log file line by line
    while (fgets(log_line, MAX_LINE_LENGTH, log_file)!= NULL) {
        // Parse the log line
        char *token = strtok(log_line, " ");
        strcpy(entries[num_entries].ip, token);
        token = strtok(NULL, " ");
        strcpy(entries[num_entries].method, token);
        token = strtok(NULL, " ");
        strcpy(entries[num_entries].url, token);
        entries[num_entries].response_code = atoi(strtok(NULL, " "));
        num_entries++;

        // Check if we have reached the maximum number of entries
        if (num_entries == MAX_LOG_LINES) {
            printf("Warning: maximum number of log entries reached.\n");
            break;
        }
    }

    // Close the log file
    fclose(log_file);

    // Print the log entries
    printf("Log Entries:\n");
    printf("-----------------\n");
    printf("IP\tMethod\tURL\tResponse Code\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%-15s %-10s %-30s %d\n", entries[i].ip, entries[i].method, entries[i].url, entries[i].response_code);
    }

    return 0;
}