//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_WORD_LENGTH 50

typedef struct log_entry {
    char ip_address[20];
    char date_time[20];
    char request_type[10];
    char url[100];
} LogEntry;

int compare_entries(const void *a, const void *b) {
    LogEntry *entry_a = (LogEntry *) a;
    LogEntry *entry_b = (LogEntry *) b;

    int result = strcmp(entry_a->url, entry_b->url);

    if (result == 0) {
        result = strcmp(entry_a->ip_address, entry_b->ip_address);
    }

    return result;
}

int main() {
    FILE *log_file = fopen("log.txt", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    LogEntry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    while (fscanf(log_file, "%s %s %s %s", log_entries[num_entries].ip_address, log_entries[num_entries].date_time, log_entries[num_entries].request_type, log_entries[num_entries].url)!= EOF) {
        num_entries++;

        if (num_entries == MAX_LOG_ENTRIES) {
            printf("Log file is too large. Only processing first %d entries.\n", MAX_LOG_ENTRIES);
            break;
        }
    }

    qsort(log_entries, num_entries, sizeof(LogEntry), compare_entries);

    printf("Sorted log entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s %s %s\n", log_entries[i].ip_address, log_entries[i].date_time, log_entries[i].request_type, log_entries[i].url);
    }

    fclose(log_file);
    return 0;
}