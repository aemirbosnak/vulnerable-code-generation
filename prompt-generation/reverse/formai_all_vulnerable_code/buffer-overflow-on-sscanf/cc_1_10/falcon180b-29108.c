//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_LINE_LENGTH 1000

typedef struct {
    char ip[16];
    char date[30];
    char time[10];
    char request[100];
    int status_code;
} LogEntry;

void read_log_file(FILE *file, LogEntry entries[], int *num_entries) {
    char line[MAX_LOG_LINE_LENGTH];
    while (fgets(line, MAX_LOG_LINE_LENGTH, file)) {
        if (*num_entries >= MAX_LOG_ENTRIES) {
            printf("Maximum number of log entries reached!\n");
            break;
        }
        LogEntry entry;
        sscanf(line, "%15s %29s %9s \"%99[^\"]\" %d", entry.ip, entry.date, entry.time, entry.request, &entry.status_code);
        strcpy(entries[*num_entries].ip, entry.ip);
        strcpy(entries[*num_entries].date, entry.date);
        strcpy(entries[*num_entries].time, entry.time);
        strcpy(entries[*num_entries].request, entry.request);
        entries[*num_entries].status_code = entry.status_code;
        (*num_entries)++;
    }
}

void print_log_entries(LogEntry entries[], int num_entries) {
    printf("IP\tDate\tTime\tRequest\tStatus Code\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%-15s %-29s %-9s %-99s %d\n", entries[i].ip, entries[i].date, entries[i].time, entries[i].request, entries[i].status_code);
    }
}

int main() {
    FILE *log_file;
    log_file = fopen("example.log", "r");
    if (log_file == NULL) {
        printf("Error opening log file!\n");
        exit(1);
    }

    LogEntry entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    read_log_file(log_file, entries, &num_entries);

    fclose(log_file);

    print_log_entries(entries, num_entries);

    return 0;
}