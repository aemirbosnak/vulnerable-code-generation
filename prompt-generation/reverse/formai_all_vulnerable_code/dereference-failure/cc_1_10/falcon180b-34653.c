//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_LINE_LENGTH 1024

typedef struct {
    char ip[16];
    char method[10];
    char path[256];
    int status_code;
    char date_time[32];
} log_entry_t;

int main() {
    FILE *fp;
    char line[MAX_LOG_LINE_LENGTH];
    char *token;
    log_entry_t entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    // Open the log file
    fp = fopen("access.log", "r");
    if (fp == NULL) {
        printf("Error: Unable to open log file.\n");
        return 1;
    }

    // Read each line of the log file
    while (fgets(line, MAX_LOG_LINE_LENGTH, fp)!= NULL) {
        // Parse the log entry
        token = strtok(line, " ");
        strcpy(entries[num_entries].ip, token);

        token = strtok(NULL, " ");
        strcpy(entries[num_entries].method, token);

        token = strtok(NULL, " ");
        strcpy(entries[num_entries].path, token);

        token = strtok(NULL, " ");
        entries[num_entries].status_code = atoi(token);

        strcpy(entries[num_entries].date_time, line);

        // Increment the number of entries
        num_entries++;

        // Check if we have reached the maximum number of entries
        if (num_entries == MAX_LOG_ENTRIES) {
            break;
        }
    }

    // Close the log file
    fclose(fp);

    // Print the log entries
    printf("Log Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("IP: %s\n", entries[i].ip);
        printf("Method: %s\n", entries[i].method);
        printf("Path: %s\n", entries[i].path);
        printf("Status Code: %d\n", entries[i].status_code);
        printf("Date/Time: %s\n\n", entries[i].date_time);
    }

    return 0;
}