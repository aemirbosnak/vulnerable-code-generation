//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1024

typedef struct {
    char ip[16];
    char date[32];
    char time[32];
    char method[10];
    char path[256];
    int status_code;
} LogEntry;

void read_log_file(const char* filename, LogEntry* entries, int* num_entries) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", filename);
        exit(1);
    }

    char line[MAX_LOG_ENTRY_LENGTH];
    char* token;
    LogEntry entry;
    int count = 0;

    while (fgets(line, MAX_LOG_ENTRY_LENGTH, fp)!= NULL) {
        if (count >= MAX_LOG_ENTRIES) {
            fprintf(stderr, "Reached maximum number of log entries: %d\n", MAX_LOG_ENTRIES);
            break;
        }

        token = strtok(line, " ");
        strcpy(entry.ip, token);

        token = strtok(NULL, " ");
        strcpy(entry.date, token);

        token = strtok(NULL, " ");
        strcpy(entry.time, token);

        token = strtok(NULL, " ");
        strcpy(entry.method, token);

        token = strtok(NULL, " ");
        strcpy(entry.path, token);

        entry.status_code = atoi(strtok(NULL, " "));

        entries[count++] = entry;
    }

    fclose(fp);
    *num_entries = count;
}

void print_log_entries(LogEntry* entries, int num_entries) {
    printf("IP\tDate\tTime\tMethod\tPath\tStatus Code\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%-15s %-10s %-8s %-6s %-20s %d\n", entries[i].ip, entries[i].date, entries[i].time, entries[i].method, entries[i].path, entries[i].status_code);
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    LogEntry entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    read_log_file(argv[1], entries, &num_entries);
    print_log_entries(entries, num_entries);

    return 0;
}