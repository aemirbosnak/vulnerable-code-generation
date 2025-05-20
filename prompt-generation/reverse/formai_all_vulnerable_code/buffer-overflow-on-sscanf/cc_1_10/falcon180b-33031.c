//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1024

typedef struct {
    char ip[16];
    char method[8];
    char url[1024];
    int status_code;
    char timestamp[32];
} LogEntry;

int main() {
    FILE *log_file = fopen("logfile.txt", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    LogEntry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    char line[MAX_LOG_ENTRY_LENGTH];
    while (fgets(line, sizeof(line), log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Maximum number of log entries reached.\n");
            break;
        }

        LogEntry *entry = &log_entries[num_entries];
        memset(entry, 0, sizeof(LogEntry));

        sscanf(line, "%15s %7s %1023s %d [%32s]", entry->ip, entry->method, entry->url, &entry->status_code, entry->timestamp);
        num_entries++;
    }

    fclose(log_file);

    printf("Number of log entries: %d\n", num_entries);

    printf("Log entries sorted by IP address:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", log_entries[i].ip);
    }

    printf("\nLog entries sorted by status code:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d: %s\n", log_entries[i].status_code, log_entries[i].url);
    }

    return 0;
}