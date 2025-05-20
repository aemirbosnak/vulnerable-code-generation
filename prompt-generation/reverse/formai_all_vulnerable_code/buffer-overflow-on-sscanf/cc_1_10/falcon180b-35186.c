//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_ENTRIES 10000
#define MAX_LOG_ENTRY_LENGTH 1024

typedef struct {
    char ip[16];
    char date[32];
    char time[32];
    char request[MAX_LOG_ENTRY_LENGTH];
} LogEntry;

int compare_entries(const void *a, const void *b) {
    const LogEntry *entry_a = (const LogEntry *)a;
    const LogEntry *entry_b = (const LogEntry *)b;

    if (strcmp(entry_a->date, entry_b->date) == 0) {
        return strcmp(entry_a->time, entry_b->time);
    } else {
        return strcmp(entry_a->date, entry_b->date);
    }
}

int main() {
    FILE *log_file = fopen("log.txt", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    LogEntry entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    char line[MAX_LOG_ENTRY_LENGTH];
    while (fgets(line, MAX_LOG_ENTRY_LENGTH, log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Maximum number of log entries reached.\n");
            break;
        }

        LogEntry entry;
        sscanf(line, "%15s %31s %31s %s", entry.ip, entry.date, entry.time, entry.request);
        strncpy(entry.date, entry.date + 3, 8); // Remove leading zeros from date
        strncpy(entry.time, entry.time + 3, 8); // Remove leading zeros from time

        entries[num_entries++] = entry;
    }

    qsort(entries, num_entries, sizeof(LogEntry), compare_entries);

    printf("IP Address\tDate\tTime\tRequest\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%15s\t%s\t%s\t%s\n", entries[i].ip, entries[i].date, entries[i].time, entries[i].request);
    }

    fclose(log_file);
    return 0;
}