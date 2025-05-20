//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1024

typedef struct {
    char ip[16];
    char date[20];
    char time[20];
    char request[1024];
} log_entry;

int compare_log_entries(const void *a, const void *b) {
    const log_entry *entry_a = (const log_entry *)a;
    const log_entry *entry_b = (const log_entry *)b;

    if (strcmp(entry_a->ip, entry_b->ip) == 0) {
        return 0;
    } else if (strcmp(entry_a->ip, entry_b->ip) < 0) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    FILE *log_file;
    char log_buffer[MAX_LOG_ENTRY_LENGTH];
    log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    log_file = fopen("access.log", "r");

    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    while (fgets(log_buffer, MAX_LOG_ENTRY_LENGTH, log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Error: log is full.\n");
            exit(1);
        }

        log_entry entry;
        sscanf(log_buffer, "%15s %19s %19s %[^\r\n]", entry.ip, entry.date, entry.time, entry.request);

        strcpy(entry.ip, toupper(entry.ip));
        strcpy(entry.request, toupper(entry.request));

        log_entries[num_entries++] = entry;
    }

    fclose(log_file);

    qsort(log_entries, num_entries, sizeof(log_entry), compare_log_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("%-15s %-19s %-19s %s\n", log_entries[i].ip, log_entries[i].date, log_entries[i].time, log_entries[i].request);
    }

    return 0;
}