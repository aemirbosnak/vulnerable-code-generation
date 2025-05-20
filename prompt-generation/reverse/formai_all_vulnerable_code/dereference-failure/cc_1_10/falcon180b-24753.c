//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000000
#define MAX_LOG_LINE_SIZE 1024

typedef struct {
    char *ip;
    char *date;
    char *time;
    char *method;
    char *url;
    char *protocol;
    int status_code;
} LogEntry;

int read_log_file(char *filename, LogEntry *entries, int max_entries) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening log file %s\n", filename);
        return -1;
    }
    int num_entries = 0;
    char line[MAX_LOG_LINE_SIZE];
    while (fgets(line, MAX_LOG_LINE_SIZE, file)!= NULL) {
        if (num_entries >= max_entries) {
            printf("Log file is too large, only processing first %d entries\n", max_entries);
            break;
        }
        LogEntry entry;
        entry.ip = strtok(line, " ");
        entry.date = strtok(NULL, " ");
        entry.time = strtok(NULL, " ");
        entry.method = strtok(NULL, " ");
        entry.url = strtok(NULL, " ");
        entry.protocol = strtok(NULL, " ");
        entry.status_code = atoi(strtok(NULL, " "));
        entries[num_entries++] = entry;
    }
    fclose(file);
    return num_entries;
}

void print_log_entry(LogEntry entry) {
    printf("%s - - [%s] \"%s %s %s\" %d - \n", entry.ip, entry.date, entry.time, entry.method, entry.url, entry.status_code);
}

void print_log_entries(LogEntry entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        print_log_entry(entries[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return -1;
    }
    char *filename = argv[1];
    LogEntry entries[MAX_LOG_SIZE];
    int num_entries = read_log_file(filename, entries, MAX_LOG_SIZE);
    if (num_entries <= 0) {
        return -1;
    }
    print_log_entries(entries, num_entries);
    return 0;
}