//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 512

typedef struct {
    char ip[16];
    char date[32];
    char request[MAX_LOG_ENTRY_LENGTH];
} log_entry_t;

int main() {
    FILE *log_file = fopen("logfile.txt", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    log_entry_t log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    char line[MAX_LOG_ENTRY_LENGTH];
    while (fgets(line, MAX_LOG_ENTRY_LENGTH, log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Log file is too large.\n");
            exit(1);
        }

        log_entry_t entry;
        memset(&entry, 0, sizeof(entry));

        sscanf(line, "%15s %31s %[^\n]", entry.ip, entry.date, entry.request);

        strncpy(log_entries[num_entries].ip, entry.ip, sizeof(log_entries[num_entries].ip));
        strncpy(log_entries[num_entries].date, entry.date, sizeof(log_entries[num_entries].date));
        strncpy(log_entries[num_entries].request, entry.request, sizeof(log_entries[num_entries].request));

        num_entries++;
    }

    fclose(log_file);

    printf("Number of entries: %d\n", num_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("IP: %s\n", log_entries[i].ip);
        printf("Date: %s\n", log_entries[i].date);
        printf("Request: %s\n\n", log_entries[i].request);
    }

    return 0;
}