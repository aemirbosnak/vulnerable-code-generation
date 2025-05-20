//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_LINES 1000
#define MAX_LINE_LENGTH 256

struct log_entry {
    char ip[16];
    char date[20];
    char time[10];
    char request[MAX_LINE_LENGTH];
};

int main() {
    FILE *log_file;
    char log_buffer[MAX_LOG_LINES * MAX_LINE_LENGTH];
    int num_entries = 0;
    struct log_entry entries[MAX_LOG_LINES];

    log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    // Read in the entire log file
    fread(log_buffer, sizeof(char), MAX_LOG_LINES * MAX_LINE_LENGTH, log_file);
    fclose(log_file);

    // Parse the log entries
    char *entry_ptr = log_buffer;
    while (num_entries < MAX_LOG_LINES && entry_ptr < log_buffer + MAX_LOG_LINES * MAX_LINE_LENGTH) {
        if (sscanf(entry_ptr, "%15s %19s %8s \"%[^\"]s\"", entries[num_entries].ip, entries[num_entries].date, entries[num_entries].time, entries[num_entries].request) == 4) {
            num_entries++;
            entry_ptr += strlen(entry_ptr);
        } else {
            entry_ptr += strlen(entry_ptr) + 1;
        }
    }

    // Display the log entries
    printf("IP Address | Date and Time | Request\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%-15s | %-19s | %s\n", entries[i].ip, entries[i].date, entries[i].request);
    }

    return 0;
}