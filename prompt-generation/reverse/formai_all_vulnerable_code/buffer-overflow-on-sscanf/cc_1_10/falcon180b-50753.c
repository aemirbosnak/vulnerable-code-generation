//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LINES 100000
#define MAX_LINE_LENGTH 2048

typedef struct {
    char ip[16];
    char method[10];
    char url[256];
    char user_agent[512];
    time_t timestamp;
} LogEntry;

int compare_timestamp(const void *a, const void *b) {
    const LogEntry *entry_a = (const LogEntry *)a;
    const LogEntry *entry_b = (const LogEntry *)b;

    if (entry_a->timestamp > entry_b->timestamp) {
        return 1;
    } else if (entry_a->timestamp < entry_b->timestamp) {
        return -1;
    } else {
        return 0;
    }
}

void print_log_entry(const LogEntry *entry) {
    printf("%s - - [%s] \"%s %s %s\" %ld\n", entry->ip, ctime(&entry->timestamp), entry->method, entry->url, entry->user_agent, entry->timestamp);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    LogEntry log_entries[MAX_LOG_LINES];
    int num_entries = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        if (num_entries >= MAX_LOG_LINES) {
            printf("Error: maximum number of log entries reached.\n");
            fclose(log_file);
            return 1;
        }

        LogEntry entry;
        sscanf(line, "%15s %9s %s %511s %ld", entry.ip, entry.method, entry.url, entry.user_agent, &entry.timestamp);
        strcpy(entry.method, toupper(entry.method));

        log_entries[num_entries++] = entry;
    }

    fclose(log_file);

    qsort(log_entries, num_entries, sizeof(LogEntry), compare_timestamp);

    for (int i = 0; i < num_entries; i++) {
        print_log_entry(&log_entries[i]);
    }

    return 0;
}