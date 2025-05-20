//Code Llama-13B DATASET v1.0 Category: Log analysis ; Style: satisfied
/*
 * Log Analysis Program
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_ENTRIES 100

typedef struct {
    char ip_address[16];
    char user_agent[128];
    char request_url[128];
    char request_method[16];
    int status_code;
} LogEntry;

void print_log_entry(LogEntry entry) {
    printf("IP address: %s\n", entry.ip_address);
    printf("User agent: %s\n", entry.user_agent);
    printf("Request URL: %s\n", entry.request_url);
    printf("Request method: %s\n", entry.request_method);
    printf("Status code: %d\n", entry.status_code);
}

int main() {
    // Read the log file
    FILE *log_file = fopen("log.txt", "r");
    if (log_file == NULL) {
        printf("Error opening log file\n");
        return 1;
    }

    // Declare an array to store the log entries
    LogEntry log_entries[MAX_LOG_ENTRIES];
    int num_log_entries = 0;

    // Read the log file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), log_file) != NULL) {
        // Parse the log entry from the line
        char *ip_address = strtok(line, " ");
        char *user_agent = strtok(NULL, " ");
        char *request_url = strtok(NULL, " ");
        char *request_method = strtok(NULL, " ");
        char *status_code = strtok(NULL, " ");

        // Create a new log entry
        LogEntry entry;
        strcpy(entry.ip_address, ip_address);
        strcpy(entry.user_agent, user_agent);
        strcpy(entry.request_url, request_url);
        strcpy(entry.request_method, request_method);
        entry.status_code = atoi(status_code);

        // Add the log entry to the array
        log_entries[num_log_entries] = entry;
        num_log_entries++;
    }

    // Print the log entries
    for (int i = 0; i < num_log_entries; i++) {
        print_log_entry(log_entries[i]);
    }

    // Close the log file
    fclose(log_file);

    return 0;
}